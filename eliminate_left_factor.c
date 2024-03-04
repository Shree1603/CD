#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PROD 10
#define MAX_LEN 20

int isPrefix(char *str1, char *str2) {
    while (*str1 && *str2 && *str1 == *str2) {
        str1++;
        str2++;
    }
    return (*str1 == '\0');
}

void eliminateLeftFactoring(char production[MAX_PROD][MAX_LEN], int n) {
    int i, j, k, l;
    char common[MAX_LEN];

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            for (k = 0, l = 0; production[i][k] && production[j][k]; k++) {
                if (production[i][k] == production[j][k]) {
                    common[l++] = production[i][k];
                } else {
                    break;
                }
            }
            common[l] = '\0';

            if (common[0] != '\0') {
                printf("\nCommon prefix found: %s\n", common);
                printf("After left factoring:\n");
                printf("A' -> %s\n", common);
                printf("A -> ");
                printf("%s | ", &production[i][k]);
                printf("%s\n", &production[j][k]);
                strcpy(production[i], "A'");
                strcpy(production[j], "A'");
            }
        }
    }
}

int main() {
    int n, i;
    char production[MAX_PROD][MAX_LEN];

    printf("Enter the number of productions: ");
    scanf("%d", &n);
    printf("Enter the productions:\n");
    for (i = 0; i < n; i++) {
        scanf("%s", production[i]);
    }

    eliminateLeftFactoring(production, n);

    return 0;
}

