#include <stdio.h>

struct IRInstruction {
    char op;
    int arg1;
    int arg2;
    int result;
};

void generateAssembly(struct IRInstruction *ir, int numInstructions) {
    printf("Generated Assembly Code:\n");
    int i;
    for (i = 0; i < numInstructions; i++) {
        switch (ir[i].op) {
            case '+':
                printf("ADD R%d, R%d, R%d\n", ir[i].result, ir[i].arg1, ir[i].arg2);
                break;
            case '-':
                printf("SUB R%d, R%d, R%d\n", ir[i].result, ir[i].arg1, ir[i].arg2);
                break;
            case '*':
                printf("MUL R%d, R%d, R%d\n", ir[i].result, ir[i].arg1, ir[i].arg2);
                break;
            case '/':
                printf("DIV R%d, R%d, R%d\n", ir[i].result, ir[i].arg1, ir[i].arg2);
                break;
            default:
                printf("Invalid operation\n");
                break;
        }
    }
}

int main() {
    struct IRInstruction ir[] = {
        {'+', 1, 2, 3},  // R3 = R1 + R2
        {'-', 4, 5, 6},  // R6 = R4 - R5
        {'*', 7, 8, 9},  // R9 = R7 * R8
        {'/', 10, 11, 12} // R12 = R10 / R11
    };
    int numInstructions = sizeof(ir) / sizeof(ir[0]);

    generateAssembly(ir, numInstructions);

    return 0;
}

