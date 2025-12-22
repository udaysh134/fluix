#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>
#include <stddef.h>

char *lineSep(char symbol, int length);
char *inputPrefix(void);
void eatBuffer(void);
void exitThanks(char clearScreen);

typedef struct {
    int code;
    char name[256];
    char names[100][256];
    int count;
} SearchResult;

SearchResult searchDir(char path[], char type[], int mode, char name[]);

void maskInput(char *destination, int maxSize);
char *parseEnv(const char *file, const char *key);
int deleteDir(const char *folder);
int isStrClean(char *input);
uint64_t getEpochTime(void);
void genRand(char *str, size_t length);
void strToHex(const char *input, char *out);
char *readJSON(const char *filename);

#endif