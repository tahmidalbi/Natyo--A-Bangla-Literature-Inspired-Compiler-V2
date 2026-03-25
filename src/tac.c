#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tac.h"

static int temp_counter = 1;
static int label_counter = 1;

static char* str_dup_local(const char *s) {
    char *out = (char *)malloc(strlen(s) + 1);
    strcpy(out, s);
    return out;
}

static char* new_temp(void) {
    char buf[32];
    snprintf(buf, sizeof(buf), "t%d", temp_counter++);
    return str_dup_local(buf);
}

static char* new_label(void) {
    char buf[32];
    snprintf(buf, sizeof(buf), "L%d", label_counter++);
    return str_dup_local(buf);
}

static const char* op_to_str(OperatorKind op) {
    switch (op) {
        case OP_ADD: return "+";
        case OP_SUB: return "-";
        case OP_MUL: return "*";
        case OP_DIV: return "/";
        case OP_MOD: return "%";
        case OP_GT:  return ">";
        case OP_LT:  return "<";
        case OP_GEQ: return ">=";
        case OP_LEQ: return "<=";
        case OP_EQ:  return "==";
        case OP_NEQ: return "!=";
        case OP_NEG: return "-";
        default:     return "?";
    }
}

static char* gen_expr(FILE *out, ASTExpr *expr);

static void gen_stmt(FILE *out, ASTStmt *stmt);

static void gen_stmt_list(FILE *out, ASTStmt *stmt) {
    while (stmt != NULL) {
        gen_stmt(out, stmt);
        stmt = stmt->next;
    }
}

static char* literal_to_string_int(int value) {
    char buf[64];
    snprintf(buf, sizeof(buf), "%d", value);
    return str_dup_local(buf);
}

static char* literal_to_string_float(double value) {
    char buf[64];
    snprintf(buf, sizeof(buf), "%.6f", value);
    return str_dup_local(buf);
}

static char* literal_to_string_char(char value) {
    char buf[16];
    snprintf(buf, sizeof(buf), "'%c'", value);
    return str_dup_local(buf);
}

static char* literal_to_string_string(const char *value) {
    char *buf = (char *)malloc(strlen(value) + 3);
    sprintf(buf, "\"%s\"", value);
    return buf;
}

static char* gen_expr(FILE *out, ASTExpr *expr) {
    char *left, *right, *temp, *arg_text;
    ASTArgList *arg;
    size_t total_len;

    if (expr == NULL) return str_dup_local("0");

    switch (expr->kind) {
        case EXPR_INT:
            return literal_to_string_int(expr->data.ival);

        case EXPR_FLOAT:
            return literal_to_string_float(expr->data.fval);

        case EXPR_CHAR:
            return literal_to_string_char(expr->data.cval);

        case EXPR_STRING:
            return literal_to_string_string(expr->data.sval);

        case EXPR_IDENTIFIER:
            return str_dup_local(expr->data.sval);

        case EXPR_UNARY:
            left = gen_expr(out, expr->data.unary.operand);
            temp = new_temp();
            fprintf(out, "%s = %s%s\n", temp, op_to_str(expr->data.unary.op), left);
            free(left);
            return temp;

        case EXPR_BINARY:
            left = gen_expr(out, expr->data.binary.left);
            right = gen_expr(out, expr->data.binary.right);
            temp = new_temp();
            fprintf(out, "%s = %s %s %s\n", temp, left, op_to_str(expr->data.binary.op), right);
            free(left);
            free(right);
            return temp;

        case EXPR_BUILTIN_SHAKTI:
            left = gen_expr(out, expr->data.shakti.base);
            right = gen_expr(out, expr->data.shakti.power);
            temp = new_temp();
            fprintf(out, "%s = shakti(%s, %s)\n", temp, left, right);
            free(left);
            free(right);
            return temp;

        case EXPR_BUILTIN_BORGOMUL:
            left = gen_expr(out, expr->data.borgomul.value);
            temp = new_temp();
            fprintf(out, "%s = borgomul(%s)\n", temp, left);
            free(left);
            return temp;

        case EXPR_CALL:
            total_len = strlen(expr->data.call.name) + 16;
            arg = expr->data.call.args;
            arg_text = str_dup_local("");

            while (arg != NULL) {
                char *arg_val = gen_expr(out, arg->expr);
                char *new_text;
                total_len += strlen(arg_val) + 2;
                new_text = (char *)malloc(strlen(arg_text) + strlen(arg_val) + 3);
                if (strlen(arg_text) == 0) {
                    sprintf(new_text, "%s", arg_val);
                } else {
                    sprintf(new_text, "%s, %s", arg_text, arg_val);
                }
                free(arg_text);
                free(arg_val);
                arg_text = new_text;
                arg = arg->next;
            }

            temp = new_temp();
            fprintf(out, "%s = call %s(%s)\n", temp, expr->data.call.name, arg_text);
            free(arg_text);
            return temp;
    }

    return str_dup_local("0");
}

static void gen_stmt(FILE *out, ASTStmt *stmt) {
    char *v, *ltrue, *lfalse, *lend, *lstart;
    if (stmt == NULL) return;

    switch (stmt->kind) {
        case STMT_DECL:
            if (stmt->data.decl.has_init) {
                if (stmt->data.decl.decl_type == TYPE_STRING) {
                    fprintf(out, "%s = \"%s\"\n",
                            stmt->data.decl.name,
                            stmt->data.decl.init_string);
                } else if (stmt->data.decl.decl_type == TYPE_CHAR) {
                    fprintf(out, "%s = '%c'\n",
                            stmt->data.decl.name,
                            stmt->data.decl.init_char);
                } else {
                    v = gen_expr(out, stmt->data.decl.init_expr);
                    fprintf(out, "%s = %s\n", stmt->data.decl.name, v);
                    free(v);
                }
            } else {
                fprintf(out, "declare %s\n", stmt->data.decl.name);
            }
            break;

        case STMT_ASSIGN:
            if (stmt->data.assign.assign_kind == TYPE_STRING) {
                fprintf(out, "%s = \"%s\"\n",
                        stmt->data.assign.name,
                        stmt->data.assign.string_value);
            } else if (stmt->data.assign.assign_kind == TYPE_CHAR) {
                fprintf(out, "%s = '%c'\n",
                        stmt->data.assign.name,
                        stmt->data.assign.char_value);
            } else {
                v = gen_expr(out, stmt->data.assign.value_expr);
                fprintf(out, "%s = %s\n", stmt->data.assign.name, v);
                free(v);
            }
            break;

        case STMT_PRINT:
            if (stmt->data.print_stmt.print_kind == TYPE_STRING) {
                fprintf(out, "print \"%s\"\n", stmt->data.print_stmt.string_literal);
            } else if (stmt->data.print_stmt.print_kind == TYPE_CHAR) {
                fprintf(out, "print '%c'\n", stmt->data.print_stmt.char_literal);
            } else {
                v = gen_expr(out, stmt->data.print_stmt.expr);
                fprintf(out, "print %s\n", v);
                free(v);
            }
            break;

        case STMT_INPUT:
            fprintf(out, "input %s\n", stmt->data.input_stmt.name);
            break;

        case STMT_IF:
            v = gen_expr(out, stmt->data.if_stmt.condition);
            ltrue = new_label();
            lfalse = new_label();
            lend = new_label();

            fprintf(out, "if %s goto %s\n", v, ltrue);
            fprintf(out, "goto %s\n", lfalse);
            fprintf(out, "%s:\n", ltrue);
            gen_stmt(out, stmt->data.if_stmt.then_branch);
            fprintf(out, "goto %s\n", lend);
            fprintf(out, "%s:\n", lfalse);
            if (stmt->data.if_stmt.else_branch != NULL) {
                gen_stmt(out, stmt->data.if_stmt.else_branch);
            }
            fprintf(out, "%s:\n", lend);

            free(v);
            free(ltrue);
            free(lfalse);
            free(lend);
            break;

        case STMT_LOOP:
            lstart = new_label();
            lend = new_label();

            gen_stmt(out, stmt->data.loop_stmt.init_assign);
            fprintf(out, "%s:\n", lstart);
            v = gen_expr(out, stmt->data.loop_stmt.condition);
            fprintf(out, "ifFalse %s goto %s\n", v, lend);
            free(v);
            gen_stmt(out, stmt->data.loop_stmt.body);
            gen_stmt(out, stmt->data.loop_stmt.update_assign);
            fprintf(out, "goto %s\n", lstart);
            fprintf(out, "%s:\n", lend);

            free(lstart);
            free(lend);
            break;

        case STMT_BLOCK:
            gen_stmt_list(out, stmt->data.block_stmt.statements);
            break;

        case STMT_RETURN:
            if (stmt->data.return_stmt.return_kind == TYPE_STRING) {
                fprintf(out, "return \"%s\"\n", stmt->data.return_stmt.string_literal);
            } else if (stmt->data.return_stmt.return_kind == TYPE_CHAR) {
                fprintf(out, "return '%c'\n", stmt->data.return_stmt.char_literal);
            } else {
                v = gen_expr(out, stmt->data.return_stmt.expr);
                fprintf(out, "return %s\n", v);
                free(v);
            }
            break;

        case STMT_EXPR:
            v = gen_expr(out, stmt->data.expr_stmt.expr);
            fprintf(out, "eval %s\n", v);
            free(v);
            break;
    }
}

void generate_tac(ASTTopLevel *program, const char *output_path) {
    FILE *out = fopen(output_path, "w");
    ASTTopLevel *cur = program;

    if (out == NULL) {
        fprintf(stderr, "Could not open TAC output file: %s\n", output_path);
        return;
    }

    temp_counter = 1;
    label_counter = 1;

    fprintf(out, "----- THREE ADDRESS CODE (TAC) -----\n");

    while (cur != NULL) {
        if (cur->kind == TOP_FUNC) {
            fprintf(out, "\nfunc %s:\n", cur->data.func.name);
            gen_stmt(out, cur->data.func.body);
            fprintf(out, "endfunc\n");
        } else {
            gen_stmt(out, cur->data.stmt);
        }
        cur = cur->next;
    }

    fclose(out);
}