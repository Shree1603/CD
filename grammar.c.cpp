#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool checkGrammar(char *input) {
    int len = strlen(input);
    if (len == 0) return false; 
    if (len < 9 || input[0] != 'I' || strncmp(input + 1, " am", 3) != 0 || strncmp(input + len - 9, "a student.", 9) != 0)
        return false;
    for (int i = 4; i < len - 9; i++) {
        if (!(input[i] == ' ' || (input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z')))
            return false;
    }

    return true;
}

int main() {
    char input[100];

    printf("Enter a sentence: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    if (checkGrammar(input)) {
        printf("The sentence satisfies the grammar.\n");
    } else {
        printf("The sentence does not satisfy the grammar.\n");
    }

    return 0;
}

