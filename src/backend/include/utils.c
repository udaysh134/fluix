#include "utils.h"
#include "colors.h"

#include <stdio.h>
#include <stdlib.h>


/*
----------------------------------------------------------------------------------------------------
LINE SEPARATOR FUNCTION
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
GLOBAL PREFIX FUNCTION
----------------------------------------------------------------------------------------------------
*/
char *inputPrefix() {
    return CMD_COL_YELLOW ">> " CMD_COL_RESET;
}


/*
----------------------------------------------------------------------------------------------------
BUFFER CONSUMING FUNCTION
----------------------------------------------------------------------------------------------------
*/
void eatBuffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {}
}