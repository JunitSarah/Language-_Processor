expr.l
%{
#include "y.tab.h"
#include <stdlib.h>
%}
%%
[0-9]+      { yylval = atoi(yytext); return NUM; }
[ \t]       ;   /* ignore spaces */
\n           return '\n';
.            return yytext[0];
%%
int yywrap()
{    return 1;
}
