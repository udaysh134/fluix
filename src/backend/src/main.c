// Header files
#include <stdio.h>
#include <ctype.h>
#include <Windows.h>

#include "../include/admin.h"
#include "../include/user.h"
#include "../include/colors.h"
#include "../include/utils.h"

// Declarations
void launch();


/*
----------------------------------------------------------------------------------------------------
MAIN EXECUTION
----------------------------------------------------------------------------------------------------
*/
int main () {
    launch();

    return 0;
}


/*
----------------------------------------------------------------------------------------------------
FUNCTIONS
----------------------------------------------------------------------------------------------------
*/
// ------=>> | Initialization | <<=------
void launch() {
    char *prefix = inputPrefix();
    char *lsThick = lineSep('=', 40);
    char *lsThin = lineSep('-', 40);
    char personId;

    system("cls");

    while (1) {
        printf("%s%sWho are you, trying to run this program?%s\n(A) Admin\n(U) User\n%s\n", prefix, CMD_COL_CYAN, CMD_COL_RESET, lsThin);
        free(lsThin);

        scanf("%s", &personId);

        switch (tolower(personId)) {
            case 'a':
                fflush(stdin);
                isAdmin();
                break;
            case 'u':
                fflush(stdin);
                isUser();
                break;
            default:
                printf("%sYou gave an invalid input! Please choose (A) for Admin, (U) for User.%s\n", CMD_COL_RED, CMD_COL_RESET);
        }
    }
}