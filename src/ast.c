#include <stdlib.h>
#include <string.h>
#include "ast.h"

static ASTExpr* alloc_expr(ExprKind kind) {
    ASTExpr *e = (ASTExpr *)malloc(sizeof(ASTExpr));
    e->kind = kind;
    e->inferred_type = TYPE_UNKNOWN;
    return e;
}

static ASTStmt* alloc_stmt(StmtKind kind) {
    ASTStmt *s = (ASTStmt *)malloc(sizeof(ASTStmt));
    s->kind = kind;
    s->next = NULL;
    return s;
}

static ASTTopLevel* alloc_top(TopLevelKind kind) {
    ASTTopLevel *t = (ASTTopLevel *)malloc(sizeof(ASTTopLevel));
    t->kind = kind;
    t->next = NULL;
    return t;
}

ASTExpr* make_int_expr(int value) {
    ASTExpr *e = alloc_expr(EXPR_INT);
    e->data.ival = value;
    e->inferred_type = TYPE_INT;
    return e;
}

ASTExpr* make_float_expr(double value) {
    ASTExpr *e = alloc_expr(EXPR_FLOAT);
    e->data.fval = value;
    e->inferred_type = TYPE_FLOAT;
    return e;
}

ASTExpr* make_char_expr(char value) {
    ASTExpr *e = alloc_expr(EXPR_CHAR);
    e->data.cval = value;
    e->inferred_type = TYPE_CHAR;
    return e;
}

ASTExpr* make_string_expr(char *value) {
    ASTExpr *e = alloc_expr(EXPR_STRING);
    e->data.sval = value;
    e->inferred_type = TYPE_STRING;
    return e;
}

ASTExpr* make_identifier_expr(char *name) {
    ASTExpr *e = alloc_expr(EXPR_IDENTIFIER);
    e->data.sval = name;
    return e;
}

ASTExpr* make_array_access_expr(char *name, ASTExpr *index_expr) {
    ASTExpr *e = alloc_expr(EXPR_ARRAY_ACCESS);
    e->data.array_access.name = name;
    e->data.array_access.index_expr = index_expr;
    return e;
}

ASTExpr* make_binary_expr(OperatorKind op, ASTExpr *left, ASTExpr *right) {
    ASTExpr *e = alloc_expr(EXPR_BINARY);
    e->data.binary.op = op;
    e->data.binary.left = left;
    e->data.binary.right = right;
    return e;
}

ASTExpr* make_unary_expr(OperatorKind op, ASTExpr *operand) {
    ASTExpr *e = alloc_expr(EXPR_UNARY);
    e->data.unary.op = op;
    e->data.unary.operand = operand;
    return e;
}

ASTExpr* make_call_expr(char *name, ASTArgList *args) {
    ASTExpr *e = alloc_expr(EXPR_CALL);
    e->data.call.name = name;
    e->data.call.args = args;
    return e;
}

ASTExpr* make_shakti_expr(ASTExpr *base, ASTExpr *power) {
    ASTExpr *e = alloc_expr(EXPR_BUILTIN_SHAKTI);
    e->data.shakti.base = base;
    e->data.shakti.power = power;
    return e;
}

ASTExpr* make_borgomul_expr(ASTExpr *value) {
    ASTExpr *e = alloc_expr(EXPR_BUILTIN_BORGOMUL);
    e->data.borgomul.value = value;
    return e;
}

ASTArgList* make_arg_list(ASTExpr *expr) {
    ASTArgList *a = (ASTArgList *)malloc(sizeof(ASTArgList));
    a->expr = expr;
    a->next = NULL;
    return a;
}

ASTArgList* append_arg(ASTArgList *list, ASTExpr *expr) {
    ASTArgList *node;
    ASTArgList *cur;

    if (list == NULL) return make_arg_list(expr);

    node = make_arg_list(expr);
    cur = list;
    while (cur->next != NULL) cur = cur->next;
    cur->next = node;
    return list;
}

ASTIdentifierList* make_identifier_list(char *name) {
    ASTIdentifierList *n = (ASTIdentifierList *)malloc(sizeof(ASTIdentifierList));
    n->name = name;
    n->next = NULL;
    return n;
}

ASTIdentifierList* append_identifier(ASTIdentifierList *list, char *name) {
    ASTIdentifierList *node;
    ASTIdentifierList *cur;

    if (list == NULL) return make_identifier_list(name);

    node = make_identifier_list(name);
    cur = list;
    while (cur->next != NULL) cur = cur->next;
    cur->next = node;
    return list;
}

ASTStmt* make_decl_stmt(DataType decl_type, char *name, ASTExpr *init_expr) {
    ASTStmt *s = alloc_stmt(STMT_DECL);
    s->data.decl.decl_type = decl_type;
    s->data.decl.name = name;
    s->data.decl.init_expr = init_expr;
    s->data.decl.init_string = NULL;
    s->data.decl.init_char = '\0';
    s->data.decl.has_init = (init_expr != NULL);
    s->data.decl.is_array = 0;
    s->data.decl.array_size = 0;
    return s;
}

ASTStmt* make_array_decl_stmt(DataType decl_type, char *name, int size) {
    ASTStmt *s = alloc_stmt(STMT_DECL);
    s->data.decl.decl_type = decl_type;
    s->data.decl.name = name;
    s->data.decl.init_expr = NULL;
    s->data.decl.init_string = NULL;
    s->data.decl.init_char = '\0';
    s->data.decl.has_init = 0;
    s->data.decl.is_array = 1;
    s->data.decl.array_size = size;
    return s;
}

ASTStmt* make_decl_string_stmt(char *name, char *value) {
    ASTStmt *s = alloc_stmt(STMT_DECL);
    s->data.decl.decl_type = TYPE_STRING;
    s->data.decl.name = name;
    s->data.decl.init_expr = NULL;
    s->data.decl.init_string = value;
    s->data.decl.init_char = '\0';
    s->data.decl.has_init = 1;
    s->data.decl.is_array = 0;
    s->data.decl.array_size = 0;
    return s;
}

ASTStmt* make_decl_char_stmt(char *name, char value) {
    ASTStmt *s = alloc_stmt(STMT_DECL);
    s->data.decl.decl_type = TYPE_CHAR;
    s->data.decl.name = name;
    s->data.decl.init_expr = NULL;
    s->data.decl.init_string = NULL;
    s->data.decl.init_char = value;
    s->data.decl.has_init = 1;
    s->data.decl.is_array = 0;
    s->data.decl.array_size = 0;
    return s;
}

ASTStmt* make_assign_expr_stmt(char *name, ASTExpr *expr) {
    ASTStmt *s = alloc_stmt(STMT_ASSIGN);
    s->data.assign.name = name;
    s->data.assign.value_expr = expr;
    s->data.assign.string_value = NULL;
    s->data.assign.char_value = '\0';
    s->data.assign.assign_kind = TYPE_UNKNOWN;
    s->data.assign.target_is_array = 0;
    s->data.assign.index_expr = NULL;
    return s;
}

ASTStmt* make_array_assign_expr_stmt(char *name, ASTExpr *index_expr, ASTExpr *expr) {
    ASTStmt *s = alloc_stmt(STMT_ASSIGN);
    s->data.assign.name = name;
    s->data.assign.value_expr = expr;
    s->data.assign.string_value = NULL;
    s->data.assign.char_value = '\0';
    s->data.assign.assign_kind = TYPE_UNKNOWN;
    s->data.assign.target_is_array = 1;
    s->data.assign.index_expr = index_expr;
    return s;
}

ASTStmt* make_assign_string_stmt(char *name, char *value) {
    ASTStmt *s = alloc_stmt(STMT_ASSIGN);
    s->data.assign.name = name;
    s->data.assign.value_expr = NULL;
    s->data.assign.string_value = value;
    s->data.assign.char_value = '\0';
    s->data.assign.assign_kind = TYPE_STRING;
    s->data.assign.target_is_array = 0;
    s->data.assign.index_expr = NULL;
    return s;
}

ASTStmt* make_array_assign_string_stmt(char *name, ASTExpr *index_expr, char *value) {
    ASTStmt *s = alloc_stmt(STMT_ASSIGN);
    s->data.assign.name = name;
    s->data.assign.value_expr = NULL;
    s->data.assign.string_value = value;
    s->data.assign.char_value = '\0';
    s->data.assign.assign_kind = TYPE_STRING;
    s->data.assign.target_is_array = 1;
    s->data.assign.index_expr = index_expr;
    return s;
}

ASTStmt* make_assign_char_stmt(char *name, char value) {
    ASTStmt *s = alloc_stmt(STMT_ASSIGN);
    s->data.assign.name = name;
    s->data.assign.value_expr = NULL;
    s->data.assign.string_value = NULL;
    s->data.assign.char_value = value;
    s->data.assign.assign_kind = TYPE_CHAR;
    s->data.assign.target_is_array = 0;
    s->data.assign.index_expr = NULL;
    return s;
}

ASTStmt* make_array_assign_char_stmt(char *name, ASTExpr *index_expr, char value) {
    ASTStmt *s = alloc_stmt(STMT_ASSIGN);
    s->data.assign.name = name;
    s->data.assign.value_expr = NULL;
    s->data.assign.string_value = NULL;
    s->data.assign.char_value = value;
    s->data.assign.assign_kind = TYPE_CHAR;
    s->data.assign.target_is_array = 1;
    s->data.assign.index_expr = index_expr;
    return s;
}

ASTStmt* make_print_expr_stmt(ASTExpr *expr) {
    ASTStmt *s = alloc_stmt(STMT_PRINT);
    s->data.print_stmt.expr = expr;
    s->data.print_stmt.string_literal = NULL;
    s->data.print_stmt.char_literal = '\0';
    s->data.print_stmt.print_kind = TYPE_UNKNOWN;
    return s;
}

ASTStmt* make_print_string_stmt(char *value) {
    ASTStmt *s = alloc_stmt(STMT_PRINT);
    s->data.print_stmt.expr = NULL;
    s->data.print_stmt.string_literal = value;
    s->data.print_stmt.char_literal = '\0';
    s->data.print_stmt.print_kind = TYPE_STRING;
    return s;
}

ASTStmt* make_print_char_stmt(char value) {
    ASTStmt *s = alloc_stmt(STMT_PRINT);
    s->data.print_stmt.expr = NULL;
    s->data.print_stmt.string_literal = NULL;
    s->data.print_stmt.char_literal = value;
    s->data.print_stmt.print_kind = TYPE_CHAR;
    return s;
}

ASTStmt* make_input_stmt(char *name) {
    ASTStmt *s = alloc_stmt(STMT_INPUT);
    s->data.input_stmt.name = name;
    s->data.input_stmt.target_is_array = 0;
    s->data.input_stmt.index_expr = NULL;
    return s;
}

ASTStmt* make_array_input_stmt(char *name, ASTExpr *index_expr) {
    ASTStmt *s = alloc_stmt(STMT_INPUT);
    s->data.input_stmt.name = name;
    s->data.input_stmt.target_is_array = 1;
    s->data.input_stmt.index_expr = index_expr;
    return s;
}

ASTStmt* make_if_stmt(ASTExpr *condition, ASTStmt *then_branch, ASTStmt *else_branch) {
    ASTStmt *s = alloc_stmt(STMT_IF);
    s->data.if_stmt.condition = condition;
    s->data.if_stmt.then_branch = then_branch;
    s->data.if_stmt.else_branch = else_branch;
    return s;
}

ASTStmt* make_loop_stmt(ASTStmt *init_assign, ASTExpr *condition, ASTStmt *update_assign, ASTStmt *body) {
    ASTStmt *s = alloc_stmt(STMT_LOOP);
    s->data.loop_stmt.init_assign = init_assign;
    s->data.loop_stmt.condition = condition;
    s->data.loop_stmt.update_assign = update_assign;
    s->data.loop_stmt.body = body;
    return s;
}

ASTStmt* make_block_stmt(ASTStmt *statements) {
    ASTStmt *s = alloc_stmt(STMT_BLOCK);
    s->data.block_stmt.statements = statements;
    return s;
}

ASTStmt* make_return_expr_stmt(ASTExpr *expr) {
    ASTStmt *s = alloc_stmt(STMT_RETURN);
    s->data.return_stmt.expr = expr;
    s->data.return_stmt.string_literal = NULL;
    s->data.return_stmt.char_literal = '\0';
    s->data.return_stmt.return_kind = TYPE_UNKNOWN;
    return s;
}

ASTStmt* make_return_string_stmt(char *value) {
    ASTStmt *s = alloc_stmt(STMT_RETURN);
    s->data.return_stmt.expr = NULL;
    s->data.return_stmt.string_literal = value;
    s->data.return_stmt.char_literal = '\0';
    s->data.return_stmt.return_kind = TYPE_STRING;
    return s;
}

ASTStmt* make_return_char_stmt(char value) {
    ASTStmt *s = alloc_stmt(STMT_RETURN);
    s->data.return_stmt.expr = NULL;
    s->data.return_stmt.string_literal = NULL;
    s->data.return_stmt.char_literal = value;
    s->data.return_stmt.return_kind = TYPE_CHAR;
    return s;
}

ASTStmt* make_expr_stmt(ASTExpr *expr) {
    ASTStmt *s = alloc_stmt(STMT_EXPR);
    s->data.expr_stmt.expr = expr;
    return s;
}

ASTStmt* append_stmt(ASTStmt *list, ASTStmt *stmt) {
    ASTStmt *cur;
    if (list == NULL) return stmt;
    cur = list;
    while (cur->next != NULL) cur = cur->next;
    cur->next = stmt;
    return list;
}

ASTTopLevel* make_top_stmt(ASTStmt *stmt) {
    ASTTopLevel *t = alloc_top(TOP_STMT);
    t->data.stmt = stmt;
    return t;
}

ASTTopLevel* make_top_func(char *name, ASTIdentifierList *params, ASTStmt *body) {
    ASTTopLevel *t = alloc_top(TOP_FUNC);
    t->data.func.name = name;
    t->data.func.params = params;
    t->data.func.body = body;
    return t;
}

ASTTopLevel* append_top(ASTTopLevel *list, ASTTopLevel *item) {
    ASTTopLevel *cur;
    if (list == NULL) return item;
    cur = list;
    while (cur->next != NULL) cur = cur->next;
    cur->next = item;
    return list;
}

void free_expr(ASTExpr *expr) {
    ASTArgList *a, *next_arg;

    if (expr == NULL) return;

    switch (expr->kind) {
        case EXPR_STRING:
        case EXPR_IDENTIFIER:
            free(expr->data.sval);
            break;

        case EXPR_ARRAY_ACCESS:
            free(expr->data.array_access.name);
            free_expr(expr->data.array_access.index_expr);
            break;

        case EXPR_BINARY:
            free_expr(expr->data.binary.left);
            free_expr(expr->data.binary.right);
            break;

        case EXPR_UNARY:
            free_expr(expr->data.unary.operand);
            break;

        case EXPR_CALL:
            free(expr->data.call.name);
            a = expr->data.call.args;
            while (a != NULL) {
                next_arg = a->next;
                free_expr(a->expr);
                free(a);
                a = next_arg;
            }
            break;

        case EXPR_BUILTIN_SHAKTI:
            free_expr(expr->data.shakti.base);
            free_expr(expr->data.shakti.power);
            break;

        case EXPR_BUILTIN_BORGOMUL:
            free_expr(expr->data.borgomul.value);
            break;

        default:
            break;
    }

    free(expr);
}

void free_stmt(ASTStmt *stmt) {
    ASTStmt *next_stmt;

    if (stmt == NULL) return;

    while (stmt != NULL) {
        next_stmt = stmt->next;

        switch (stmt->kind) {
            case STMT_DECL:
                free(stmt->data.decl.name);
                free_expr(stmt->data.decl.init_expr);
                free(stmt->data.decl.init_string);
                break;

            case STMT_ASSIGN:
                free(stmt->data.assign.name);
                free_expr(stmt->data.assign.value_expr);
                free(stmt->data.assign.string_value);
                free_expr(stmt->data.assign.index_expr);
                break;

            case STMT_PRINT:
                free_expr(stmt->data.print_stmt.expr);
                free(stmt->data.print_stmt.string_literal);
                break;

            case STMT_INPUT:
                free(stmt->data.input_stmt.name);
                free_expr(stmt->data.input_stmt.index_expr);
                break;

            case STMT_IF:
                free_expr(stmt->data.if_stmt.condition);
                free_stmt(stmt->data.if_stmt.then_branch);
                free_stmt(stmt->data.if_stmt.else_branch);
                break;

            case STMT_LOOP:
                free_stmt(stmt->data.loop_stmt.init_assign);
                free_expr(stmt->data.loop_stmt.condition);
                free_stmt(stmt->data.loop_stmt.update_assign);
                free_stmt(stmt->data.loop_stmt.body);
                break;

            case STMT_BLOCK:
                free_stmt(stmt->data.block_stmt.statements);
                break;

            case STMT_RETURN:
                free_expr(stmt->data.return_stmt.expr);
                free(stmt->data.return_stmt.string_literal);
                break;

            case STMT_EXPR:
                free_expr(stmt->data.expr_stmt.expr);
                break;
        }

        free(stmt);
        stmt = next_stmt;
    }
}

void free_top_level(ASTTopLevel *node) {
    ASTTopLevel *next_top;
    ASTIdentifierList *p, *next_p;

    while (node != NULL) {
        next_top = node->next;

        if (node->kind == TOP_STMT) {
            free_stmt(node->data.stmt);
        } else {
            free(node->data.func.name);
            p = node->data.func.params;
            while (p != NULL) {
                next_p = p->next;
                free(p->name);
                free(p);
                p = next_p;
            }
            free_stmt(node->data.func.body);
        }

        free(node);
        node = next_top;
    }
}