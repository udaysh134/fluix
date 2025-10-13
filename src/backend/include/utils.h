#ifndef UTILS_H
#define UTILS_H

char *lineSep(char symbol, int length);
char *inputPrefix();
void eatBuffer();
void exitThanks(char clearScreen);
void searchDir(char path[], char type[], char nameToSearch[]);

#endif