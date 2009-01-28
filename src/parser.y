%{
#include <stdio.h>
#include <string.h>

extern int line_number;

void yyerror(const char *str)
{
  fprintf(stderr, "Error (line: %d): %s\n", line_number, str);
}

int yywrap()
{
  return 1;
} 

%}

%token CLASS
%token MODULE
%token SELF
%token SUPER
%token BUBBLE
%token METHOD
%token IF
%token UNLESS
%token WHEN
%token FOR
%token NUMBER
%token CONSTANT
%token VARIABLE
%token LAMBDA
%token PUTS

%left ';'
%left PUTS
%left '-' '+'
%left '*' '/'

%start expression

%%

expression: /* empty */
  | NUMBER                               { $$ = $1; }
  | expression ';' expression            { $$ = $3; }
  | arithmetic
  | PUTS expression                      { printf("%d\n", $2); $$ = $2; }
  | '(' expression ')'                   { $$ = $2; }
  ;

arithmetic:
  expression '*' expression              { $$ = $1 * $3; }
  | expression '/' expression            { $$ = $1 / $3; }
  | expression '+' expression            { $$ = $1 + $3; }
  | expression '-' expression            { $$ = $1 - $3; }
  ;

// block:
//   "{" expression "}"                     { $$ = $2; };
