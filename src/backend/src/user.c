// Headers
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <ctype.h>
#include <string.h>

#include "../include/user.h"
#include "../include/colors.h"
#include "../include/utils.h"

// Declarations
void optSignIn(char name[]);
void optSignUp(char name[]);
void checkUsername();
void *validateUsername(char name[]);


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

    // while (1) {
    //     printf("%sUser Panel%s\n%s\n%s\n%s\n", CMD_COL_GREEN, CMD_COL_RESET, lsThick, userOptions, lsThin);

    //     char selectionId = getchar();
    //     eatBuffer();

    //     switch (tolower(selectionId)) {
    //         case '1':
    //             optSignIn();
    //             break;
    //         case '2':
    //             optSignUp();
    //             break;
    //         case 'b':
    //             system("cls");
    //             return;
    //         case '0':
    //             system("cls");
    //             exitThanks('y');
    //             exit(0);
    //         default:
    //             printf("%sYou gave an invalid input! Please choose among these only - 1/2/0.%s\n", CMD_COL_RED, CMD_COL_RESET);
    //     }
    // }

    free(lsThick);
    free(lsThin);
}


/*
----------------------------------------------------------------------------------------------------
MAJOR FUNCTIONS
----------------------------------------------------------------------------------------------------
*/
// ------=>> | Checks if a folder with the given username exists | <<=------
void checkUsername() {
    char *prefix = inputPrefix();
    char userInput[16];
    SearchResult res1;

    system("cls");

    rptr1:

    printf("%s%sPlease provide your USERNAME : %s", prefix, CMD_COL_CYAN, CMD_COL_RESET);
    maskInput(userInput, sizeof(userInput));
    // scanf("%15s", &userInput);

    if (userInput == NULL) {
        printf("%sYou didn't provide anything, please provide a valid username.\n%s", CMD_COL_RED, CMD_COL_RESET);
        eatBuffer();
        goto rptr1;
    }

    if (strlen(userInput) >= sizeof(userInput) - 1) {
        printf("%sThe username cannot be of more than 15 characters.\n%s", CMD_COL_RED, CMD_COL_RESET);
        eatBuffer();
        goto rptr1;
    }
    
    res1 = searchDir(".\\src\\db", "folder", 0, userInput);
    
    if (res1.code == 0) { // 0 means success
        optSignIn(res1.name);
        return;
    } else if (res1.code == 1) { // 1 means failure, directory not found
        optSignUp(userInput);
        return;
    } else if (res1.code == 2) { // 2 means failure, unable to open directory
        printf("%sAn internal error occurred!\n", CMD_COL_RED);
        Sleep(1000);
        printf("Exiting the program!%s", CMD_COL_RESET);
        Sleep(2000);
        exit(0);
    }
}


// ------=>> | Lets user proceed with their Bot Selection | <<=------
void optSignIn(char name[]) {
    char *prefix = inputPrefix();
    char continuation;
    SearchResult res2;

    printf("An account was found with the username %s\"%s\"%s\n", CMD_COL_GREEN, name, CMD_COL_RESET);
    printf("%s%sWould you like to continue signing in with this username? (Y/N) : %s", prefix, CMD_COL_CYAN, CMD_COL_RESET);

    scanf(" %c", &continuation);

    switch (tolower(continuation)) {
        case 'y':
            res2 = searchDir(".\\src\\db\\udaysh", "folder", 1, "");
            printf("%d, %s, %d", res2.code, res2.name, res2.count);
            break;
        case 'n':
        
            break;
        default:
        
            break;
    }
}


// ------=>> | Lets user create an account for themselves | <<=------
void optSignUp(char name[]) {
    printf("Sign Up\n");
    /**
     * 1. We now ask user what username will they like to continue signing up with.
     * 2. We then re-validate that input if it matches with our standards or not.
     * 3. If it can't pass the validation, we keep running the same in loop.
     * 4. If it passes our validation, we create a folder with that name inside "db" folder, and this will be our "User Creation".
     * 5. Now the user is inside "User Panel" and can add new bots.
     * 6. We take leave from this function from here, as our work is done.
     */
}


/*
----------------------------------------------------------------------------------------------------
MINOR FUNCTIONS
----------------------------------------------------------------------------------------------------
*/
void *validateUsername(char name[]) {
    name[strcspn(name, "\n")] = '\0';

    if (isdigit(name[0])) {
        printf("%sError : You can't initiate a username with a number.%s", CMD_COL_RED, CMD_COL_RESET);
    } else if (ispunct(name[0])) {
        printf("%sError : You can't initiate a username with a special character.%s", CMD_COL_RED, CMD_COL_RESET);
    } else if (strlen(name) > 16) {
        printf("%sError : Your username cannot exceed 15 characters.%s", CMD_COL_RED, CMD_COL_RESET);
    } else {
        return name;
    }
}