// Headers
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <stdint.h>
#include <time.h>

#include "../include/utils.h"
#include "../include/colors.h"

// Definitions
#define ENV_LINE_MAX 256

// Declarations
static uint32_t weakRandom_u32(void);
static uint64_t fnv1a_Hash(const char *s);


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
char *inputPrefix(void) {
    return CMD_COL_YELLOW ">> " CMD_COL_RESET;
}


/*
----------------------------------------------------------------------------------------------------
3. BUFFER CONSUMING FUNCTION
----------------------------------------------------------------------------------------------------
*/
void eatBuffer(void) {
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
 * PARAMETERS:
 * 1. "path" - Relative path of the desired directory, like ".\\src\\db".
 * 2. "type" - Select if it is a "file" or a "folder".
 * 3. "mode" - Integer value of "0" or "1" (0 is "Target Mode", 1 is "List Mode").
 * 4. "name" - Required if mode is 0, or leave it blank like (""). Any name is ignored by default.
 * 
 * RESULTS:
 * 1. If "res.code = 0", it means success
 * 2. If "res.code = 1", it means failure, directory not found
 * 3. If "res.code = 2", it means failure, unable to open directory
 * 4. If "res.code = 3", it means failure, mode not defined correctly
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
7. ENV PARSER FUNCTION
----------------------------------------------------------------------------------------------------
*/
char *parseEnv(const char *file, const char *key) {
    FILE *openedFile = fopen(file, "r");
    if (!openedFile) return NULL;

    char line[ENV_LINE_MAX];

    while (fgets(line, sizeof(line), openedFile)) {
        // (1). Skip comments and empty lines
        if (line[0] == '#' || line[0] == '\n') continue;

        // (2). Skip lines with no equal sign, meaning no values
        char *equalSign = strchr(line, '=');
        if (!equalSign) continue;

        *equalSign = '\0';
        char *extractedKey = line;
        char *extractedValue = equalSign + 1;

        // (3). Trim spaces around extracted KEY (if any)
        while (*extractedKey == ' ' || *extractedKey == '\t') extractedKey++;
        char *end = extractedKey + strlen(extractedKey) - 1;
        while (end > extractedKey && (*end == ' ' || *end == '\t' || *end == '\r')) *end-- = '\0';

        // (4). Trim spaces on left from extracted VALUE (if any)
        while (*extractedValue == ' ' || *extractedValue == '\t') extractedValue++;

        // (5). Handling line comments
        for (char *ptr = extractedValue; *ptr; ptr++) {
            if (*ptr == '#') {
                *ptr = '\0';
                break;
            }
        }

        // (6). Trim right spaces or newline from cleaned value
        end = extractedValue + strlen(extractedValue) - 1;
        while (end > extractedValue && (*end == ' ' || *end == '\t' || *end == '\n' || *end == '\r')) *end-- = '\0';

        // (7). Remove surrounding quotes
        if ((extractedValue[0] == '"' || extractedValue[0] == '\'' || extractedValue[0] == '`')) {
            char quoteType = extractedValue[0];
            size_t len = strlen(extractedValue);

            if (len >= 2 && extractedValue[len - 1] == quoteType) {
                extractedValue[len - 1] = '\0';
                extractedValue++;
            }
        }

        // (8). Comparing keys - Final returning of the VALUE
        if (strcmp(extractedKey, key) == 0) {
            char *value = malloc(strlen(extractedValue) + 1);

            if (!value) {
                fclose(openedFile);
                return NULL;
            }

            strcpy(value, extractedValue);
            fclose(openedFile);
            return value;
        }
    }

    fclose(openedFile);
    return NULL;
}


/*
----------------------------------------------------------------------------------------------------
8. DELETE FOLDER FUNCTION
----------------------------------------------------------------------------------------------------
*/
int deleteDir(const char *folder) {
    char searchPath[MAX_PATH];
    snprintf(searchPath, sizeof(searchPath), "%s\\*.*", folder);

    WIN32_FIND_DATAA fd;
    HANDLE hFind = FindFirstFileA(searchPath, &fd);

    if (hFind == INVALID_HANDLE_VALUE) return 0;

    do {
        if (strcmp(fd.cFileName, ".") == 0 || strcmp(fd.cFileName, "..") == 0) continue;

        char path[MAX_PATH];
        snprintf(path, sizeof(path), "%s\\%s", folder, fd.cFileName);

        if (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            deleteDir(path);
            RemoveDirectoryA(path);
        } else {
            DeleteFileA(path);
        }
    } while (FindNextFileA(hFind, &fd));

    FindClose(hFind);
    return RemoveDirectoryA(folder); // Returns a BOOL, so 0 is failure, 1 is success
}


/*
----------------------------------------------------------------------------------------------------
9. STRING CLEANER FUNCTION
----------------------------------------------------------------------------------------------------
*/
int isStrClean(char *input) {
    for (int i = 0; input[i] != '\0'; i++) {
        if (!isalnum(input[i])) {
            return 0;
        }
    }
    
    return 1;
}


/*
----------------------------------------------------------------------------------------------------
10. GET EPOCH TIME IN MILLISECONDS
----------------------------------------------------------------------------------------------------
*/
uint64_t getEpochTime(void) {
    FILETIME ft;
    GetSystemTimeAsFileTime(&ft);

    uint64_t t = ((uint64_t)ft.dwHighDateTime << 32) | ft.dwLowDateTime;
    return (t - 116444736000000000ULL) / 10000;
}


/*
----------------------------------------------------------------------------------------------------
11. GENRATE RANDOM STRING OF ALPHANUMERIC CHARACTERS
----------------------------------------------------------------------------------------------------
*/
void genRand(char *str, size_t length) {
    static const char charset[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789";

    size_t charset_len = sizeof(charset) - 1;

    for (size_t i = 0; i < length; i++) {
        uint32_t r = weakRandom_u32();
        str[i] = charset[r % charset_len];
    }

    str[length] = '\0';
}

static uint32_t weakRandom_u32(void) {
    static int seeded = 0;
    if (!seeded) {
        srand((unsigned)time(NULL));
        seeded = 1;
    }

    return ((uint32_t)rand() << 16) ^ rand();
}


/*
----------------------------------------------------------------------------------------------------
12. STRING TO HEXADECIMAL
----------------------------------------------------------------------------------------------------
*/
void strToHex(const char *input, char *out) {
    uint64_t hash = fnv1a_Hash(input);
    sprintf(out, "%016llX", (unsigned long long)hash);
}

static uint64_t fnv1a_Hash(const char *s) {
    uint64_t hash = 14695981039346656037ULL;

    while (*s) {
        hash ^= (unsigned char)*s++;
        hash *= 1099511628211ULL;
    }

    return hash;
}


/*
----------------------------------------------------------------------------------------------------
13. JSON FILE CONTENT READER
----------------------------------------------------------------------------------------------------
*/
char *readJSON(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) return NULL;

    if (fseek(fp, 0, SEEK_END) != 0) {
        fclose(fp);
        return NULL;
    }

    long size = ftell(fp);
    if (size < 0) {
        fclose(fp);
        return NULL;
    }

    rewind(fp);

    char *buffer = malloc((size_t)size + 1);
    if (!buffer) {
        fclose(fp);
        return NULL;
    }

    size_t read = fread(buffer, 1, (size_t)size, fp);
    buffer[read] = '\0';

    fclose(fp);
    return buffer;
}