#ifndef UTILS_H
#define UTILS_H

char *lineSep(char symbol, int length);
char *inputPrefix();
void eatBuffer();
void exitThanks(char clearScreen);

typedef struct {
    int code;
    char name[256];
} SearchResult;

SearchResult searchDir(char path[], char type[], char name[]);

void maskInput(char *destination, int maxSize);

#endif