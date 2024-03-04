#include <stdio.h>
#include <string.h>

int main() {
    char production[10][10], non_terminal;
    int i, j, n;

    printf("Enter the number of productions: ");
    scanf("%d", &n);

    printf("Enter the productions:\n");
    for (i = 0; i < n; i++)
        scanf("%s", production[i]);

    printf("Enter the non-terminal to eliminate left recursion: ");
    scanf(" %c", &non_terminal);

    for (i = 0; i < n; i++) {
        if (production[i][0] == non_terminal) {
            char alpha[10][10], beta[10][10];
            int alpha_count = 0, beta_count = 0;

            for (j = 3; j < strlen(production[i]); j++) {
                if (production[i][j] == '|') {
                    beta[beta_count][0] = '\0';
                    beta_count = 0;
                    continue;
                }

                if (production[i][j] == non_terminal) {
                    strcpy(alpha[alpha_count++], &production[i][j + 1]);
                } else {
                    strcpy(beta[beta_count++], &production[i][j]);
                }
            }

            printf("%c->", non_terminal);
            for (j = 0; j < beta_count; j++)
                printf("%s%c'|'", beta[j], non_terminal);

            printf("\n%c'->", non_terminal);
            for (j = 0; j < alpha_count; j++)
                printf("%s%c'|'", alpha[j], non_terminal);
        } else {
            printf("%s\n", production[i]);
        }
    }

    return 0;
}
