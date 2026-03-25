#include <stdlib.h>
#include <math.h>
#include "optimizer.h"

static int is_numeric_literal(ASTExpr *expr) {
    return expr != NULL &&
           (expr->kind == EXPR_INT || expr->kind == EXPR_FLOAT);
}

static double get_numeric_literal_value(ASTExpr *expr) {
    if (expr->kind == EXPR_INT) return (double)expr->data.ival;
    return expr->data.fval;
}

static void replace_with_int(ASTExpr *expr, int value) {
    expr->kind = EXPR_INT;
    expr->inferred_type = TYPE_INT;
    expr->data.ival = value;
}

static void replace_with_float(ASTExpr *expr, double value) {
    expr->kind = EXPR_FLOAT;
    expr->inferred_type = TYPE_FLOAT;
    expr->data.fval = value;
}

static ASTExpr* optimize_expr(ASTExpr *expr);

static void optimize_stmt_list(ASTStmt *stmt);

static ASTExpr* optimize_expr(ASTExpr *expr) {
    double left_val, right_val, result;
    int is_float_result;

    if (expr == NULL) return NULL;

    switch (expr->kind) {
        case EXPR_BINARY:
            expr->data.binary.left = optimize_expr(expr->data.binary.left);
            expr->data.binary.right = optimize_expr(expr->data.binary.right);

            if (is_numeric_literal(expr->data.binary.left) &&
                is_numeric_literal(expr->data.binary.right)) {

                left_val = get_numeric_literal_value(expr->data.binary.left);
                right_val = get_numeric_literal_value(expr->data.binary.right);
                is_float_result = (
                    expr->data.binary.left->kind == EXPR_FLOAT ||
                    expr->data.binary.right->kind == EXPR_FLOAT
                );

                switch (expr->data.binary.op) {
                    case OP_ADD:
                        result = left_val + right_val;
                        if (is_float_result) replace_with_float(expr, result);
                        else replace_with_int(expr, (int)result);
                        break;

                    case OP_SUB:
                        result = left_val - right_val;
                        if (is_float_result) replace_with_float(expr, result);
                        else replace_with_int(expr, (int)result);
                        break;

                    case OP_MUL:
                        result = left_val * right_val;
                        if (is_float_result) replace_with_float(expr, result);
                        else replace_with_int(expr, (int)result);
                        break;

                    case OP_DIV:
                        if (fabs(right_val) > 1e-12) {
                            result = left_val / right_val;
                            replace_with_float(expr, result);
                        }
                        break;

                    case OP_MOD:
                        if ((int)right_val != 0) {
                            replace_with_int(expr, ((int)left_val % (int)right_val));
                        }
                        break;

                    case OP_GT:
                        replace_with_int(expr, left_val > right_val);
                        break;

                    case OP_LT:
                        replace_with_int(expr, left_val < right_val);
                        break;

                    case OP_GEQ:
                        replace_with_int(expr, left_val >= right_val);
                        break;

                    case OP_LEQ:
                        replace_with_int(expr, left_val <= right_val);
                        break;

                    case OP_EQ:
                        replace_with_int(expr, fabs(left_val - right_val) < 1e-12);
                        break;

                    case OP_NEQ:
                        replace_with_int(expr, fabs(left_val - right_val) >= 1e-12);
                        break;

                    default:
                        break;
                }
            }
            break;

        case EXPR_UNARY:
            expr->data.unary.operand = optimize_expr(expr->data.unary.operand);

            if (expr->data.unary.op == OP_NEG &&
                is_numeric_literal(expr->data.unary.operand)) {

                result = -get_numeric_literal_value(expr->data.unary.operand);

                if (expr->data.unary.operand->kind == EXPR_FLOAT) {
                    replace_with_float(expr, result);
                } else {
                    replace_with_int(expr, (int)result);
                }
            }
            break;

        case EXPR_BUILTIN_SHAKTI:
            expr->data.shakti.base = optimize_expr(expr->data.shakti.base);
            expr->data.shakti.power = optimize_expr(expr->data.shakti.power);

            if (is_numeric_literal(expr->data.shakti.base) &&
                is_numeric_literal(expr->data.shakti.power)) {

                result = pow(
                    get_numeric_literal_value(expr->data.shakti.base),
                    get_numeric_literal_value(expr->data.shakti.power)
                );
                replace_with_float(expr, result);
            }
            break;

        case EXPR_BUILTIN_BORGOMUL:
            expr->data.borgomul.value = optimize_expr(expr->data.borgomul.value);

            if (is_numeric_literal(expr->data.borgomul.value)) {
                result = sqrt(get_numeric_literal_value(expr->data.borgomul.value));
                replace_with_float(expr, result);
            }
            break;

        case EXPR_CALL: {
            ASTArgList *arg = expr->data.call.args;
            while (arg != NULL) {
                arg->expr = optimize_expr(arg->expr);
                arg = arg->next;
            }
            break;
        }

        default:
            break;
    }

    return expr;
}

static void optimize_stmt(ASTStmt *stmt) {
    if (stmt == NULL) return;

    switch (stmt->kind) {
        case STMT_DECL:
            stmt->data.decl.init_expr = optimize_expr(stmt->data.decl.init_expr);
            break;

        case STMT_ASSIGN:
            stmt->data.assign.value_expr = optimize_expr(stmt->data.assign.value_expr);
            break;

        case STMT_PRINT:
            stmt->data.print_stmt.expr = optimize_expr(stmt->data.print_stmt.expr);
            break;

        case STMT_IF:
            stmt->data.if_stmt.condition = optimize_expr(stmt->data.if_stmt.condition);
            optimize_stmt(stmt->data.if_stmt.then_branch);
            optimize_stmt(stmt->data.if_stmt.else_branch);
            break;

        case STMT_LOOP:
            optimize_stmt(stmt->data.loop_stmt.init_assign);
            stmt->data.loop_stmt.condition = optimize_expr(stmt->data.loop_stmt.condition);
            optimize_stmt(stmt->data.loop_stmt.update_assign);
            optimize_stmt(stmt->data.loop_stmt.body);
            break;

        case STMT_BLOCK:
            optimize_stmt_list(stmt->data.block_stmt.statements);
            break;

        case STMT_RETURN:
            stmt->data.return_stmt.expr = optimize_expr(stmt->data.return_stmt.expr);
            break;

        case STMT_EXPR:
            stmt->data.expr_stmt.expr = optimize_expr(stmt->data.expr_stmt.expr);
            break;

        case STMT_INPUT:
        default:
            break;
    }
}

static void optimize_stmt_list(ASTStmt *stmt) {
    while (stmt != NULL) {
        optimize_stmt(stmt);
        stmt = stmt->next;
    }
}

void optimize_program(ASTTopLevel *program) {
    while (program != NULL) {
        if (program->kind == TOP_STMT) {
            optimize_stmt(program->data.stmt);
        } else {
            optimize_stmt(program->data.func.body);
        }
        program = program->next;
    }
}