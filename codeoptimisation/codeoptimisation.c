//codeoptimisation.c
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int isNumber(char str[]) {
    for(int i = 0; str[i] != '\0'; i++) {
        if(!isdigit(str[i]))
            return 0; }
    return 1;
}
int main() {
    int n;
    char lhs[10], op1[20], op2[20], operator;
    printf("Enter no: of expressions: ");
    scanf("%d", &n);
    /* arrays to store optimized output */
    char output[50][50];
    printf("\nEnter expressions (a = 5 + 3)\n");
    for(int i = 0; i < n; i++) {
        scanf("%s = %s %c %s", lhs, op1, &operator, op2);
        if(isNumber(op1) && isNumber(op2)) {
            int num1 = atoi(op1);
            int num2 = atoi(op2);
            int result;
            switch(operator) {
                case '+': result = num1 + num2; break;
                case '-': result = num1 - num2; break;
                case '*': result = num1 * num2; break;
                case '/': result = num1 / num2; break;
            }
            sprintf(output[i], "%s = %d", lhs, result);
        }
        else {
            sprintf(output[i],
                    "%s = %s %c %s",
                    lhs, op1, operator, op2);
        }    }
    /* Print separately after input */
    printf("\nOptimized Expressions:\n");
    for(int i = 0; i < n; i++) {
        printf("%s\n", output[i]);
    }
    return 0;
}
