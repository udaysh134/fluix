// Headers
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <ctype.h>

#include "user.h"
#include "colors.h"
#include "utils.h"


// Declarations
void optSignIn();
void optSignUp();


/*
----------------------------------------------------------------------------------------------------
MAIN FUNCTION
----------------------------------------------------------------------------------------------------
*/
void isUser() {
    char *lsThick = lineSep('=', 50);
    char *lsThin = lineSep('-', 50);
    char userOptions[] = "(1) - Sign In\n(2) - Sign Up\n(B) - Go back\n(0) - Exit";

    system("cls");

    while (1) {
        printf("%sUser Panel%s\n%s\n%s\n%s\n", CMD_COL_GREEN, CMD_COL_RESET, lsThick, userOptions, lsThin);

        char selectionId = getchar();
        eatBuffer();

        switch (tolower(selectionId)) {
            case '1':
                optSignIn();
                break;
            case '2':
                optSignUp();
                break;
            case 'b':
                system("cls");
                return;
            case '0':
                system("cls");
                exitThanks('y');
                exit(0);
            default:
                printf("%sYou gave an invalid input! Please choose among these only - 1/2/0.%s\n", CMD_COL_RED, CMD_COL_RESET);
        }
    }

    free(lsThick);
    free(lsThin);
}


/*
----------------------------------------------------------------------------------------------------
OTHER FUNCTIONS
----------------------------------------------------------------------------------------------------
*/
void optSignIn() {
    printf("You entered Sign In Panel.");
}


void optSignUp() {
    printf("You entered Sign Up Panel.");
}