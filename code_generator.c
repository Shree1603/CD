#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct ThreeAddressCode {
    char op; // Operation (+, -, *, /)
    char arg1[10]; // Argument 1
    char arg2[10]; // Argument 2
    char result[10]; // Result
};
void generateThreeAddressCode(char *expression, struct ThreeAddressCode *code) {
    int codeIndex = 0;
    char stack[100][10];
    int top = -1;
    int i;
    for ( i = 0; expression[i]; i++) {
        if (isalnum(expression[i])) {
            int j = 0;
            while (isalnum(expression[i])) {
                stack[++top][j++] = expression[i++];
            }
            stack[top][j] = '\0';
            i--; 
        }
        else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            strcpy(code[codeIndex].arg2, stack[top--]);
            strcpy(code[codeIndex].arg1, stack[top--]);
            code[codeIndex].op = expression[i];
            sprintf(code[codeIndex].result, "t%d", codeIndex + 1);
            strcpy(stack[++top], code[codeIndex].result);
            codeIndex++;
        }
    }

    strcpy(code[codeIndex].arg2, stack[top--]);
    strcpy(code[codeIndex].arg1, stack[top--]);
    code[codeIndex].op = expression[strlen(expression) - 1];
    strcpy(code[codeIndex].result, "Result");
    codeIndex++;
    printf("Three Address Code:\n");
    for (i = 0; i < codeIndex; i++) {
        printf("%s = %s %c %s\n", code[i].result, code[i].arg1, code[i].op, code[i].arg2);
    }
}

int main() {
    char expression[100];
    struct ThreeAddressCode code[100];

    printf("Enter the infix expression: ");
    fgets(expression, sizeof(expression), stdin);

    generateThreeAddressCode(expression, code);

    return 0;
}

