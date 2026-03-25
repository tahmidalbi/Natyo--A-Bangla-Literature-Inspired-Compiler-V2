#include <stdio.h>
#include <string.h>
#include "symbol_table.h"

static Symbol symbols[MAX_SYMBOLS];
static int symbol_count = 0;
static int current_scope = 0;

static Symbol *current_function = NULL;

void init_symbol_table(void) {
    symbol_count = 0;
    current_scope = 0;
    current_function = NULL;
}

void bootstrap_constants(void) {
    declare_variable("PAI", TYPE_FLOAT, SYM_CONST);
    declare_variable("E", TYPE_FLOAT, SYM_CONST);
    declare_variable("G", TYPE_FLOAT, SYM_CONST);
}

void enter_scope(void) {
    current_scope++;
}

void exit_scope(void) {
    int i, j = 0;

    for (i = 0; i < symbol_count; i++) {
        if (symbols[i].scope_level != current_scope) {
            symbols[j++] = symbols[i];
        }
    }

    symbol_count = j;

    if (current_scope > 0) {
        current_scope--;
    }
}

int get_current_scope(void) {
    return current_scope;
}

Symbol* lookup_symbol(const char *name) {
    int i;
    for (i = symbol_count - 1; i >= 0; i--) {
        if (strcmp(symbols[i].name, name) == 0) {
            return &symbols[i];
        }
    }
    return NULL;
}

Symbol* lookup_symbol_current_scope(const char *name) {
    int i;
    for (i = symbol_count - 1; i >= 0; i--) {
        if (symbols[i].scope_level == current_scope &&
            strcmp(symbols[i].name, name) == 0) {
            return &symbols[i];
        }
    }
    return NULL;
}

Symbol* lookup_function(const char *name) {
    int i;
    for (i = symbol_count - 1; i >= 0; i--) {
        if (symbols[i].kind == SYM_FUNC &&
            strcmp(symbols[i].name, name) == 0) {
            return &symbols[i];
        }
    }
    return NULL;
}

int declare_variable(const char *name, DataType type, SymbolKind kind) {
    Symbol *existing = lookup_symbol_current_scope(name);

    if (existing != NULL) {
        return 0;
    }

    if (symbol_count >= MAX_SYMBOLS) {
        return 0;
    }

    strncpy(symbols[symbol_count].name, name, NAME_SIZE - 1);
    symbols[symbol_count].name[NAME_SIZE - 1] = '\0';
    symbols[symbol_count].type = type;
    symbols[symbol_count].kind = kind;
    symbols[symbol_count].scope_level = current_scope;
    symbols[symbol_count].param_count = 0;
    symbols[symbol_count].return_type = TYPE_UNKNOWN;

    symbol_count++;
    return 1;
}

int declare_function(const char *name) {
    Symbol *existing = lookup_symbol(name);

    if (existing != NULL) {
        return 0;
    }

    if (symbol_count >= MAX_SYMBOLS) {
        return 0;
    }

    strncpy(symbols[symbol_count].name, name, NAME_SIZE - 1);
    symbols[symbol_count].name[NAME_SIZE - 1] = '\0';
    symbols[symbol_count].type = TYPE_UNKNOWN;
    symbols[symbol_count].kind = SYM_FUNC;
    symbols[symbol_count].scope_level = 0;
    symbols[symbol_count].param_count = 0;
    symbols[symbol_count].return_type = TYPE_UNKNOWN;

    current_function = &symbols[symbol_count];
    symbol_count++;
    return 1;
}

void start_function_context(const char *name) {
    current_function = lookup_function(name);
    enter_scope();
}

void end_function_context(void) {
    exit_scope();
    current_function = NULL;
}

int in_function_context(void) {
    return current_function != NULL;
}

const char* current_function_name(void) {
    if (current_function == NULL) return NULL;
    return current_function->name;
}

int add_parameter_to_current_function(const char *name, DataType type) {
    if (current_function == NULL) return 0;

    if (!declare_variable(name, type, SYM_PARAM)) {
        return 0;
    }

    if (current_function->param_count >= MAX_PARAMS) {
        return 0;
    }

    current_function->param_types[current_function->param_count++] = type;
    return 1;
}

int register_return_type(DataType t) {
    if (current_function == NULL) return 0;

    if (current_function->return_type == TYPE_UNKNOWN) {
        current_function->return_type = t;
        return 1;
    }

    if (can_assign(current_function->return_type, t)) {
        return 1;
    }

    return 0;
}

const char* type_name(DataType t) {
    switch (t) {
        case TYPE_INT: return "shonkhya";
        case TYPE_FLOAT: return "purnoshonkhya";
        case TYPE_STRING: return "bakkyo";
        case TYPE_CHAR: return "okkhyor";
        case TYPE_VOID: return "void";
        default: return "unknown";
    }
}

int is_numeric_type(DataType t) {
    return (t == TYPE_INT || t == TYPE_FLOAT);
}

int can_assign(DataType target, DataType source) {
    if (target == source) return 1;

    /* implicit conversion: int -> float */
    if (target == TYPE_FLOAT && source == TYPE_INT) return 1;

    /* unknown is allowed to avoid parser collapse after one error */
    if (target == TYPE_UNKNOWN || source == TYPE_UNKNOWN) return 1;

    return 0;
}

DataType arithmetic_result_type(DataType left, DataType right) {
    if (!is_numeric_type(left) || !is_numeric_type(right)) {
        return TYPE_UNKNOWN;
    }

    if (left == TYPE_FLOAT || right == TYPE_FLOAT) {
        return TYPE_FLOAT;
    }

    return TYPE_INT;
}