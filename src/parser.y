%code requires {
    #include "symbol_table.h"
    #include "ast.h"

    typedef struct {
        DataType type;
        ASTExpr *node;
    } ExprAttr;

    typedef struct {
        int count;
        DataType types[MAX_PARAMS];
        ASTArgList *nodes;
    } ArgListAttr;
}

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"
#include "ast.h"
#include "interpreter.h"
#include "utils.h"
#include "optimizer.h"
#include "tac.h"

int yylex(void);
void yyerror(const char *s);

extern FILE *yyin;
extern int yylineno;

static int semantic_errors = 0;
static DataType current_decl_type = TYPE_UNKNOWN;
static ASTTopLevel *program_root = NULL;

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
    ASTStmt *stmt;
    ASTIdentifierList *idlist;
    ASTTopLevel *top;
}

%token <ival> INT_LITERAL
%token <fval> FLOAT_LITERAL
%token <cval> CHAR_LITERAL
%token <sval> STRING_LITERAL
%token <sval> IDENTIFIER

%token PROSTABONA UPOSHONGHAR
%token DRISSHO SHURU SHESH
%token SHONKHYA PURNOSHONKHYA BAKKYO OKKHYOR
%token SHOBDO JOBDO
%token JODI ONNOTHA CHOKRO
%token SHAKTI BORGOMUL
%token PHEROT

%token ASSIGN
%token PLUS MINUS MULT DIV MOD
%token GT LT GEQ LEQ EQ NEQ
%token SEMICOLON COMMA
%token LPAREN RPAREN
%token LBRACKET RBRACKET

%nonassoc LOWER_THAN_ELSE
%nonassoc ONNOTHA
%left GT LT GEQ LEQ EQ NEQ
%left PLUS MINUS
%left MULT DIV MOD
%right UMINUS

%type <expr> expression function_call
%type <args> argument_list argument_list_opt argument
%type <stmt> statement declaration assignment print_stmt input_stmt return_stmt if_stmt loop_stmt block statement_list function_body
%type <stmt> numeric_declarator string_declarator char_declarator
%type <idlist> parameter_list parameter_list_opt
%type <top> global_item global_items function_definition

%%

program
    : PROSTABONA global_items UPOSHONGHAR
      {
          program_root = $2;

          if (semantic_errors == 0) {
              printf("Semantic Analysis Successful: program is meaningful.\n");

              optimize_program(program_root);
              generate_tac(program_root, "tac_output.txt");
              printf("Optimization complete: constant folding applied where possible.\n");
              printf("TAC generated in tac_output.txt\n");

              reset_history_log();
              interpret_program(program_root);
          } else {
              printf("Semantic Analysis finished with %d semantic error(s).\n", semantic_errors);
          }
      }
    ;

global_items
    : /* empty */
      {
          $$ = NULL;
      }
    | global_items global_item
      {
          $$ = append_top($1, $2);
      }
    ;

global_item
    : statement
      {
          $$ = make_top_stmt($1);
      }
    | function_definition
      {
          $$ = $1;
      }
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
          ASTIdentifierList *params = $5;
          set_current_function_body($7);
          $$ = make_top_func($2, params, $7);
          end_function_context();
      }
    ;

function_body
    : SHURU statement_list SHESH
      {
          $$ = make_block_stmt($2);
      }
    ;

parameter_list_opt
    : /* empty */
      {
          $$ = NULL;
      }
    | parameter_list
      {
          $$ = $1;
      }
    ;

parameter_list
    : IDENTIFIER
      {
          if (!add_parameter_to_current_function($1, TYPE_FLOAT)) {
              semantic_error("parameter redeclared");
          }
          $$ = make_identifier_list($1);
      }
    | parameter_list COMMA IDENTIFIER
      {
          if (!add_parameter_to_current_function($3, TYPE_FLOAT)) {
              semantic_error("parameter redeclared");
          }
          $$ = append_identifier($1, $3);
      }
    ;

block
    : SHURU statement_list SHESH
      {
          $$ = make_block_stmt($2);
      }
    ;

statement_list
    : /* empty */
      {
          $$ = NULL;
      }
    | statement_list statement
      {
          $$ = append_stmt($1, $2);
      }
    ;

statement
    : declaration SEMICOLON
      {
          $$ = $1;
      }
    | assignment SEMICOLON
      {
          $$ = $1;
      }
    | print_stmt SEMICOLON
      {
          $$ = $1;
      }
    | input_stmt SEMICOLON
      {
          $$ = $1;
      }
    | function_call SEMICOLON
      {
          $$ = make_expr_stmt($1.node);
      }
    | return_stmt SEMICOLON
      {
          $$ = $1;
      }
    | if_stmt
      {
          $$ = $1;
      }
    | loop_stmt
      {
          $$ = $1;
      }
    | block
      {
          $$ = $1;
      }
    ;

declaration
    : SHONKHYA
      {
          current_decl_type = TYPE_INT;
      }
      numeric_declarator
      {
          $$ = $3;
      }
    | PURNOSHONKHYA
      {
          current_decl_type = TYPE_FLOAT;
      }
      numeric_declarator
      {
          $$ = $3;
      }
    | BAKKYO string_declarator
      {
          $$ = $2;
      }
    | OKKHYOR char_declarator
      {
          $$ = $2;
      }
    ;

numeric_declarator
    : IDENTIFIER
      {
          if (!declare_variable($1, current_decl_type, SYM_VAR)) {
              semantic_error("variable redeclared in same scope");
          }
          $$ = make_decl_stmt(current_decl_type, $1, NULL);
      }
    | IDENTIFIER ASSIGN expression
      {
          if (!declare_variable($1, current_decl_type, SYM_VAR)) {
              semantic_error("variable redeclared in same scope");
          } else if (!can_assign(current_decl_type, $3.type)) {
              semantic_error("type mismatch in declaration assignment");
          }
          $$ = make_decl_stmt(current_decl_type, $1, $3.node);
      }
    | IDENTIFIER LBRACKET INT_LITERAL RBRACKET
      {
          if ($3 <= 0) {
              semantic_error("array size must be positive");
          } else if (!declare_array($1, current_decl_type, SYM_VAR, $3)) {
              semantic_error("array redeclared in same scope");
          }
          $$ = make_array_decl_stmt(current_decl_type, $1, $3);
      }
    ;

string_declarator
    : IDENTIFIER
      {
          if (!declare_variable($1, TYPE_STRING, SYM_VAR)) {
              semantic_error("variable redeclared in same scope");
          }
          $$ = make_decl_stmt(TYPE_STRING, $1, NULL);
      }
    | IDENTIFIER ASSIGN STRING_LITERAL
      {
          if (!declare_variable($1, TYPE_STRING, SYM_VAR)) {
              semantic_error("variable redeclared in same scope");
          }
          $$ = make_decl_string_stmt($1, $3);
      }
    | IDENTIFIER LBRACKET INT_LITERAL RBRACKET
      {
          if ($3 <= 0) {
              semantic_error("array size must be positive");
          } else if (!declare_array($1, TYPE_STRING, SYM_VAR, $3)) {
              semantic_error("array redeclared in same scope");
          }
          $$ = make_array_decl_stmt(TYPE_STRING, $1, $3);
      }
    ;

char_declarator
    : IDENTIFIER
      {
          if (!declare_variable($1, TYPE_CHAR, SYM_VAR)) {
              semantic_error("variable redeclared in same scope");
          }
          $$ = make_decl_stmt(TYPE_CHAR, $1, NULL);
      }
    | IDENTIFIER ASSIGN CHAR_LITERAL
      {
          if (!declare_variable($1, TYPE_CHAR, SYM_VAR)) {
              semantic_error("variable redeclared in same scope");
          }
          $$ = make_decl_char_stmt($1, $3);
      }
    | IDENTIFIER LBRACKET INT_LITERAL RBRACKET
      {
          if ($3 <= 0) {
              semantic_error("array size must be positive");
          } else if (!declare_array($1, TYPE_CHAR, SYM_VAR, $3)) {
              semantic_error("array redeclared in same scope");
          }
          $$ = make_array_decl_stmt(TYPE_CHAR, $1, $3);
      }
    ;

assignment
    : IDENTIFIER ASSIGN expression
      {
          Symbol *s = lookup_symbol($1);
          if (s == NULL) {
              semantic_error("assignment to undeclared variable");
          } else if (s->is_array) {
              semantic_error("array variable requires index for assignment");
          } else if (s->kind == SYM_CONST) {
              semantic_error("cannot modify constant");
          } else if (!can_assign(s->type, $3.type)) {
              semantic_error("type mismatch in assignment");
          }
          $$ = make_assign_expr_stmt($1, $3.node);
      }
    | IDENTIFIER ASSIGN STRING_LITERAL
      {
          Symbol *s = lookup_symbol($1);
          if (s == NULL) {
              semantic_error("assignment to undeclared variable");
          } else if (s->is_array) {
              semantic_error("array variable requires index for assignment");
          } else if (s->kind == SYM_CONST) {
              semantic_error("cannot modify constant");
          } else if (!can_assign(s->type, TYPE_STRING)) {
              semantic_error("type mismatch in assignment");
          }
          $$ = make_assign_string_stmt($1, $3);
      }
    | IDENTIFIER ASSIGN CHAR_LITERAL
      {
          Symbol *s = lookup_symbol($1);
          if (s == NULL) {
              semantic_error("assignment to undeclared variable");
          } else if (s->is_array) {
              semantic_error("array variable requires index for assignment");
          } else if (s->kind == SYM_CONST) {
              semantic_error("cannot modify constant");
          } else if (!can_assign(s->type, TYPE_CHAR)) {
              semantic_error("type mismatch in assignment");
          }
          $$ = make_assign_char_stmt($1, $3);
      }
    | IDENTIFIER LBRACKET expression RBRACKET ASSIGN expression
      {
          Symbol *s = lookup_symbol($1);
          if (s == NULL) {
              semantic_error("assignment to undeclared array");
          } else if (!s->is_array) {
              semantic_error("indexed assignment requires an array");
          } else if ($3.type != TYPE_INT && $3.type != TYPE_UNKNOWN) {
              semantic_error("array index must be integer");
          } else if (!can_assign(s->type, $6.type)) {
              semantic_error("type mismatch in array assignment");
          }
          $$ = make_array_assign_expr_stmt($1, $3.node, $6.node);
      }
    | IDENTIFIER LBRACKET expression RBRACKET ASSIGN STRING_LITERAL
      {
          Symbol *s = lookup_symbol($1);
          if (s == NULL) {
              semantic_error("assignment to undeclared array");
          } else if (!s->is_array) {
              semantic_error("indexed assignment requires an array");
          } else if ($3.type != TYPE_INT && $3.type != TYPE_UNKNOWN) {
              semantic_error("array index must be integer");
          } else if (!can_assign(s->type, TYPE_STRING)) {
              semantic_error("type mismatch in array assignment");
          }
          $$ = make_array_assign_string_stmt($1, $3.node, $6);
      }
    | IDENTIFIER LBRACKET expression RBRACKET ASSIGN CHAR_LITERAL
      {
          Symbol *s = lookup_symbol($1);
          if (s == NULL) {
              semantic_error("assignment to undeclared array");
          } else if (!s->is_array) {
              semantic_error("indexed assignment requires an array");
          } else if ($3.type != TYPE_INT && $3.type != TYPE_UNKNOWN) {
              semantic_error("array index must be integer");
          } else if (!can_assign(s->type, TYPE_CHAR)) {
              semantic_error("type mismatch in array assignment");
          }
          $$ = make_array_assign_char_stmt($1, $3.node, $6);
      }
    ;

print_stmt
    : SHOBDO expression
      {
          $$ = make_print_expr_stmt($2.node);
      }
    | SHOBDO STRING_LITERAL
      {
          $$ = make_print_string_stmt($2);
      }
    | SHOBDO CHAR_LITERAL
      {
          $$ = make_print_char_stmt($2);
      }
    ;

input_stmt
    : JOBDO IDENTIFIER
      {
          Symbol *s = lookup_symbol($2);
          if (s == NULL) {
              semantic_error("input target is undeclared");
          } else if (s->is_array) {
              semantic_error("array input requires index");
          }
          $$ = make_input_stmt($2);
      }
    | JOBDO IDENTIFIER LBRACKET expression RBRACKET
      {
          Symbol *s = lookup_symbol($2);
          if (s == NULL) {
              semantic_error("input target array is undeclared");
          } else if (!s->is_array) {
              semantic_error("indexed input requires an array");
          } else if ($4.type != TYPE_INT && $4.type != TYPE_UNKNOWN) {
              semantic_error("array index must be integer");
          }
          $$ = make_array_input_stmt($2, $4.node);
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
          $$ = make_return_expr_stmt($2.node);
      }
    | PHEROT STRING_LITERAL
      {
          if (!in_function_context()) {
              semantic_error("pherot used outside function");
          } else if (!register_return_type(TYPE_STRING)) {
              semantic_error("inconsistent function return type");
          }
          $$ = make_return_string_stmt($2);
      }
    | PHEROT CHAR_LITERAL
      {
          if (!in_function_context()) {
              semantic_error("pherot used outside function");
          } else if (!register_return_type(TYPE_CHAR)) {
              semantic_error("inconsistent function return type");
          }
          $$ = make_return_char_stmt($2);
      }
    ;

if_stmt
    : JODI LPAREN expression RPAREN statement %prec LOWER_THAN_ELSE
      {
          if (!is_numeric_type($3.type)) {
              semantic_error("if condition must be numeric/boolean-like");
          }
          $$ = make_if_stmt($3.node, $5, NULL);
      }
    | JODI LPAREN expression RPAREN statement ONNOTHA statement
      {
          if (!is_numeric_type($3.type)) {
              semantic_error("if condition must be numeric/boolean-like");
          }
          $$ = make_if_stmt($3.node, $5, $7);
      }
    ;

loop_stmt
    : CHOKRO LPAREN assignment SEMICOLON expression SEMICOLON assignment RPAREN statement
      {
          if (!is_numeric_type($5.type)) {
              semantic_error("loop condition must be numeric/boolean-like");
          }
          $$ = make_loop_stmt($3, $5.node, $7, $9);
      }
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
          $$.node = make_call_expr($1, $3.nodes);
      }
    ;

argument_list_opt
    : /* empty */
      {
          $$.count = 0;
          $$.nodes = NULL;
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
          if ($3.nodes != NULL) {
              if ($$.nodes == NULL) {
                  $$.nodes = $3.nodes;
              } else {
                  ASTArgList *cur = $$.nodes;
                  while (cur->next != NULL) cur = cur->next;
                  cur->next = $3.nodes;
              }
          }
      }
    ;

argument
    : expression
      {
          $$.count = 1;
          $$.types[0] = $1.type;
          $$.nodes = make_arg_list($1.node);
      }
    | STRING_LITERAL
      {
          $$.count = 1;
          $$.types[0] = TYPE_STRING;
          $$.nodes = make_arg_list(make_string_expr($1));
      }
    | CHAR_LITERAL
      {
          $$.count = 1;
          $$.types[0] = TYPE_CHAR;
          $$.nodes = make_arg_list(make_char_expr($1));
      }
    ;

expression
    : expression PLUS expression
      {
          DataType t = arithmetic_result_type($1.type, $3.type);
          if (t == TYPE_UNKNOWN) semantic_error("invalid operands for +");
          $$.type = t;
          $$.node = make_binary_expr(OP_ADD, $1.node, $3.node);
      }
    | expression MINUS expression
      {
          DataType t = arithmetic_result_type($1.type, $3.type);
          if (t == TYPE_UNKNOWN) semantic_error("invalid operands for -");
          $$.type = t;
          $$.node = make_binary_expr(OP_SUB, $1.node, $3.node);
      }
    | expression MULT expression
      {
          DataType t = arithmetic_result_type($1.type, $3.type);
          if (t == TYPE_UNKNOWN) semantic_error("invalid operands for *");
          $$.type = t;
          $$.node = make_binary_expr(OP_MUL, $1.node, $3.node);
      }
    | expression DIV expression
      {
          DataType t = arithmetic_result_type($1.type, $3.type);
          if (t == TYPE_UNKNOWN) semantic_error("invalid operands for /");
          $$.type = TYPE_FLOAT;
          $$.node = make_binary_expr(OP_DIV, $1.node, $3.node);
      }
    | expression MOD expression
      {
          if ($1.type != TYPE_INT || $3.type != TYPE_INT) {
              semantic_error("modulo requires integer operands");
              $$.type = TYPE_UNKNOWN;
          } else {
              $$.type = TYPE_INT;
          }
          $$.node = make_binary_expr(OP_MOD, $1.node, $3.node);
      }
    | expression GT expression
      {
          if (!is_numeric_type($1.type) || !is_numeric_type($3.type)) {
              semantic_error("comparison requires numeric operands");
          }
          $$.type = TYPE_INT;
          $$.node = make_binary_expr(OP_GT, $1.node, $3.node);
      }
    | expression LT expression
      {
          if (!is_numeric_type($1.type) || !is_numeric_type($3.type)) {
              semantic_error("comparison requires numeric operands");
          }
          $$.type = TYPE_INT;
          $$.node = make_binary_expr(OP_LT, $1.node, $3.node);
      }
    | expression GEQ expression
      {
          if (!is_numeric_type($1.type) || !is_numeric_type($3.type)) {
              semantic_error("comparison requires numeric operands");
          }
          $$.type = TYPE_INT;
          $$.node = make_binary_expr(OP_GEQ, $1.node, $3.node);
      }
    | expression LEQ expression
      {
          if (!is_numeric_type($1.type) || !is_numeric_type($3.type)) {
              semantic_error("comparison requires numeric operands");
          }
          $$.type = TYPE_INT;
          $$.node = make_binary_expr(OP_LEQ, $1.node, $3.node);
      }
    | expression EQ expression
      {
          if (!is_numeric_type($1.type) || !is_numeric_type($3.type)) {
              semantic_error("comparison requires numeric operands");
          }
          $$.type = TYPE_INT;
          $$.node = make_binary_expr(OP_EQ, $1.node, $3.node);
      }
    | expression NEQ expression
      {
          if (!is_numeric_type($1.type) || !is_numeric_type($3.type)) {
              semantic_error("comparison requires numeric operands");
          }
          $$.type = TYPE_INT;
          $$.node = make_binary_expr(OP_NEQ, $1.node, $3.node);
      }
    | MINUS expression %prec UMINUS
      {
          if (!is_numeric_type($2.type)) {
              semantic_error("unary minus requires numeric operand");
              $$.type = TYPE_UNKNOWN;
          } else {
              $$.type = $2.type;
          }
          $$.node = make_unary_expr(OP_NEG, $2.node);
      }
    | LPAREN expression RPAREN
      {
          $$.type = $2.type;
          $$.node = $2.node;
      }
    | SHAKTI LPAREN expression COMMA expression RPAREN
      {
          if (!is_numeric_type($3.type) || !is_numeric_type($5.type)) {
              semantic_error("shakti requires numeric arguments");
              $$.type = TYPE_UNKNOWN;
          } else {
              $$.type = TYPE_FLOAT;
          }
          $$.node = make_shakti_expr($3.node, $5.node);
      }
    | BORGOMUL LPAREN expression RPAREN
      {
          if (!is_numeric_type($3.type)) {
              semantic_error("borgomul requires numeric argument");
              $$.type = TYPE_UNKNOWN;
          } else {
              $$.type = TYPE_FLOAT;
          }
          $$.node = make_borgomul_expr($3.node);
      }
    | function_call
      {
          $$.type = $1.type;
          $$.node = $1.node;
      }
    | INT_LITERAL
      {
          $$.type = TYPE_INT;
          $$.node = make_int_expr($1);
      }
    | FLOAT_LITERAL
      {
          $$.type = TYPE_FLOAT;
          $$.node = make_float_expr($1);
      }
    | IDENTIFIER
      {
          Symbol *s = lookup_symbol($1);
          if (s == NULL) {
              semantic_error("use of undeclared variable");
              $$.type = TYPE_UNKNOWN;
          } else if (s->is_array) {
              semantic_error("array variable requires index");
              $$.type = TYPE_UNKNOWN;
          } else {
              $$.type = s->type;
          }
          $$.node = make_identifier_expr($1);
      }
    | IDENTIFIER LBRACKET expression RBRACKET
      {
          Symbol *s = lookup_symbol($1);
          if (s == NULL) {
              semantic_error("use of undeclared array");
              $$.type = TYPE_UNKNOWN;
          } else if (!s->is_array) {
              semantic_error("indexed access requires an array");
              $$.type = TYPE_UNKNOWN;
          } else if ($3.type != TYPE_INT && $3.type != TYPE_UNKNOWN) {
              semantic_error("array index must be integer");
              $$.type = TYPE_UNKNOWN;
          } else {
              $$.type = s->type;
          }
          $$.node = make_array_access_expr($1, $3.node);
      }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Syntax Error at line %d: %s\n", yylineno, s);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: natyo.exe <input_file>\n");
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if (!yyin) {
        perror("Could not open input file");
        return 1;
    }

    init_symbol_table();
    bootstrap_constants();

    printf("Starting syntax + semantic analysis...\n");
    yyparse();

    fclose(yyin);
    free_top_level(program_root);
    return 0;
}