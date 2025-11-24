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
/**
 * 1. "path" - Relative path of the desired directory, like ".\\src\\db".
 * 2. "type" - Select if it is a "file" or a "folder".
 * 3. "mode" - Integer value of "0" or "1" (0 is "Target Mode", 1 is "List Mode").
 * 4. "name" - Required if mode is 0, or leave it blank like (""). Any name is ignored by default.
 */
SearchResult searchDir(char path[], char type[], int mode, char name[]) {
    SearchResult result = {0};

    if (mode != 0 && mode != 1) {
        result.code = 3; // Mode not defined correctly
        return result;
    }

    char srchPath[MAX_PATH];
    snprintf(srchPath, sizeof(srchPath), "%s\\*", path);

    WIN32_FIND_DATA findData;
    HANDLE hFind = FindFirstFile(srchPath, &findData);

    if (hFind == INVALID_HANDLE_VALUE) {
        result.code = 2; // Unable to open directory
        return result;
    }

    // ------=>> | [MODE 0] - Target Mode (Search a specific file/folder with name) | <<=------
    if (mode == 0) {
        int found = 0;

        do {
            if (strcmp(findData.cFileName, ".") == 0 || strcmp(findData.cFileName, "..") == 0) continue;

            int isFolder = (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY);

            if ((strcmp(type, "folder") == 0 && isFolder) || (strcmp(type, "file") == 0 && !isFolder)) {
                if (strcmp(findData.cFileName, name) == 0) {
                    strcpy(result.name, findData.cFileName);
                    result.code = 0; // Success
                    found = 1;
                    break;
                }
            }
        } while (FindNextFile(hFind, &findData));

        if (!found) result.code = 1; // Directory not found
    }

    // ------=>> | [MODE 1] - List Mode (Search all files/folders in that path) | <<=------
    else if (mode == 1) {
        do {
            if (strcmp(findData.cFileName, ".") == 0 || strcmp(findData.cFileName, "..") == 0) continue;

            int isFolder = (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY);

            if ((strcmp(type, "folder") == 0 && isFolder) || (strcmp(type, "file") == 0 && !isFolder)) {
                strcpy(result.names[result.count++], findData.cFileName);
            }
        } while (FindNextFile(hFind, &findData));


        if (result.count > 0) {
            result.code = 0; // Success
        } else {
            result.code = 1; // Directory not found
        }
    }

    FindClose(hFind);
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
            printf("%s*%s", CMD_COL_BLACK, CMD_COL_RESET); // Print astrisk in place of given input
        }
    }
}



/*
 ----------------------------------------------------------------------------------------------------
 7. ENV PARSER FUNCTIONS
 ----------------------------------------------------------------------------------------------------
*/

/*----------------------NOTE--------------------------------------*/

/* 
The following parser was tested under custom conditions and have possible bugs.
The code was tweaked with help of GPT and Gemini AI assistants.
Code might need further optimizations and might not be 100% upto the mark.
Trying to understand the parsing a bit better and will rework on it 
------------------END OF NOTE----------------------*/
/* remove this  comment line initiator and the closer on line no. 278 to make code functionable
// Structure for key&value pair: This will help us store env variables
typedef struct {
    char key[50];
    char value[200];
} EnvPair;

// Storage for parsed values: 20 pairs max
static EnvPair env[20]; // Array to hold env key-value pairs
static int envCount = 0; // Number of loaded env variables


// Trim spaces around a string
static char *trim(char *str) {
    while (isspace((unsigned char)*str)) str++; // trim leading spaces
    char *end = str + strlen(str) - 1;  // point to last character
    while (end > str && isspace((unsigned char)*end)) *end-- = '\0'; // trim trailing spaces
    return str; // return trimmed string
}


// Remove surrounding quotes
static char *removeQuotes(char *str) { // Remove surrounding quotes if present
    int len = strlen(str);
    if (len >= 2 &&
       ((str[0] == '"' && str[len-1] == '"') ||
        (str[0] == '\'' && str[len-1] == '\''))) {
        str[len-1] = '\0';
        return str + 1; // return string without quotes
    }
    return str; // return original string
}


// Load .env-style file
int loadEnvFromFile(const char *path) {
    FILE *fp = fopen(path, "r");
    if (!fp) {
        return 0; // failed to open file
    }

    char line[256];  // buffer for each line

    while (fgets(line, sizeof(line), fp)) {   // read line by line
        char *ln = trim(line);  // trim spaces

        if (ln[0] == '\0' || ln[0] == '#')  // skip empty lines and comments
            continue;

        char *eq = strchr(ln, '=');
        if (!eq)
            continue;   // skip lines without '='

        *eq = '\0';
        char *key = trim(ln);
        char *val = trim(eq + 1);

        val = removeQuotes(val);  // remove surrounding quotes

        // prevent overflow / too many entries
        if (envCount < (int)(sizeof(env) / sizeof(env[0]))) {
            strncpy(env[envCount].key, key, sizeof(env[envCount].key) - 1);
            env[envCount].key[sizeof(env[envCount].key) - 1] = '\0';
            strncpy(env[envCount].value, val, sizeof(env[envCount].value) - 1);
            env[envCount].value[sizeof(env[envCount].value) - 1] = '\0';
            envCount++;
        } else {
            // reached maximum capacity; ignore further entries
            // you can log or handle this case if needed
        }
    }

    fclose(fp);
    return 1;
}


// Fetch value for a key
char *getEnvValue(const char *key) {  // retrieve value by key
    for (int i = 0; i < envCount; i++) {   // search for key
        if (strcmp(env[i].key, key) == 0)
            return env[i].value;  // return corresponding value
    }
    return NULL;  // key not found
}
*/
