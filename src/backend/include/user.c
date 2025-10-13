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
void checkUsername();


/*
----------------------------------------------------------------------------------------------------
MAIN FUNCTION
----------------------------------------------------------------------------------------------------
*/
void isUser() {
    char *lsThick = lineSep('=', 50);
    char *lsThin = lineSep('-', 50);
    char userOptions[] = "(1) - Sign In\n(2) - Sign Up\n(B) - Go back\n(0) - Exit";

    checkUsername();

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
// ------=>> | Checks if a folder with the given username exists | <<=------
void checkUsername() {
    char *prefix = inputPrefix();
    char username[20];

    system("cls");

    while (1) {
        printf("%s%sPlease provide your USERNAME : %s", prefix, CMD_COL_CYAN, CMD_COL_RESET);
        scanf("%s", &username);

        if (username == NULL) {
            printf("%sYou didn't provide anything, please provide a valid username.%s", CMD_COL_RED, CMD_COL_RESET);
            break;
        }

        /**
         * 1. Validate the user input here, according to the standards, for example :
         * 2. Check if the given input is not initiating with a number, capital letter, or special character
         * 3. Then only proceed to the following step...
         */

        username[strcspn(username, "\n")] = '\0';

        /**
         * 1. Once we have the username, we can use that string literal to check if a folder exists exactly with this name.
         * 2. We only need to search inside this directory "<root>/src/db/", if we find it, we internally treat it as "Sign In".
         * 3. If we can't find a folder with this name, we treat it as "Sign Up" and ask user if they'd like to continue with that name...
         * 4. If "YES", we create a folder using the name user agreed,
         * 5. If "NO", we ask if they'd like to provide a new name and then either continue Sign Up process or Exit.
         * 6. If "EXIT", we break from the loop and go back to the main launch panel.
         */
        break;
    }
}


void optSignIn() {
    // printf("You entered Sign In Panel.");
}


void optSignUp() {
    // printf("You entered Sign Up Panel.");
}