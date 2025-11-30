// Headers
#include <stdio.h>
#include <ctype.h>
#include <Windows.h>

#include "../include/admin.h"
#include "../include/user.h"
#include "../include/colors.h"
#include "../include/utils.h"


/*
----------------------------------------------------------------------------------------------------
MAIN FUNCTION
----------------------------------------------------------------------------------------------------
*/
void launch() {
    char *prefix = inputPrefix();
    char *lsThin = lineSep('-', 50);
    char initialOptions[] = "(A) - Admin Panel\n(U) - User Panel\n(0) - Exit";

    system("cls");

    while (1) {
        printf("%s%sWhat would you like to access?%s\n%s\n%s\n", prefix, CMD_COL_CYAN, CMD_COL_RESET, initialOptions, lsThin);

        char personId = getchar();
        eatBuffer();

        switch (tolower(personId)) {
            case 'a':
                isAdmin();
                break;
            case 'u':
                isUser();
                break;
            case '0':
                exitThanks('y');
                return;
            default:
                printf("%sYou gave an invalid input! Please choose among these only - A/U/0.%s\n", CMD_COL_RED, CMD_COL_RESET);
        }
    }

    free(lsThin);
}


/*
----------------------------------------------------------------------------------------------------
OTHER FUNCTIONS
----------------------------------------------------------------------------------------------------
*/