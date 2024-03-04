#include <stdio.h>
#include <string.h>

int isCommonSubexpression(char *str, int start1, int end1, int start2, int end2) {
    int len1 = end1 - start1 + 1;
    int len2 = end2 - start2 + 1;
    
    // Check if the lengths are equal
    if (len1 != len2) {
        return 0;
    }
    int i,j;
    for (i = start1, j = start2; i <= end1 && j <= end2; i++, j++) {
        if (str[i] != str[j]) {
            return 0;
        }
    }
    
    return 1;
}
void eliminateCommonSubexpressions(char *input) {
    int len = strlen(input);
    
    // Iterate through the input string
    int i,j,k;
    for (i = 0; i < len; i++) {
        for (j = i + 1; j < len; j++) {
            // Check for common subexpression
            if (isCommonSubexpression(input, i, j, j + 1, j + j - i)) {
                // Replace the common subexpression with a single occurrence
                for (k = j + 1; k <= j + j - i; k++) {
                    input[k] = ' ';
                }
            }
        }
    }
}

int main() {
    char input[100];

    printf("Enter the input expression: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline character if present
    input[strcspn(input, "\n")] = '\0';

    eliminateCommonSubexpressions(input);

    printf("Optimized expression: %s\n", input);

    return 0;
}

