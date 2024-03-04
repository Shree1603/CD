#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char filename[100];
    char ch;
    int charCount = 0, wordCount = 0, lineCount = 0;
    int inWord = 0; 
    printf("Enter the filename: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Unable to open the file.\n");
        exit(1);
    }
    while ((ch = fgetc(fp)) != EOF) {
        charCount++;
        if (!isspace(ch) && !inWord) {
            wordCount++;
            inWord = 1;
        }
        if (isspace(ch)) {
            inWord = 0;
        }
        if (ch == '\n') {
            lineCount++;
        }
    }
    if (inWord) {
        wordCount++;
    }
    fclose(fp);
    printf("Number of characters: %d\n", charCount);
    printf("Number of words: %d\n", wordCount);
    printf("Number of lines: %d\n", lineCount);

    return 0;
}

