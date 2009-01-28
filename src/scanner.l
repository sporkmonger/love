%{
#include <stdlib.h>
#include <stdio.h>
#include "parser.h"

int line_number = 1;
%}

whitespace [ \t]+
digit [0-9]
number ({digit}+|{digit}+\.{digit}*|{digit}*\.{digit}+)([Ee][+\-]?{digit}+)?
letter [a-zA-Z]
constant [A-Z][a-zA-Z0-9_]*
variable [a-z][a-z0-9_]*

%%
"class"              return CLASS;
"module"             return MODULE;
"self"               return SELF;
"super"              return SUPER;
"bubble"             return BUBBLE;
"def"                return METHOD;
"if"                 return IF;
"when"               return WHEN;
"for"                return FOR;
"puts"               return PUTS;
"->"                 return LAMBDA;
{number}             { yylval=atoi(yytext); return NUMBER; }
\n                   { line_number++; }
[ \t]+               /* ignore whitespace */;
"+"                  return '+';
"-"                  return '-';
"*"                  return '*';
"/"                  return '/';
";"                  return ';';
"("                  return '(';
")"                  return ')';
"["                  return '[';
"]"                  return ']';
"{"                  return '{';
"}"                  return '}';

%%

/*{constant}           {
  yylval.id = (char *)strdup(yytext);
  return CONSTANT;
}
{variable}           {
  yylval.id = (char *)strdup(yytext);
  return VARIABLE;
}
*/
