%code requires {
    #include "symbol_table.h"

    typedef struct {
        DataType type;
    } ExprAttr;

    typedef struct {
        int count;
        DataType types[MAX_PARAMS];
    } ArgListAttr;
}

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "symbol_table.h"

int yylex(void);
void yyerror(const char *s);

extern FILE *yyin;
extern int yylineno;

static int semantic_errors = 0;
static DataType current_decl_type = TYPE_UNKNOWN;

void semantic_error(const char *msg) {
    fprintf(stderr, "Semantic Error at line %d: %s\n", yylineno, msg);
    semantic_errors++;
}
%}

%union {
    int ival;
    double fval;
    char cval;
    char *sval;
    ExprAttr expr;
    ArgListAttr args;
}

/* Tokens with values */
%token <ival> INT_LITERAL
%token <fval> FLOAT_LITERAL
%token <cval> CHAR_LITERAL
%token <sval> STRING_LITERAL
%token <sval> IDENTIFIER

/* Keywords */
%token PROSTABONA UPOSHONGHAR
%token DRISSHO SHURU SHESH
%token SHONKHYA PURNOSHONKHYA BAKKYO OKKHYOR
%token SHOBDO JOBDO
%token JODI ONNOTHA CHOKRO
%token SHAKTI BORGOMUL
%token PHEROT

/* Operators / punctuation */
%token ASSIGN
%token PLUS MINUS MULT DIV MOD
%token GT LT GEQ LEQ EQ NEQ
%token SEMICOLON COMMA
%token LPAREN RPAREN

%nonassoc LOWER_THAN_ELSE
%nonassoc ONNOTHA
%left GT LT GEQ LEQ EQ NEQ
%left PLUS MINUS
%left MULT DIV MOD
%right UMINUS

%type <expr> expression
%type <ival> condition
%type <args> argument_list argument_list_opt argument
%type <expr> function_call

%%

program
    : PROSTABONA global_items UPOSHONGHAR
      {
          if (semantic_errors == 0) {
              printf("Semantic Analysis Successful: program is meaningful.\n");
          } else {
              printf("Semantic Analysis finished with %d semantic error(s).\n", semantic_errors);
          }
      }
    ;

global_items
    : /* empty */
    | global_items global_item
    ;

global_item
    : statement
    | function_definition
    ;

function_definition
    : DRISSHO IDENTIFIER
      {
          if (!declare_function($2)) {
              semantic_error("function redeclared");
          }
          start_function_context($2);
      }
      LPAREN parameter_list_opt RPAREN function_body
      {
          end_function_context();
          free($2);
      }
    ;

function_body
    : SHURU statement_list SHESH
    ;

parameter_list_opt
    : /* empty */
    | parameter_list
    ;

parameter_list
    : IDENTIFIER
      {
          /* current syntax has untyped params, so we treat them as numeric placeholders */
          if (!add_parameter_to_current_function($1, TYPE_FLOAT)) {
              semantic_error("parameter redeclared");
          }
          free($1);
      }
    | parameter_list COMMA IDENTIFIER
      {
          if (!add_parameter_to_current_function($3, TYPE_FLOAT)) {
              semantic_error("parameter redeclared");
          }
          free($3);
      }
    ;

block
    : SHURU
      {
          enter_scope();
      }
      statement_list
      SHESH
      {
          exit_scope();
      }
    ;

statement_list
    : /* empty */
    | statement_list statement
    ;

statement
    : declaration SEMICOLON
    | assignment SEMICOLON
    | print_stmt SEMICOLON
    | input_stmt SEMICOLON
    | function_call SEMICOLON
    | return_stmt SEMICOLON
    | if_stmt
    | loop_stmt
    | block
    ;

declaration
    : SHONKHYA
      {
          current_decl_type = TYPE_INT;
      }
      numeric_declarator_list
    | PURNOSHONKHYA
      {
          current_decl_type = TYPE_FLOAT;
      }
      numeric_declarator_list
    | BAKKYO
      {
          current_decl_type = TYPE_STRING;
      }
      string_declarator_list
    | OKKHYOR
      {
          current_decl_type = TYPE_CHAR;
      }
      char_declarator_list
    ;

numeric_declarator_list
    : numeric_declarator
    | numeric_declarator_list COMMA numeric_declarator
    ;

numeric_declarator
    : IDENTIFIER
      {
          if (!declare_variable($1, current_decl_type, SYM_VAR)) {
              semantic_error("variable redeclared in same scope");
          }
          free($1);
      }
    | IDENTIFIER ASSIGN expression
      {
          if (!declare_variable($1, current_decl_type, SYM_VAR)) {
              semantic_error("variable redeclared in same scope");
          } else if (!can_assign(current_decl_type, $3.type)) {
              semantic_error("type mismatch in declaration assignment");
          }
          free($1);
      }
    ;

string_declarator_list
    : string_declarator
    | string_declarator_list COMMA string_declarator
    ;

string_declarator
    : IDENTIFIER
      {
          if (!declare_variable($1, TYPE_STRING, SYM_VAR)) {
              semantic_error("variable redeclared in same scope");
          }
          free($1);
      }
    | IDENTIFIER ASSIGN STRING_LITERAL
      {
          if (!declare_variable($1, TYPE_STRING, SYM_VAR)) {
              semantic_error("variable redeclared in same scope");
          }
          free($1);
          free($3);
      }
    ;

char_declarator_list
    : char_declarator
    | char_declarator_list COMMA char_declarator
    ;

char_declarator
    : IDENTIFIER
      {
          if (!declare_variable($1, TYPE_CHAR, SYM_VAR)) {
              semantic_error("variable redeclared in same scope");
          }
          free($1);
      }
    | IDENTIFIER ASSIGN CHAR_LITERAL
      {
          if (!declare_variable($1, TYPE_CHAR, SYM_VAR)) {
              semantic_error("variable redeclared in same scope");
          }
          free($1);
      }
    ;

assignment
    : IDENTIFIER ASSIGN expression
      {
          Symbol *s = lookup_symbol($1);
          if (s == NULL) {
              semantic_error("assignment to undeclared variable");
          } else if (s->kind == SYM_CONST) {
              semantic_error("cannot modify constant");
          } else if (!can_assign(s->type, $3.type)) {
              semantic_error("type mismatch in assignment");
          }
          free($1);
      }
    | IDENTIFIER ASSIGN STRING_LITERAL
      {
          Symbol *s = lookup_symbol($1);
          if (s == NULL) {
              semantic_error("assignment to undeclared variable");
          } else if (s->kind == SYM_CONST) {
              semantic_error("cannot modify constant");
          } else if (!can_assign(s->type, TYPE_STRING)) {
              semantic_error("type mismatch in assignment");
          }
          free($1);
          free($3);
      }
    | IDENTIFIER ASSIGN CHAR_LITERAL
      {
          Symbol *s = lookup_symbol($1);
          if (s == NULL) {
              semantic_error("assignment to undeclared variable");
          } else if (s->kind == SYM_CONST) {
              semantic_error("cannot modify constant");
          } else if (!can_assign(s->type, TYPE_CHAR)) {
              semantic_error("type mismatch in assignment");
          }
          free($1);
      }
    ;

print_stmt
    : SHOBDO printable
    ;

printable
    : expression
    | STRING_LITERAL
      {
          free($1);
      }
    | CHAR_LITERAL
    ;

input_stmt
    : JOBDO IDENTIFIER
      {
          if (lookup_symbol($2) == NULL) {
              semantic_error("input target is undeclared");
          }
          free($2);
      }
    ;

return_stmt
    : PHEROT expression
      {
          if (!in_function_context()) {
              semantic_error("pherot used outside function");
          } else if (!register_return_type($2.type)) {
              semantic_error("inconsistent function return type");
          }
      }
    | PHEROT STRING_LITERAL
      {
          if (!in_function_context()) {
              semantic_error("pherot used outside function");
          } else if (!register_return_type(TYPE_STRING)) {
              semantic_error("inconsistent function return type");
          }
          free($2);
      }
    | PHEROT CHAR_LITERAL
      {
          if (!in_function_context()) {
              semantic_error("pherot used outside function");
          } else if (!register_return_type(TYPE_CHAR)) {
              semantic_error("inconsistent function return type");
          }
      }
    ;

if_stmt
    : JODI LPAREN condition RPAREN statement %prec LOWER_THAN_ELSE
    | JODI LPAREN condition RPAREN statement ONNOTHA statement
    ;

loop_stmt
    : CHOKRO LPAREN assignment SEMICOLON condition SEMICOLON assignment RPAREN statement
    ;

function_call
    : IDENTIFIER LPAREN argument_list_opt RPAREN
      {
          Symbol *f = lookup_function($1);
          if (f == NULL) {
              semantic_error("call to undeclared function");
              $$.type = TYPE_UNKNOWN;
          } else {
              if (f->param_count != $3.count) {
                  semantic_error("wrong number of function arguments");
              } else {
                  int i;
                  for (i = 0; i < f->param_count && i < $3.count; i++) {
                      if (!can_assign(f->param_types[i], $3.types[i])) {
                          semantic_error("function argument type mismatch");
                          break;
                      }
                  }
              }
              $$.type = f->return_type;
          }
          free($1);
      }
    ;

argument_list_opt
    : /* empty */
      {
          $$.count = 0;
      }
    | argument_list
      {
          $$ = $1;
      }
    ;

argument_list
    : argument
      {
          $$ = $1;
      }
    | argument_list COMMA argument
      {
          int i;
          $$ = $1;
          if ($$.count < MAX_PARAMS) {
              for (i = 0; i < $3.count; i++) {
                  $$.types[$$.count++] = $3.types[i];
              }
          }
      }
    ;

argument
    : expression
      {
          $$.count = 1;
          $$.types[0] = $1.type;
      }
    | STRING_LITERAL
      {
          $$.count = 1;
          $$.types[0] = TYPE_STRING;
          free($1);
      }
    | CHAR_LITERAL
      {
          $$.count = 1;
          $$.types[0] = TYPE_CHAR;
      }
    ;

condition
    : expression GT expression
      {
          if (!is_numeric_type($1.type) || !is_numeric_type($3.type)) {
              semantic_error("comparison requires numeric operands");
          }
          $$ = 1;
      }
    | expression LT expression
      {
          if (!is_numeric_type($1.type) || !is_numeric_type($3.type)) {
              semantic_error("comparison requires numeric operands");
          }
          $$ = 1;
      }
    | expression GEQ expression
      {
          if (!is_numeric_type($1.type) || !is_numeric_type($3.type)) {
              semantic_error("comparison requires numeric operands");
          }
          $$ = 1;
      }
    | expression LEQ expression
      {
          if (!is_numeric_type($1.type) || !is_numeric_type($3.type)) {
              semantic_error("comparison requires numeric operands");
          }
          $$ = 1;
      }
    | expression EQ expression
      {
          if (!is_numeric_type($1.type) || !is_numeric_type($3.type)) {
              semantic_error("comparison requires numeric operands");
          }
          $$ = 1;
      }
    | expression NEQ expression
      {
          if (!is_numeric_type($1.type) || !is_numeric_type($3.type)) {
              semantic_error("comparison requires numeric operands");
          }
          $$ = 1;
      }
    ;

expression
    : expression PLUS expression
      {
          DataType t = arithmetic_result_type($1.type, $3.type);
          if (t == TYPE_UNKNOWN) {
              semantic_error("invalid operands for +");
          }
          $$.type = t;
      }
    | expression MINUS expression
      {
          DataType t = arithmetic_result_type($1.type, $3.type);
          if (t == TYPE_UNKNOWN) {
              semantic_error("invalid operands for -");
          }
          $$.type = t;
      }
    | expression MULT expression
      {
          DataType t = arithmetic_result_type($1.type, $3.type);
          if (t == TYPE_UNKNOWN) {
              semantic_error("invalid operands for *");
          }
          $$.type = t;
      }
    | expression DIV expression
      {
          DataType t = arithmetic_result_type($1.type, $3.type);
          if (t == TYPE_UNKNOWN) {
              semantic_error("invalid operands for /");
          }
          $$.type = t;
      }
    | expression MOD expression
      {
          if ($1.type != TYPE_INT || $3.type != TYPE_INT) {
              semantic_error("modulo requires integer operands");
              $$.type = TYPE_UNKNOWN;
          } else {
              $$.type = TYPE_INT;
          }
      }
    | MINUS expression %prec UMINUS
      {
          if (!is_numeric_type($2.type)) {
              semantic_error("unary minus requires numeric operand");
              $$.type = TYPE_UNKNOWN;
          } else {
              $$.type = $2.type;
          }
      }
    | LPAREN expression RPAREN
      {
          $$.type = $2.type;
      }
    | SHAKTI LPAREN expression COMMA expression RPAREN
      {
          if (!is_numeric_type($3.type) || !is_numeric_type($5.type)) {
              semantic_error("shakti requires numeric arguments");
              $$.type = TYPE_UNKNOWN;
          } else {
              $$.type = arithmetic_result_type($3.type, $5.type);
          }
      }
    | BORGOMUL LPAREN expression RPAREN
      {
          if (!is_numeric_type($3.type)) {
              semantic_error("borgomul requires numeric argument");
              $$.type = TYPE_UNKNOWN;
          } else {
              $$.type = TYPE_FLOAT;
          }
      }
    | function_call
      {
          $$.type = $1.type;
      }
    | INT_LITERAL
      {
          $$.type = TYPE_INT;
      }
    | FLOAT_LITERAL
      {
          $$.type = TYPE_FLOAT;
      }
    | IDENTIFIER
      {
          Symbol *s = lookup_symbol($1);
          if (s == NULL) {
              semantic_error("use of undeclared variable");
              $$.type = TYPE_UNKNOWN;
          } else {
              $$.type = s->type;
          }
          free($1);
      }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Syntax Error at line %d: %s\n", yylineno, s);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: natyo_semantic.exe <input_file>\n");
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if (!yyin) {
        perror("Could not open input file");
        return 1;
    }

    init_symbol_table();
    bootstrap_constants();

    printf("Starting semantic analysis...\n");
    yyparse();

    fclose(yyin);
    return 0;
}