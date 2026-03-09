#include <stdio.h>
#include <string.h>
#include <ctype.h>
char stack[100];
int top = -1;
void push(char x) {
    stack[++top] = x;
}
char pop() {
    return stack[top--];
}
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}
int main() {
    char infix[100], postfix[100];
    int i, j = 0;
    printf("Enter  Expression: ");
    scanf("%s", infix);
    //  INFIX TO POSTFIX 
    for (i = 0; i < strlen(infix); i++) {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        }
        else if (infix[i] == '(') {
            push(infix[i]);
        }
        else if (infix[i] == ')') {
            while (stack[top] != '(')
                postfix[j++] = pop();
            pop();
        }
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i]))
                postfix[j++] = pop();
            push(infix[i]);
        }
    }
    while (top != -1)
        postfix[j++] = pop();
    postfix[j] = '\0';
    // GENERATE THREE ADDRESS CODE 
    printf("\nThree Address Code:\n");
    char tempStack[100][10];
    int tTop = -1;
    int tempCount = 1;
    for (i = 0; i < strlen(postfix); i++) {
        if (isalnum(postfix[i])) {
            char operand[2] = {postfix[i], '\0'};
            strcpy(tempStack[++tTop], operand);
        }
        else {
            char op2[10], op1[10];
            strcpy(op2, tempStack[tTop--]);
            strcpy(op1, tempStack[tTop--]);
            char tempVar[10];
            sprintf(tempVar, "t%d", tempCount++);

            printf("%s = %s %c %s\n", tempVar, op1, postfix[i], op2);
            strcpy(tempStack[++tTop], tempVar);
        }
    }
    return 0;
}
