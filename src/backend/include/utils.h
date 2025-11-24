#ifndef UTILS_H
#define UTILS_H

char *lineSep(char symbol, int length);
char *inputPrefix();
void eatBuffer();
void exitThanks(char clearScreen);

typedef struct {
    int code;
    char name[256];
    char names[100][256];
    int count;
} SearchResult;

SearchResult searchDir(char path[], char type[], int mode, char name[]);

void maskInput(char *destination, int maxSize);

int loadEnvFromFile(const char *path); //Helps in loading the env file
char *getEnvValue(const char *key);  // helps in retrieving value by key

#endif
