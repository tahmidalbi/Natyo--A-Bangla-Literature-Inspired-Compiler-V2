#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "symbol_table.h"

static Symbol symbols[MAX_SYMBOLS];
static int symbol_count = 0;
static int current_scope = 0;
static Symbol *current_function = NULL;

static void clear_runtime_value(RuntimeValue *v) {
    if (v->type == TYPE_STRING && v->str_val != NULL) {
        free(v->str_val);
        v->str_val = NULL;
    }
    v->type = TYPE_UNKNOWN;
    v->num_val = 0.0;
    v->char_val = '\0';
}

static void clear_symbol_runtime(Symbol *s) {
    int i;

    clear_runtime_value(&s->value);

    if (s->array_values != NULL) {
        for (i = 0; i < s->array_size; i++) {
            clear_runtime_value(&s->array_values[i]);
        }
        free(s->array_values);
        s->array_values = NULL;
    }
}

void init_symbol_table(void) {
    int i;
    for (i = 0; i < symbol_count; i++) {
        clear_symbol_runtime(&symbols[i]);
    }
    symbol_count = 0;
    current_scope = 0;
    current_function = NULL;
}

void bootstrap_constants(void) {
    Symbol *s;

    declare_variable("PAI", TYPE_FLOAT, SYM_CONST);
    s = lookup_symbol("PAI");
    set_symbol_numeric(s, 3.1416);

    declare_variable("E", TYPE_FLOAT, SYM_CONST);
    s = lookup_symbol("E");
    set_symbol_numeric(s, 2.718);

    declare_variable("G", TYPE_FLOAT, SYM_CONST);
    s = lookup_symbol("G");
    set_symbol_numeric(s, 9.8);
}

void enter_scope(void) {
    current_scope++;
}

void exit_scope(void) {
    int i, j = 0;

    for (i = 0; i < symbol_count; i++) {
        if (symbols[i].scope_level == current_scope &&
            symbols[i].kind != SYM_FUNC &&
            symbols[i].kind != SYM_CONST) {
            clear_symbol_runtime(&symbols[i]);
            continue;
        }
        symbols[j++] = symbols[i];
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

    if (existing != NULL) return 0;
    if (symbol_count >= MAX_SYMBOLS) return 0;

    strncpy(symbols[symbol_count].name, name, NAME_SIZE - 1);
    symbols[symbol_count].name[NAME_SIZE - 1] = '\0';
    symbols[symbol_count].type = type;
    symbols[symbol_count].kind = kind;
    symbols[symbol_count].scope_level = current_scope;

    symbols[symbol_count].is_array = 0;
    symbols[symbol_count].array_size = 0;
    symbols[symbol_count].array_values = NULL;

    symbols[symbol_count].value.type = type;
    symbols[symbol_count].value.num_val = 0.0;
    symbols[symbol_count].value.str_val = NULL;
    symbols[symbol_count].value.char_val = '\0';

    symbols[symbol_count].param_count = 0;
    symbols[symbol_count].return_type = TYPE_UNKNOWN;
    symbols[symbol_count].function_body = NULL;

    symbol_count++;
    return 1;
}

int declare_array(const char *name, DataType type, SymbolKind kind, int array_size) {
    int i;
    Symbol *existing = lookup_symbol_current_scope(name);

    if (existing != NULL) return 0;
    if (symbol_count >= MAX_SYMBOLS) return 0;
    if (array_size <= 0) return 0;

    strncpy(symbols[symbol_count].name, name, NAME_SIZE - 1);
    symbols[symbol_count].name[NAME_SIZE - 1] = '\0';
    symbols[symbol_count].type = type;
    symbols[symbol_count].kind = kind;
    symbols[symbol_count].scope_level = current_scope;

    symbols[symbol_count].is_array = 1;
    symbols[symbol_count].array_size = array_size;
    symbols[symbol_count].array_values = (RuntimeValue *)malloc(sizeof(RuntimeValue) * array_size);

    for (i = 0; i < array_size; i++) {
        symbols[symbol_count].array_values[i].type = type;
        symbols[symbol_count].array_values[i].num_val = 0.0;
        symbols[symbol_count].array_values[i].str_val = NULL;
        symbols[symbol_count].array_values[i].char_val = '\0';
    }

    symbols[symbol_count].value.type = TYPE_UNKNOWN;
    symbols[symbol_count].value.num_val = 0.0;
    symbols[symbol_count].value.str_val = NULL;
    symbols[symbol_count].value.char_val = '\0';

    symbols[symbol_count].param_count = 0;
    symbols[symbol_count].return_type = TYPE_UNKNOWN;
    symbols[symbol_count].function_body = NULL;

    symbol_count++;
    return 1;
}

int declare_function(const char *name) {
    Symbol *existing = lookup_symbol(name);

    if (existing != NULL) return 0;
    if (symbol_count >= MAX_SYMBOLS) return 0;

    strncpy(symbols[symbol_count].name, name, NAME_SIZE - 1);
    symbols[symbol_count].name[NAME_SIZE - 1] = '\0';
    symbols[symbol_count].type = TYPE_UNKNOWN;
    symbols[symbol_count].kind = SYM_FUNC;
    symbols[symbol_count].scope_level = 0;

    symbols[symbol_count].is_array = 0;
    symbols[symbol_count].array_size = 0;
    symbols[symbol_count].array_values = NULL;

    symbols[symbol_count].value.type = TYPE_UNKNOWN;
    symbols[symbol_count].value.num_val = 0.0;
    symbols[symbol_count].value.str_val = NULL;
    symbols[symbol_count].value.char_val = '\0';

    symbols[symbol_count].param_count = 0;
    symbols[symbol_count].return_type = TYPE_UNKNOWN;
    symbols[symbol_count].function_body = NULL;

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
    if (!declare_variable(name, type, SYM_PARAM)) return 0;
    if (current_function->param_count >= MAX_PARAMS) return 0;

    current_function->param_types[current_function->param_count] = type;
    strncpy(current_function->param_names[current_function->param_count], name, NAME_SIZE - 1);
    current_function->param_names[current_function->param_count][NAME_SIZE - 1] = '\0';
    current_function->param_count++;
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

void set_current_function_body(ASTStmt *body) {
    if (current_function != NULL) {
        current_function->function_body = body;
    }
}

void set_symbol_numeric(Symbol *s, double value) {
    if (s == NULL || s->is_array) return;

    if (s->value.type == TYPE_STRING && s->value.str_val != NULL) {
        free(s->value.str_val);
        s->value.str_val = NULL;
    }

    s->value.type = s->type;
    s->value.num_val = value;
    s->value.char_val = '\0';
}

void set_symbol_string(Symbol *s, const char *value) {
    if (s == NULL || s->is_array) return;

    if (s->value.type == TYPE_STRING && s->value.str_val != NULL) {
        free(s->value.str_val);
    }

    s->value.type = TYPE_STRING;
    s->value.str_val = strdup(value);
    s->value.num_val = 0.0;
    s->value.char_val = '\0';
}

void set_symbol_char(Symbol *s, char value) {
    if (s == NULL || s->is_array) return;

    if (s->value.type == TYPE_STRING && s->value.str_val != NULL) {
        free(s->value.str_val);
        s->value.str_val = NULL;
    }

    s->value.type = TYPE_CHAR;
    s->value.char_val = value;
    s->value.num_val = 0.0;
}

void set_array_element_numeric(Symbol *s, int index, double value) {
    if (s == NULL || !s->is_array || index < 0 || index >= s->array_size) return;

    if (s->array_values[index].type == TYPE_STRING && s->array_values[index].str_val != NULL) {
        free(s->array_values[index].str_val);
        s->array_values[index].str_val = NULL;
    }

    s->array_values[index].type = s->type;
    s->array_values[index].num_val = value;
    s->array_values[index].char_val = '\0';
}

void set_array_element_string(Symbol *s, int index, const char *value) {
    if (s == NULL || !s->is_array || index < 0 || index >= s->array_size) return;

    if (s->array_values[index].type == TYPE_STRING && s->array_values[index].str_val != NULL) {
        free(s->array_values[index].str_val);
    }

    s->array_values[index].type = TYPE_STRING;
    s->array_values[index].str_val = strdup(value);
    s->array_values[index].num_val = 0.0;
    s->array_values[index].char_val = '\0';
}

void set_array_element_char(Symbol *s, int index, char value) {
    if (s == NULL || !s->is_array || index < 0 || index >= s->array_size) return;

    if (s->array_values[index].type == TYPE_STRING && s->array_values[index].str_val != NULL) {
        free(s->array_values[index].str_val);
        s->array_values[index].str_val = NULL;
    }

    s->array_values[index].type = TYPE_CHAR;
    s->array_values[index].char_val = value;
    s->array_values[index].num_val = 0.0;
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
    if (target == TYPE_FLOAT && source == TYPE_INT) return 1;
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