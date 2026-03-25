#ifndef AST_H
#define AST_H

#include "symbol_table.h"

typedef enum {
    EXPR_INT = 0,
    EXPR_FLOAT,
    EXPR_CHAR,
    EXPR_STRING,
    EXPR_IDENTIFIER,
    EXPR_BINARY,
    EXPR_UNARY,
    EXPR_CALL,
    EXPR_BUILTIN_SHAKTI,
    EXPR_BUILTIN_BORGOMUL
} ExprKind;

typedef enum {
    OP_ADD = 0,
    OP_SUB,
    OP_MUL,
    OP_DIV,
    OP_MOD,
    OP_GT,
    OP_LT,
    OP_GEQ,
    OP_LEQ,
    OP_EQ,
    OP_NEQ,
    OP_NEG
} OperatorKind;

typedef enum {
    STMT_DECL = 0,
    STMT_ASSIGN,
    STMT_PRINT,
    STMT_INPUT,
    STMT_IF,
    STMT_LOOP,
    STMT_BLOCK,
    STMT_RETURN,
    STMT_EXPR
} StmtKind;

typedef struct ASTExpr ASTExpr;
typedef struct ASTStmt ASTStmt;
typedef struct ASTArgList ASTArgList;
typedef struct ASTIdentifierList ASTIdentifierList;
typedef struct ASTTopLevel ASTTopLevel;

struct ASTArgList {
    ASTExpr *expr;
    ASTArgList *next;
};

struct ASTIdentifierList {
    char *name;
    ASTIdentifierList *next;
};

struct ASTExpr {
    ExprKind kind;
    DataType inferred_type;

    union {
        int ival;
        double fval;
        char cval;
        char *sval;

        struct {
            OperatorKind op;
            ASTExpr *left;
            ASTExpr *right;
        } binary;

        struct {
            OperatorKind op;
            ASTExpr *operand;
        } unary;

        struct {
            char *name;
            ASTArgList *args;
        } call;

        struct {
            ASTExpr *base;
            ASTExpr *power;
        } shakti;

        struct {
            ASTExpr *value;
        } borgomul;
    } data;
};

struct ASTStmt {
    StmtKind kind;
    ASTStmt *next;

    union {
        struct {
            DataType decl_type;
            char *name;
            ASTExpr *init_expr;
            char *init_string;
            char init_char;
            int has_init;
        } decl;

        struct {
            char *name;
            ASTExpr *value_expr;
            char *string_value;
            char char_value;
            DataType assign_kind;
        } assign;

        struct {
            ASTExpr *expr;
            char *string_literal;
            char char_literal;
            DataType print_kind;
        } print_stmt;

        struct {
            char *name;
        } input_stmt;

        struct {
            ASTExpr *condition;
            ASTStmt *then_branch;
            ASTStmt *else_branch;
        } if_stmt;

        struct {
            ASTStmt *init_assign;
            ASTExpr *condition;
            ASTStmt *update_assign;
            ASTStmt *body;
        } loop_stmt;

        struct {
            ASTStmt *statements;
        } block_stmt;

        struct {
            ASTExpr *expr;
            char *string_literal;
            char char_literal;
            DataType return_kind;
        } return_stmt;

        struct {
            ASTExpr *expr;
        } expr_stmt;
    } data;
};

typedef enum {
    TOP_STMT = 0,
    TOP_FUNC
} TopLevelKind;

struct ASTTopLevel {
    TopLevelKind kind;
    ASTTopLevel *next;

    union {
        ASTStmt *stmt;
        struct {
            char *name;
            ASTIdentifierList *params;
            ASTStmt *body;
        } func;
    } data;
};

ASTExpr* make_int_expr(int value);
ASTExpr* make_float_expr(double value);
ASTExpr* make_char_expr(char value);
ASTExpr* make_string_expr(char *value);
ASTExpr* make_identifier_expr(char *name);
ASTExpr* make_binary_expr(OperatorKind op, ASTExpr *left, ASTExpr *right);
ASTExpr* make_unary_expr(OperatorKind op, ASTExpr *operand);
ASTExpr* make_call_expr(char *name, ASTArgList *args);
ASTExpr* make_shakti_expr(ASTExpr *base, ASTExpr *power);
ASTExpr* make_borgomul_expr(ASTExpr *value);

ASTArgList* make_arg_list(ASTExpr *expr);
ASTArgList* append_arg(ASTArgList *list, ASTExpr *expr);

ASTIdentifierList* make_identifier_list(char *name);
ASTIdentifierList* append_identifier(ASTIdentifierList *list, char *name);

ASTStmt* make_decl_stmt(DataType decl_type, char *name, ASTExpr *init_expr);
ASTStmt* make_decl_string_stmt(char *name, char *value);
ASTStmt* make_decl_char_stmt(char *name, char value);

ASTStmt* make_assign_expr_stmt(char *name, ASTExpr *expr);
ASTStmt* make_assign_string_stmt(char *name, char *value);
ASTStmt* make_assign_char_stmt(char *name, char value);

ASTStmt* make_print_expr_stmt(ASTExpr *expr);
ASTStmt* make_print_string_stmt(char *value);
ASTStmt* make_print_char_stmt(char value);

ASTStmt* make_input_stmt(char *name);
ASTStmt* make_if_stmt(ASTExpr *condition, ASTStmt *then_branch, ASTStmt *else_branch);
ASTStmt* make_loop_stmt(ASTStmt *init_assign, ASTExpr *condition, ASTStmt *update_assign, ASTStmt *body);
ASTStmt* make_block_stmt(ASTStmt *statements);
ASTStmt* make_return_expr_stmt(ASTExpr *expr);
ASTStmt* make_return_string_stmt(char *value);
ASTStmt* make_return_char_stmt(char value);
ASTStmt* make_expr_stmt(ASTExpr *expr);

ASTStmt* append_stmt(ASTStmt *list, ASTStmt *stmt);

ASTTopLevel* make_top_stmt(ASTStmt *stmt);
ASTTopLevel* make_top_func(char *name, ASTIdentifierList *params, ASTStmt *body);
ASTTopLevel* append_top(ASTTopLevel *list, ASTTopLevel *item);

void free_expr(ASTExpr *expr);
void free_stmt(ASTStmt *stmt);
void free_top_level(ASTTopLevel *node);

#endif