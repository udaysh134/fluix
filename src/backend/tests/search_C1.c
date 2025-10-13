#include <stdio.h>
#include <string.h>

#define MAX 1000
// Its the search function which can scan JASON file 

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
    const char *filename = "data.jason";
    const char *searchTerm = "New York";

    searchInFile(filename, searchTerm);

    return 0;
}