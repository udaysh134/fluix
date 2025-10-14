#include <stdio.h>
#include <string.h>

#define MAX 1000

void searchInFile(const char *filename, const char *searchTerm) {
    FILE *file = fopen(filename, "r");
    char line[MAX];

    if (!file) {
        printf("Error opening file.\n");
        return;
    }

    while (fgets(line, MAX, file)) {
        if (strstr(line, searchTerm)) {
            printf("Found: %s", line);
        }
    }

    fclose(file);
}

int main() {
    const char *filename = "data.json";  // Fixed file name
    char searchTerm[MAX];

    printf("Enter the term/word to be searche : ");
    if (fgets(searchTerm, MAX, stdin)) {
        searchTerm[strcspn(searchTerm, "\n")] = 0; // Remove trailing newline
        searchInFile(filename, searchTerm);
    } else {
        printf("Error reading input.\n");
    }

    return 0;
}
