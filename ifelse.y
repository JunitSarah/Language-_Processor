%{
#include <stdio.h>
int yylex(void);
int yyerror(const char *s);
%}
%token IF ELSE ID NUM
%nonassoc IFX
%nonassoc ELSE
%%
start : stmt { printf("VALID.\n"); }
;
//possible statement rules
stmt : IF '(' cond ')' stmt %prec IFX  //if (A) a; gives more precednece to else
     | IF '(' cond ')' stmt ELSE stmt  //if (A) a; else y;
     | ID ';' //a;
     ;
//conditon can be no: or letter
cond : ID
     | NUM
     ;
%%
int main() {
   printf("JUNIT SARAH ROLL :54 \n");
   printf("Enter an if-else statement:\n");
   yyparse(); //parsing
   return 0;
}
int yyerror(const char *s) {
   printf("INVALID. \n");
   return 0;
}
