// Headers
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

#include "../include/utils.h"
#include "../include/colors.h"


/*
----------------------------------------------------------------------------------------------------
1. LINE SEPARATOR FUNCTION
----------------------------------------------------------------------------------------------------
*/
char *lineSep(char symbol, int length) {
    char *res = malloc(length + 1);  
    if (res == NULL) return NULL;

    for (int i = 0; i < length; i++) {
        res[i] = symbol;
    }

    res[length] = '\0';
    return res;
}


/*
----------------------------------------------------------------------------------------------------
2. GLOBAL PREFIX FUNCTION
----------------------------------------------------------------------------------------------------
*/
char *inputPrefix() {
    return CMD_COL_YELLOW ">> " CMD_COL_RESET;
}


/*
----------------------------------------------------------------------------------------------------
3. BUFFER CONSUMING FUNCTION
----------------------------------------------------------------------------------------------------
*/
void eatBuffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {}
}


/*
----------------------------------------------------------------------------------------------------
4. EXIT THANKING FUNCTION
----------------------------------------------------------------------------------------------------
*/
void exitThanks(char clearScreen) {    
    char clScreen = tolower(clearScreen);

    if (clScreen == 'n') {
        printf("%sThank you!\nHave a good day!%s", CMD_COL_GREEN, CMD_COL_RESET);
    } else if (clScreen == 'y') {
        system("cls");
        printf("%sThank you!\nHave a good day!%s", CMD_COL_GREEN, CMD_COL_RESET);
    } else {
        printf("%sExiting with a internal error!\nFix parameter declaration(s) of function 4.%s", CMD_COL_RED, CMD_COL_RESET);
        exit(0);
    }
}


/*
----------------------------------------------------------------------------------------------------
5. DIRECTORY SEARCH FUNCTION
----------------------------------------------------------------------------------------------------
*/
SearchResult searchDir(char path[], char type[], char name[]) {
    SearchResult result = {0};

    char srchPath[MAX_PATH];
    snprintf(srchPath, sizeof(srchPath), "%s\\*", path);

    WIN32_FIND_DATA findData;
    HANDLE hFind = FindFirstFile(srchPath, &findData);

    if (hFind == INVALID_HANDLE_VALUE) {
        result.code = 2; // Unable to open directory
        return result;
    }

    int found = 0;

    do {
        if (strcmp(findData.cFileName, ".") == 0 || strcmp(findData.cFileName, "..") == 0) continue;

        int isFolder = (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY);

        if (strcmp(type, "folder") == 0 && isFolder) {
            if (strcmp(findData.cFileName, name) == 0) {
                strcpy(result.name, findData.cFileName);
                result.code = 0; // Success
                found = 1;
                break;
            }
        } else if (strcmp(type, "file") == 0 && !isFolder) {
            if (strcmp(findData.cFileName, name) == 0) {
                strcpy(result.name, findData.cFileName);
                result.code = 0; // Success
                found = 1;
                break;
            }
        }
    } while (FindNextFile(hFind, &findData));

    FindClose(hFind);

    if (!found) result.code = 1; // Directory not found

    return result;
}


/*
----------------------------------------------------------------------------------------------------
6. INPUT TEXT MASKING FUNCTION
----------------------------------------------------------------------------------------------------
*/
void maskInput(char *destination, int maxSize) {
    int i = 0;
    char ch;

    while (1) {
        ch = getch(); // Reads character without display

        if (ch == 13) { // ASCII for "Enter" key
            destination[i] = '\0';
            printf("\n");
            break;
        } else if (ch == 8) { // ASCII for "Backspace" key
            if (i > 0) {
                i--;
                printf("\b \b"); // Removes last input
            }
        } else if (i < maxSize - 1) {
            destination[i++] = ch;
            printf("*"); // Print astrisk in place of given input
        }
    }
}