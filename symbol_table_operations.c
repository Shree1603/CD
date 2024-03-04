#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

// Structure for symbol table entry
struct symbol {
    char name[20];
    int value;
};

// Hash table for symbol table
struct symbol *hashTable[SIZE];

// Function to calculate hash value
int hash(char *name) {
    int sum = 0;
    int i;
    for (i = 0; name[i] != '\0'; i++) {
        sum += name[i];
    }
    return sum % SIZE;
}

// Function to insert symbol into symbol table
void insert(char *name, int value) {
    int index = hash(name);
    struct symbol *newSymbol = (struct symbol *)malloc(sizeof(struct symbol));
    strcpy(newSymbol->name, name);
    newSymbol->value = value;
    hashTable[index] = newSymbol;
}

// Function to search for a symbol in the symbol table
struct symbol* search(char *name) {
    int index = hash(name);
    return hashTable[index];
}

// Function to delete a symbol from the symbol table
void delete(char *name) {
    int index = hash(name);
    free(hashTable[index]);
    hashTable[index] = NULL;
}

int main() {
    // Usage example
    insert("x", 10);
    insert("y", 20);
    
    struct symbol *result = search("x");
    if (result != NULL) {
        printf("Value of x: %d\n", result->value);
    } else {
        printf("Symbol not found\n");
    }

    delete("x");

    return 0;
}

