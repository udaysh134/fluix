// Headers
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
#include <string.h>

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
void searchDir(char path[], char type[], char name[]) {
    char srchPath[MAX_PATH];
    snprintf(srchPath, sizeof(srchPath), "%s\\*", path);

    WIN32_FIND_DATA findData;
    HANDLE hFind = FindFirstFile(srchPath, &findData);

    if (hFind == INVALID_HANDLE_VALUE) {
        printf("Unable to open directory: %s\n", path);
        return;
    }

    int found = 0;

    do {
        // Skip current and parent directory entries
        if (strcmp(findData.cFileName, ".") == 0 || strcmp(findData.cFileName, "..") == 0) continue;

        int isFolder = (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY);

        if (strcmp(type, "folder") == 0 && isFolder) { // To search a folder
            if (strcmp(findData.cFileName, name) == 0) {
                printf("Found folder: %s\\%s\n", path, name);
                found = 1;
                break;
            }
        } else if (strcmp(type, "file") == 0 && !isFolder) { // To search a file
            if (strcmp(findData.cFileName, name) == 0) {
                printf("Found file: %s\\%s\n", path, name);
                found = 1;
                break;
            }
        }
    } while (FindNextFile(hFind, &findData));

    FindClose(hFind);

    if (!found) {
        const char *placeholder = strcmp(type, "folder") == 0 ? "Folder" : "File";
        printf("%s '%s' not found in %s\n", placeholder, name, path);
    }
}