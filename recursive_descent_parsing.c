#include <stdio.h>
#include <ctype.h>

char input[100];
int pos = 0;

// Function to match a terminal symbol 'a'
int match(char c) {
    if (input[pos] == c) {
        pos++;
        return 1;
    } else {
        return 0;
    }
}

// Function to parse the non-terminal 'S'
void S() {
    if (match('a')) {
        S();
        if (!match('b')) {
            printf("Error: Expected 'b' after 'a'\n");
            return;
        }
    } else {
        printf("Error: Expected 'a'\n");
        return;
    }
}

int main() {
    printf("Enter input string: ");
    scanf("%s", input);

    S();

    if (input[pos] == '\0') {
        printf("Parsing successful\n");
    } else {
        printf("Parsing unsuccessful\n");
    }

    return 0;
}

