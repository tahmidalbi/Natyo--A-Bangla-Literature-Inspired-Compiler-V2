%{
#include <stdio.h>
#include <stdlib.h>
#include "token_debug.h"

void print_token(const char *token_name, const char *lexeme);
%}

%option noyywrap
%option yylineno

LETTER      [A-Za-z_]
DIGIT       [0-9]
ID          {LETTER}({LETTER}|{DIGIT})*
INTNUM      {DIGIT}+
FLOATNUM    {DIGIT}+"."{DIGIT}+

%%

"prostabona"            { print_token("PROSTABONA", yytext); return TOK_PROSTABONA; }
"uposhonghar"           { print_token("UPOSHONGHAR", yytext); return TOK_UPOSHONGHAR; }
"drissho"               { print_token("DRISSHO", yytext); return TOK_DRISSHO; }
"shonkhya"              { print_token("SHONKHYA", yytext); return TOK_SHONKHYA; }
"purnoshonkhya"         { print_token("PURNOSHONKHYA", yytext); return TOK_PURNOSHONKHYA; }
"shobdo"                { print_token("SHOBDO", yytext); return TOK_SHOBDO; }
"jobdo"                 { print_token("JOBDO", yytext); return TOK_JOBDO; }
"jodi"                  { print_token("JODI", yytext); return TOK_JODI; }
"onnotha"               { print_token("ONNOTHA", yytext); return TOK_ONNOTHA; }
"chokro"                { print_token("CHOKRO", yytext); return TOK_CHOKRO; }
"shakti"                { print_token("SHAKTI", yytext); return TOK_SHAKTI; }
"borgomul"              { print_token("BORGOMUL", yytext); return TOK_BORGOMUL; }

"PAI"                   { print_token("IDENTIFIER", yytext); return TOK_IDENTIFIER; }
"E"                     { print_token("IDENTIFIER", yytext); return TOK_IDENTIFIER; }
"G"                     { print_token("IDENTIFIER", yytext); return TOK_IDENTIFIER; }

{FLOATNUM}              { print_token("FLOAT_LITERAL", yytext); return TOK_FLOAT_LITERAL; }
{INTNUM}                { print_token("INT_LITERAL", yytext); return TOK_INT_LITERAL; }

">="                    { print_token("GEQ", yytext); return TOK_GEQ; }
"<="                    { print_token("LEQ", yytext); return TOK_LEQ; }
"=="                    { print_token("EQ", yytext); return TOK_EQ; }
"!="                    { print_token("NEQ", yytext); return TOK_NEQ; }
">"                     { print_token("GT", yytext); return TOK_GT; }
"<"                     { print_token("LT", yytext); return TOK_LT; }
"="                     { print_token("ASSIGN", yytext); return TOK_ASSIGN; }
"+"                     { print_token("PLUS", yytext); return TOK_PLUS; }
"-"                     { print_token("MINUS", yytext); return TOK_MINUS; }
"*"                     { print_token("MULT", yytext); return TOK_MULT; }
"/"                     { print_token("DIV", yytext); return TOK_DIV; }
"%"                     { print_token("MOD", yytext); return TOK_MOD; }

";"                     { print_token("SEMICOLON", yytext); return TOK_SEMICOLON; }
","                     { print_token("COMMA", yytext); return TOK_COMMA; }
"("                     { print_token("LPAREN", yytext); return TOK_LPAREN; }
")"                     { print_token("RPAREN", yytext); return TOK_RPAREN; }
"{"                     { print_token("LBRACE", yytext); return TOK_LBRACE; }
"}"                     { print_token("RBRACE", yytext); return TOK_RBRACE; }

{ID}                    { print_token("IDENTIFIER", yytext); return TOK_IDENTIFIER; }

[ \t\r\n]+              { }

.                       {
                            printf("Lexical Error: Invalid token '%s' at line %d\n", yytext, yylineno);
                        }

%%

void print_token(const char *token_name, const char *lexeme) {
    printf("LINE %-3d TOKEN %-18s LEXEME %s\n", yylineno, token_name, lexeme);
}