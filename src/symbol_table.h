#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#define MAX_SYMBOLS 512
#define MAX_PARAMS 16
#define NAME_SIZE 64

typedef struct ASTStmt ASTStmt;

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
    DataType type;
    double num_val;
    char *str_val;
    char char_val;
} RuntimeValue;

typedef struct {
    char name[NAME_SIZE];
    DataType type;
    SymbolKind kind;
    int scope_level;

    int is_array;
    int array_size;

    RuntimeValue value;
    RuntimeValue *array_values;

    int param_count;
    DataType param_types[MAX_PARAMS];
    char param_names[MAX_PARAMS][NAME_SIZE];
    DataType return_type;
    ASTStmt *function_body;
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
int declare_array(const char *name, DataType type, SymbolKind kind, int array_size);
int declare_function(const char *name);
int add_parameter_to_current_function(const char *name, DataType type);

void start_function_context(const char *name);
void end_function_context(void);
int in_function_context(void);
const char* current_function_name(void);

int register_return_type(DataType t);
void set_current_function_body(ASTStmt *body);

void set_symbol_numeric(Symbol *s, double value);
void set_symbol_string(Symbol *s, const char *value);
void set_symbol_char(Symbol *s, char value);

void set_array_element_numeric(Symbol *s, int index, double value);
void set_array_element_string(Symbol *s, int index, const char *value);
void set_array_element_char(Symbol *s, int index, char value);

const char* type_name(DataType t);
int is_numeric_type(DataType t);
int can_assign(DataType target, DataType source);
DataType arithmetic_result_type(DataType left, DataType right);

#endif