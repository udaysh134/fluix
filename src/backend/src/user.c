// Headers
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <ctype.h>

#include "../include/user.h"
#include "../include/colors.h"
#include "../include/utils.h"

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
         * 2. We only need to search inside this directory "<root>/src/db/", we'll use "searchDir()" function from "utils.c" for that.
         * 3. If we find it, we internally treat it as "Sign In" and redirect the code to "optSignIn()" function.
         * 4. If we can't find a folder with this name, we treat it as "Sign Up" and ask user if they'd like to continue with that name.
         * 5. If the user choses to go with the name, redirect the code to "optSignUp()" function.
         */
        break;
    }
}


void optSignIn() {
    /**
     * 1. First we change the directory to get inside the user's folder.
     * 2. Then we re-search inside this directory if we can find a JSON file.
     * 3. If we find even a single JSON file (which is a bot, for user), we ask user which one would they like to access?
     * 4. Whatever bot they choose to work on, we'll redirect the code to another function, which will carry on with the procedure.
     */
}


void optSignUp() {
    /**
     * 1. We now ask user what username will they like to continue signing up with.
     * 2. We then re-validate that input if it matches with our standards or not.
     * 3. If it can't pass the validation, we keep running the same in loop.
     * 4. If it passes our validation, we create a folder with that name inside "db" folder, and this will be our "User Creation".
     * 5. Now the user is inside "User Panel" and can add new bots.
     * 6. We take leave from this function from here, as our work is done.
     */
}