%{
#include <stdio.h>
#include <stdlib.h>
int yylex(void);
int yyerror(const char *s);
%}
%token NUM
%left '+' '-'
%left '*' '/'
%%
input
    : input line
    |
    ;
line
    : expr '\n' { printf("Result = %d\n", $1 ); exit(0); }
    ;
expr
    : expr '+' expr { $$ = $1 + $3; }
    | expr '-' expr { $$ = $1 - $3; }
    | expr '*' expr { $$ = $1 * $3; }
    | expr '/' expr { $$ = $1 / $3; }
    | '(' expr ')'  { $$ = $2; }
    | NUM           { $$ = $1; }
    ;
%%
int main() {
    printf("JUNIT SARAH ROLL :54 \n");
    printf("CALCULATOR\n");
    printf("Enter expression:\n");
    yyparse();
    return 0;
}
int yyerror(const char *s) {
    printf("SYNTAX ERROR\n");
    return 0;
}


