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

    system("cls");

    while (1) {
        printf("%s%sWho are you, trying to run this program?%s\n(A) Admin\n(U) User\n(0) To exit\n%s\n", prefix, CMD_COL_CYAN, CMD_COL_RESET, lsThin);

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
                system("cls");
                printf("%sThank you!\nHave a good day!%s", CMD_COL_GREEN, CMD_COL_RESET);
                return;
            default:
                printf("%sYou gave an invalid input! Please choose (A) for Admin, (U) for User or (0) to exit.%s\n", CMD_COL_RED, CMD_COL_RESET);
        }
    }

    free(lsThin);
}


/*
----------------------------------------------------------------------------------------------------
OTHER FUNCTIONS
----------------------------------------------------------------------------------------------------
*/