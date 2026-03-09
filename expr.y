%{
#include <stdio.h>
#include <stdlib.h>
int yylex();
int yyerror(char *s);
%}
%token NUM
%left '+' '-'
%left '*' '/'
%%
S : E '\n' { printf("Result = %d\n", $1);  printf("VALID EXPRESSIONn"); exit(0); }
  ;
E : E '+' E   { $$ = $1 + $3; }
  | E '-' E   { $$ = $1 - $3; }
  | E '*' E   { $$ = $1 * $3; }
  | E '/' E   { $$ = $1 / $3; }
  | '(' E ')' { $$ = $2; }
  | NUM       { $$ = $1; }
  ;
%%
int main()
{   printf("JUNIT SARAH ROLL :54 \n");
    printf("Enter expression: ");
    yyparse();
    return 0; }
int yyerror(char *s)
{   printf("INVALID EXPRESSION.\n");
    return 0; }
