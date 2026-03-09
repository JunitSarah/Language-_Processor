#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char input[100];
int i = 0;
// Function declarations
void S();
void S1();
void A();
void A1();
void B();
void error() {
    printf("REJECTED.\n");
    exit(1);
}
void match(char t) {
    if (input[i] == t)
        i++;
    else
        error();
}
// S → aS' | b
void S() {
    if (input[i] == 'a') {
        match('a');
        S1();
    }
    else if (input[i] == 'b') {
        match('b');
    }
    else {
        error();
    }
}
// S' → Ad | B
void S1() {
    if (input[i] == 'a') {
        A();
        match('d');
    }
    else if (input[i] == 'c' || input[i] == 'd') {
        B();
    }
    else {
        error();
    }
}
// A → aA' | ac
void A() {
    if (input[i] == 'a') {
        match('a');
        if (input[i] == 'b') {
            A1();
        }
        else if (input[i] == 'c') {
            match('c');
        }
        else {
            error();
        }
    }
    else {
        error();
    }
}
// A' → b | ε
void A1() {
    if (input[i] == 'b') {
        match('b');
    }// E do nothing
}
// B → ccd | ddc
void B() {
    if (input[i] == 'c') {
        match('c');
        match('c');
        match('d');
    }
    else if (input[i] == 'd') {
        match('d');
        match('d');
        match('c');
    }
    else {
        error();
    }
}
int main() {
printf("JUNIT SARAH ROLL :54 \n");
    printf("Enter input string: ");
    scanf("%s", input);
    S();
    if (input[i] == '\0')
        printf("STRING ACCEPTED\n");
    else
        printf("REJECTED!.\n");
    return 0;}
