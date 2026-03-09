//compiler.c
#include <stdio.h>
#include <string.h>
int main() {
    char tac[20];
    char result, op1, op2, operator;
    printf("Enter Three Address Code :  ");
    scanf("%s", tac);
    /*Format assumed: a=b+c
      0 1 2 3 4 */
    result = tac[0];
    op1 = tac[2];
    // Assignment only case (a=b)
    if(strlen(tac) == 3) {
        printf("\n8085 Assembly Code:\n");
        printf("MOV R1,%c\n", op1);
        printf("MOV %c,R1\n", result);
        return 0;
    }
    operator = tac[3];
    op2 = tac[4];
    printf("\n8085 Assembly Code:\n");
    // Load operands
    printf("MOV R1,%c\n", op1);
    printf("MOV R2,%c\n", op2);
    // Operation check
    switch(operator) {
        case '+':
            printf("ADD R1,R2\n");
            break;
        case '-':
            printf("SUB R1,R2\n");
            break;
        case '*':
            printf("MUL R1,R2\n");
            break;
        case '/':
            printf("DIV R1,R2\n");
            break;
        default:
            printf("Invalid\n");
            return 0;
    }   // Store result
    printf("MOV %c,R1\n", result);
    return 0;}
