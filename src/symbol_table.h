#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#define MAX_SYMBOLS 512
#define MAX_PARAMS 16
#define NAME_SIZE 64

typedef enum {
    TYPE_UNKNOWN = 0,
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_STRING,
    TYPE_CHAR,
    TYPE_VOID
} DataType;

typedef enum {
    SYM_VAR = 0,
    SYM_FUNC,
    SYM_PARAM,
    SYM_CONST
} SymbolKind;

typedef struct {
    char name[NAME_SIZE];
    DataType type;
    SymbolKind kind;
    int scope_level;

    /* For functions */
    int param_count;
    DataType param_types[MAX_PARAMS];
    DataType return_type;
} Symbol;

void init_symbol_table(void);
void bootstrap_constants(void);

void enter_scope(void);
void exit_scope(void);
int get_current_scope(void);

Symbol* lookup_symbol(const char *name);
Symbol* lookup_symbol_current_scope(const char *name);
Symbol* lookup_function(const char *name);

int declare_variable(const char *name, DataType type, SymbolKind kind);
int declare_function(const char *name);
int add_parameter_to_current_function(const char *name, DataType type);

void start_function_context(const char *name);
void end_function_context(void);
int in_function_context(void);
const char* current_function_name(void);

int register_return_type(DataType t);

const char* type_name(DataType t);
int is_numeric_type(DataType t);
int can_assign(DataType target, DataType source);
DataType arithmetic_result_type(DataType left, DataType right);

#endif