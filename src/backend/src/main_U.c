// Header files
#include <stdio.h>
#include <ctype.h>
#include <Windows.h>
#include "utils.h"

// Definitions
const char lineBreakThick[] = "========================================";
const char lineBreakThin[] = "----------------------------------------";
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
// To initialize the program ================================================== >>>>>
void launch() {
    char personId;

    system("cls");

    rpt1:
    printf("Who are you, trying to run this program?\n(A) Admin\n(U) User\n%s\n", lineBreakThin);
    scanf("\n%s", &personId);
    
    switch (tolower(personId)) {
        case 'a':
            isAdmin();
            break;
        case 'u':
            isUser();
            break;
        default:
            printf("Error!! | You gave an invalid input! Please choose (A) for Admin, (U) for User.\n");
            goto rpt1;
    }
}


// To check if Admin is trying to run configurations ================================================== >>>>>
void isAdmin() {
    char pass[20];

    rpt2:
    printf("What's the PASSCODE? : ");    
    fgets(pass, sizeof(pass), stdin);

    if (pass == configPass) {
        printf("You're now in ADMIN portal. There's nothing to show here for now.");
        printf("Press any key to exit...");
        getchar();
    } else {
        printf("That was a wrong try!\n");
        goto rpt2;
    }
}


// To check if User is trying to enter and use the program ================================================== >>>>>
void isUser() {
    int selecNum;

    system("cls");

    printf("Welcome to Fluix\n%s\n", lineBreakThick);
    Sleep(1000);
    printf("What would you like to do?\n");
    Sleep(1000);
    printf("(1) Sign In - For registered users\n(2) SignUp - For new users\n%s\n", lineBreakThin);

    scanf("%d", &selecNum);
}