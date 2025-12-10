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
    char *lsThick = lineSep('=', 50);
    char *lsThin = lineSep('-', 50);
    char initialOptions[] = "(A) - Admin Panel\n(U) - User Panel\n(0) - Exit";

    rptr1:

    system("cls");

    while (1) {
        printf("%s\n%s\t\t    MAIN MENU%s\n%s\n%s\n%s\n", lsThick, CMD_COL_GREEN, CMD_COL_RESET, lsThick, initialOptions, lsThin);
        printf("%s %sWhat would you like to access? : %s", prefix,  CMD_COL_CYAN, CMD_COL_RESET);

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
                goto rptr1;
        }
    }

    free(lsThin);
}