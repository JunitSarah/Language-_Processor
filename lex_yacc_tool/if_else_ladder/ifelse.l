ifelse.l
%{
#include "y.tab.h"
%}

%%
"if"        { return IF; }
"else"      { return ELSE; }
[0-9]+      { return NUM; }
[a-zA-Z]+   { return ID; }
[();]       { return yytext[0]; }
[ \t]       ;
\n          return 0;    // <<< THIS LINE ENDS INPUT
.           ;
%%
int yywrap(void) {
    return 1;
}
