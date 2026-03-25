#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "ast.h"
#include "symbol_table.h"

typedef struct {
    int has_return;
    RuntimeValue value;
} ExecResult;

void interpret_program(ASTTopLevel *program);

#endif