#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}
int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}
int applyOperator(int a, char op, int b) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return (int)pow(a, b);
        default: return 0;
    }
}

int evaluate(char *expression) {
    int stack[100];
    char operatorStack[100];
    int top = -1;
    int opTop = -1;
    int i;
    for (i = 0; expression[i]; i++) {
        if (isdigit(expression[i])) {
            int num = 0;
            while (isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            i--;
            stack[++top] = num;
        } else if (isOperator(expression[i])) {
            while (opTop >= 0 && precedence(operatorStack[opTop]) >= precedence(expression[i])) {
                int b = stack[top--];
                int a = stack[top--];
                char op = operatorStack[opTop--];
                stack[++top] = applyOperator(a, op, b);
            }
            operatorStack[++opTop] = expression[i];
        } else if (expression[i] == '(') {
            operatorStack[++opTop] = expression[i];
        } else if (expression[i] == ')') {
            while (opTop >= 0 && operatorStack[opTop] != '(') {
                int b = stack[top--];
                int a = stack[top--];
                char op = operatorStack[opTop--];
                stack[++top] = applyOperator(a, op, b);
            }
            opTop--; // Discard the '('
        }
    }

    while (opTop >= 0) {
        int b = stack[top--];
        int a = stack[top--];
        char op = operatorStack[opTop--];
        stack[++top] = applyOperator(a, op, b);
    }

    return stack[top];
}

int main() {
    char expression[100];

    printf("Enter the infix expression: ");
    fgets(expression, sizeof(expression), stdin);

    int result = evaluate(expression);
    printf("Result: %d\n", result);

    return 0;
}

