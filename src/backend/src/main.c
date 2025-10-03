// Header files
#include <stdio.h>
#include <ctype.h>
#include <Windows.h>

#include "../include/colors.h"
#include "../include/utils.h"

// Definitions
const char inputPrefix[] = CMD_COL_YELLOW ">> " CMD_COL_RESET;
const char configPass[] = "fluixo";

// Function Declarations
void launch();
void isAdmin();
void isUser();


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
// To initialize the program = = = = = = = = = = >>>>>
void launch() {
    char *lsThick = lineSep('=', 40);
    char *lsThin = lineSep('-', 40);
    char personId;

    system("cls");

    while (1) {
        printf("%s%sWho are you, trying to run this program?%s\n(A) Admin\n(U) User\n%s\n", inputPrefix, CMD_COL_CYAN, CMD_COL_RESET, lsThin);
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


// To check if Admin is trying to run configurations = = = = = = = = = = >>>>>
void isAdmin() {
    char *lsThick = lineSep('=', 40);
    char *lsThin = lineSep('-', 40);
    char pass[20];

    while (1) {
        printf("What's the PASSCODE? : ");

        if (fgets(pass, sizeof(pass), stdin) == NULL) {
            printf("There was an error! Please provide a valid input.");
            break;
        }

        pass[strcspn(pass, "\n")] = '\0';

        if (strcmp(pass, configPass) == 0) {
            printf("You're now in ADMIN portal, but there's nothing to show here for now.");
            printf("\nPress any key to exit...");

            fgets(pass, sizeof(pass), stdin);

            break;
        } else {
            printf("That was a wrong try!\n");
        }
    }
}


// To check if User is trying to enter and use the program = = = = = = = = = = >>>>>
void isUser() {
    char *lsThick = lineSep('=', 40);
    char *lsThin = lineSep('-', 40);
    int selecNum;

    system("cls");

    printf("Welcome to Fluix\n%s\n", lsThick);
    free(lsThick);
    
    Sleep(1000);
    printf("What would you like to do?\n");
    Sleep(1000);
    printf("(1) Sign In - For registered users\n(2) SignUp - For new users\n%s\n", lsThin);
    free(lsThin);

    scanf("%d", &selecNum);
}