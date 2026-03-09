#include <stdio.h>
#include <ctype.h>
#include <string.h>

int is_keyword(char *word) {
    char keywords[][10] = {
        "int", "float", "return", "if", "else",
        "while", "for", "char"
    };
    for (int i = 0; i < 8; i++)
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    return 0;
}

int main() {
    printf("JUNIT SARAH  ROLL NO: 54\n");

    FILE *fp = fopen("input.c", "r");
    if (!fp) return 1;

    int state = 0;
    int ch;
    char buffer[100];
    int bi = 0;
   
    char symbol_table[100][100];
    int sym_count = 0;
    while ((ch = fgetc(fp)) != EOF) {

        switch (state) {

        // intial state
        case 0:
            if (isspace(ch))
             break;
   
            if (ch == '<') state = 1;
            else if (ch == '>') state = 4;
            else if (ch == '!') state = 7;
            else if (ch == '=') state = 10;
            else if (ch == '+') state = 13;
            else if (ch == '-') state = 14;
            else if (ch == '*') state = 15;
            else if (ch == '/') state = 16;
            else if (ch == '&') state = 17;
            else if (ch == '|') state = 19;

            else if (isdigit(ch)) {
                bi = 0;
                buffer[bi++] = ch;
                state = 21;
            }
            else if (isalpha(ch) || ch == '_') {
                bi = 0;
                buffer[bi++] = ch;
                state = 22;
            }
            else {
                printf("%c - SPECIAL CHARACTER\n", ch);
            }
            break;

        // <= OR <
        case 1:
            if (ch == '=') state = 2;
            else {
                state = 3;
                ungetc(ch, fp);
            }
            break;

        case 2:
            printf("<= - RELATIONAL, LE\n");
            state = 0;
            break;

        case 3:
            printf("< - RELATIONAL, LT\n");
            state = 0;
            break;

        // >= OR >
        case 4:
            if (ch == '=') state = 5;
            else {
                state = 6;
                ungetc(ch, fp);
            }
            break;

        case 5:
            printf(">= - RELATIONAL, GE\n");
            state = 0;
            break;

        case 6:
            printf("> - RELATIONAL, GT\n");
            state = 0;
            break;

        // ! OR !=
        case 7:
            if (ch == '=') state = 8;
            else {
                state = 9;
                ungetc(ch, fp);
            }
            break;

        case 8:
            printf("!= - RELATIONAL, NE\n");
            state = 0;
            break;

        case 9:
            printf("! - LOGICAL, NOT\n");
            state = 0;
            break;

        // == OR =
        case 10:
            if (ch == '=') state = 11;
            else {
                state = 12;
                ungetc(ch, fp);
            }
            break;

        case 11:
            printf("== - RELATIONAL, EQ\n");
            state = 0;
            break;

        case 12:
            printf("= - ASSIGNMENT, ASSIGN\n");
            state = 0;
            break;

        // arithemtic
        case 13:
            printf("+ - ARITHMETIC, ADD\n");
            state = 0;
            break;

        case 14:
            printf("- - ARITHMETIC, SUB\n");
            state = 0;
            break;

        case 15:
            printf("* - ARITHMETIC, MUL\n");
            state = 0;
            break;

        case 16:
            printf("/ - ,ARITHMETIC, DIV\n");
            state = 0;
            break;

        // && OR &
        case 17:
            if (ch == '&') state = 18;
            else {
                printf("& - SPECIAL CHARACTER\n");
                ungetc(ch, fp);
                state = 0;
            }
            break;

        case 18:
            printf("&& - LOGICAL, AND\n");
            state = 0;
            break;

        // || OR |
        case 19:
            if (ch == '|') state = 20;
            else {
                printf("| - SPECIAL CHARACTER\n");
                ungetc(ch, fp);
                state = 0;
            }
            break;

        case 20:
            printf("|| - LOGICAL, OR\n");
            state = 0;
            break;

        // constant values
        case 21:
            if (isdigit(ch)) {
                buffer[bi++] = ch;
            } else {
                buffer[bi] = '\0';
                printf("%s - CONSTANT\n", buffer);
                ungetc(ch, fp);
                state = 0;
            }
            break;

        // identifier or keyword
  case 22:
if (isalnum(ch) || ch == '_') {
    buffer[bi++] = ch;
} else {
  buffer[bi] = '\0';

if (is_keyword(buffer)) {
 printf("%s - KEYWORD\n", buffer);
} else {
 int found = -1;
          for (int i = 0; i < sym_count; i++) {
   if (strcmp(buffer, symbol_table[i]) == 0) {
found = i;
       break;
            }
          }
 if (found != -1) {
            printf("%s - IDENTIFIER, #%d\n", buffer, found);
          } else {
    strcpy(symbol_table[sym_count], buffer);
             printf("%s - IDENTIFIER, #%d\n", buffer, sym_count);
    sym_count++;
          }
      }

      ungetc(ch, fp);
      state = 0;
     }
     break;
        }
    }
   
    printf("\n\n");
    printf("SYMBOL TABLE\n");
    printf("IDENTIFIER\tINDEX\n");
    for(int i = 0 ; i < sym_count ; i++) {
   printf("%s\t\t#%d\n", symbol_table[i], i);
    }

    fclose(fp);
    return 0;
}
