#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "interpreter.h"
#include "utils.h"

static RuntimeValue make_unknown_value(void) {
    RuntimeValue v;
    v.type = TYPE_UNKNOWN;
    v.num_val = 0.0;
    v.str_val = NULL;
    v.char_val = '\0';
    return v;
}

static RuntimeValue make_numeric_value(DataType t, double n) {
    RuntimeValue v;
    v.type = t;
    v.num_val = n;
    v.str_val = NULL;
    v.char_val = '\0';
    return v;
}

static RuntimeValue make_string_value(const char *s) {
    RuntimeValue v;
    v.type = TYPE_STRING;
    v.num_val = 0.0;
    v.str_val = strdup(s);
    v.char_val = '\0';
    return v;
}

static RuntimeValue make_char_value(char c) {
    RuntimeValue v;
    v.type = TYPE_CHAR;
    v.num_val = 0.0;
    v.str_val = NULL;
    v.char_val = c;
    return v;
}

static void free_runtime_value(RuntimeValue *v) {
    if (v->type == TYPE_STRING && v->str_val != NULL) {
        free(v->str_val);
        v->str_val = NULL;
    }
}

static RuntimeValue clone_runtime_value(const RuntimeValue *src) {
    RuntimeValue v;
    v.type = src->type;
    v.num_val = src->num_val;
    v.char_val = src->char_val;
    v.str_val = NULL;
    if (src->type == TYPE_STRING && src->str_val != NULL) {
        v.str_val = strdup(src->str_val);
    }
    return v;
}

static int truthy(RuntimeValue v) {
    if (v.type == TYPE_STRING) return (v.str_val != NULL && v.str_val[0] != '\0');
    if (v.type == TYPE_CHAR) return (v.char_val != '\0');
    return (fabs(v.num_val) > 1e-12);
}

static RuntimeValue eval_expr(ASTExpr *expr);
static ExecResult exec_stmt(ASTStmt *stmt);

static RuntimeValue call_user_function(Symbol *f, ASTArgList *args) {
    RuntimeValue evaluated_args[MAX_PARAMS];
    int i = 0;
    ASTArgList *cur = args;
    ExecResult res;
    RuntimeValue ret = make_unknown_value();

    while (cur != NULL && i < MAX_PARAMS) {
        evaluated_args[i++] = eval_expr(cur->expr);
        cur = cur->next;
    }

    enter_scope();

    for (i = 0; i < f->param_count; i++) {
        declare_variable(f->param_names[i], f->param_types[i], SYM_PARAM);
        {
            Symbol *p = lookup_symbol_current_scope(f->param_names[i]);
            if (p != NULL) {
                if (evaluated_args[i].type == TYPE_STRING) {
                    set_symbol_string(p, evaluated_args[i].str_val);
                } else if (evaluated_args[i].type == TYPE_CHAR) {
                    set_symbol_char(p, evaluated_args[i].char_val);
                } else {
                    set_symbol_numeric(p, evaluated_args[i].num_val);
                }
            }
        }
    }

    res = exec_stmt(f->function_body);
    if (res.has_return) {
        ret = clone_runtime_value(&res.value);
        free_runtime_value(&res.value);
    }

    exit_scope();

    for (i = 0; i < f->param_count; i++) {
        free_runtime_value(&evaluated_args[i]);
    }

    return ret;
}

static RuntimeValue eval_expr(ASTExpr *expr) {
    RuntimeValue left, right, out;
    Symbol *s;
    RuntimeValue a1, a2;
    ASTArgList *args;

    if (expr == NULL) return make_unknown_value();

    switch (expr->kind) {
        case EXPR_INT:
            return make_numeric_value(TYPE_INT, expr->data.ival);

        case EXPR_FLOAT:
            return make_numeric_value(TYPE_FLOAT, expr->data.fval);

        case EXPR_CHAR:
            return make_char_value(expr->data.cval);

        case EXPR_STRING:
            return make_string_value(expr->data.sval);

        case EXPR_IDENTIFIER:
            s = lookup_symbol(expr->data.sval);
            if (s == NULL) return make_unknown_value();
            return clone_runtime_value(&s->value);

        case EXPR_UNARY:
            out = eval_expr(expr->data.unary.operand);
            if (expr->data.unary.op == OP_NEG) {
                out.num_val = -out.num_val;
            }
            return out;

        case EXPR_BINARY:
            left = eval_expr(expr->data.binary.left);
            right = eval_expr(expr->data.binary.right);
            out = make_unknown_value();

            switch (expr->data.binary.op) {
                case OP_ADD:
                    out = make_numeric_value(arithmetic_result_type(left.type, right.type), left.num_val + right.num_val);
                    break;
                case OP_SUB:
                    out = make_numeric_value(arithmetic_result_type(left.type, right.type), left.num_val - right.num_val);
                    break;
                case OP_MUL:
                    out = make_numeric_value(arithmetic_result_type(left.type, right.type), left.num_val * right.num_val);
                    break;
                case OP_DIV:
                    out = make_numeric_value(TYPE_FLOAT, left.num_val / right.num_val);
                    break;
                case OP_MOD:
                    out = make_numeric_value(TYPE_INT, (int)left.num_val % (int)right.num_val);
                    break;
                case OP_GT:
                    out = make_numeric_value(TYPE_INT, left.num_val > right.num_val);
                    break;
                case OP_LT:
                    out = make_numeric_value(TYPE_INT, left.num_val < right.num_val);
                    break;
                case OP_GEQ:
                    out = make_numeric_value(TYPE_INT, left.num_val >= right.num_val);
                    break;
                case OP_LEQ:
                    out = make_numeric_value(TYPE_INT, left.num_val <= right.num_val);
                    break;
                case OP_EQ:
                    out = make_numeric_value(TYPE_INT, fabs(left.num_val - right.num_val) < 1e-12);
                    break;
                case OP_NEQ:
                    out = make_numeric_value(TYPE_INT, fabs(left.num_val - right.num_val) >= 1e-12);
                    break;
                default:
                    break;
            }

            free_runtime_value(&left);
            free_runtime_value(&right);
            return out;

        case EXPR_BUILTIN_SHAKTI:
            a1 = eval_expr(expr->data.shakti.base);
            a2 = eval_expr(expr->data.shakti.power);
            out = make_numeric_value(TYPE_FLOAT, pow(a1.num_val, a2.num_val));
            free_runtime_value(&a1);
            free_runtime_value(&a2);
            return out;

        case EXPR_BUILTIN_BORGOMUL:
            a1 = eval_expr(expr->data.borgomul.value);
            out = make_numeric_value(TYPE_FLOAT, sqrt(a1.num_val));
            free_runtime_value(&a1);
            return out;

        case EXPR_CALL:
            s = lookup_function(expr->data.call.name);
            if (s == NULL || s->function_body == NULL) {
                return make_unknown_value();
            }
            args = expr->data.call.args;
            return call_user_function(s, args);
    }

    return make_unknown_value();
}

static ExecResult make_exec_result(int has_return, RuntimeValue value) {
    ExecResult r;
    r.has_return = has_return;
    r.value = value;
    return r;
}

static ExecResult exec_stmt_list(ASTStmt *stmt) {
    ExecResult r = make_exec_result(0, make_unknown_value());

    while (stmt != NULL) {
        r = exec_stmt(stmt);
        if (r.has_return) return r;
        stmt = stmt->next;
    }

    return r;
}

static ExecResult exec_stmt(ASTStmt *stmt) {
    RuntimeValue v;
    Symbol *s;
    char input_buf[1024];
    ExecResult r;

    if (stmt == NULL) return make_exec_result(0, make_unknown_value());

    switch (stmt->kind) {
        case STMT_DECL:
            declare_variable(stmt->data.decl.name, stmt->data.decl.decl_type, SYM_VAR);
            s = lookup_symbol_current_scope(stmt->data.decl.name);
            if (s != NULL && stmt->data.decl.has_init) {
                if (stmt->data.decl.decl_type == TYPE_STRING) {
                    set_symbol_string(s, stmt->data.decl.init_string);
                    log_string_update(s->name, s->value.str_val);
                } else if (stmt->data.decl.decl_type == TYPE_CHAR) {
                    set_symbol_char(s, stmt->data.decl.init_char);
                    log_char_update(s->name, s->value.char_val);
                } else {
                    v = eval_expr(stmt->data.decl.init_expr);
                    set_symbol_numeric(s, v.num_val);
                    log_numeric_update(s->name, s->value.num_val);
                    free_runtime_value(&v);
                }
            }
            return make_exec_result(0, make_unknown_value());

        case STMT_ASSIGN:
            s = lookup_symbol(stmt->data.assign.name);
            if (s != NULL) {
                if (stmt->data.assign.assign_kind == TYPE_STRING) {
                    set_symbol_string(s, stmt->data.assign.string_value);
                    log_string_update(s->name, s->value.str_val);
                } else if (stmt->data.assign.assign_kind == TYPE_CHAR) {
                    set_symbol_char(s, stmt->data.assign.char_value);
                    log_char_update(s->name, s->value.char_val);
                } else {
                    v = eval_expr(stmt->data.assign.value_expr);
                    set_symbol_numeric(s, v.num_val);
                    log_numeric_update(s->name, s->value.num_val);
                    free_runtime_value(&v);
                }
            }
            return make_exec_result(0, make_unknown_value());

        case STMT_PRINT:
            if (stmt->data.print_stmt.print_kind == TYPE_STRING) {
                printf("%s\n", stmt->data.print_stmt.string_literal);
            } else if (stmt->data.print_stmt.print_kind == TYPE_CHAR) {
                printf("%c\n", stmt->data.print_stmt.char_literal);
            } else {
                v = eval_expr(stmt->data.print_stmt.expr);
                if (v.type == TYPE_INT) {
                    printf("%d\n", (int)v.num_val);
                } else if (v.type == TYPE_FLOAT) {
                    printf("%.6f\n", v.num_val);
                } else if (v.type == TYPE_STRING && v.str_val != NULL) {
                    printf("%s\n", v.str_val);
                } else if (v.type == TYPE_CHAR) {
                    printf("%c\n", v.char_val);
                }
                free_runtime_value(&v);
            }
            return make_exec_result(0, make_unknown_value());

        case STMT_INPUT:
            s = lookup_symbol(stmt->data.input_stmt.name);
            if (s != NULL) {
                if (s->type == TYPE_INT) {
                    scanf("%d", (int *)&s->value.num_val);
                } else if (s->type == TYPE_FLOAT) {
                    scanf("%lf", &s->value.num_val);
                } else if (s->type == TYPE_STRING) {
                    scanf("%1023s", input_buf);
                    set_symbol_string(s, input_buf);
                } else if (s->type == TYPE_CHAR) {
                    scanf(" %c", &s->value.char_val);
                }
            }
            return make_exec_result(0, make_unknown_value());

        case STMT_IF:
            v = eval_expr(stmt->data.if_stmt.condition);
            if (truthy(v)) {
                free_runtime_value(&v);
                return exec_stmt(stmt->data.if_stmt.then_branch);
            } else if (stmt->data.if_stmt.else_branch != NULL) {
                free_runtime_value(&v);
                return exec_stmt(stmt->data.if_stmt.else_branch);
            }
            free_runtime_value(&v);
            return make_exec_result(0, make_unknown_value());

        case STMT_LOOP:
            exec_stmt(stmt->data.loop_stmt.init_assign);
            while (1) {
                v = eval_expr(stmt->data.loop_stmt.condition);
                if (!truthy(v)) {
                    free_runtime_value(&v);
                    break;
                }
                free_runtime_value(&v);
                r = exec_stmt(stmt->data.loop_stmt.body);
                if (r.has_return) return r;
                exec_stmt(stmt->data.loop_stmt.update_assign);
            }
            return make_exec_result(0, make_unknown_value());

        case STMT_BLOCK:
            enter_scope();
            r = exec_stmt_list(stmt->data.block_stmt.statements);
            exit_scope();
            return r;

        case STMT_RETURN:
            if (stmt->data.return_stmt.return_kind == TYPE_STRING) {
                return make_exec_result(1, make_string_value(stmt->data.return_stmt.string_literal));
            } else if (stmt->data.return_stmt.return_kind == TYPE_CHAR) {
                return make_exec_result(1, make_char_value(stmt->data.return_stmt.char_literal));
            } else {
                v = eval_expr(stmt->data.return_stmt.expr);
                return make_exec_result(1, v);
            }

        case STMT_EXPR:
            v = eval_expr(stmt->data.expr_stmt.expr);
            free_runtime_value(&v);
            return make_exec_result(0, make_unknown_value());
    }

    return make_exec_result(0, make_unknown_value());
}

void interpret_program(ASTTopLevel *program) {
    ASTTopLevel *cur = program;

    while (cur != NULL) {
        if (cur->kind == TOP_STMT) {
            exec_stmt(cur->data.stmt);
        }
        cur = cur->next;
    }
}