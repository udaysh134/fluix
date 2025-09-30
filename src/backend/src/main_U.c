// Header files
#include <stdio.h>
#include <ctype.h>
#include <Windows.h>

// Definitions
const char lineBreakThick[] = "========================================";
const char lineBreakThin[] = "----------------------------------------";

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
    int selecNum;

    system("cls");

    printf("Welcome to Fluix\n%s\n", lineBreakThick);
    Sleep(1000);
    printf("What would you like to do?\n");
    Sleep(1000);
    printf("(1) Sign In - For registered users\n(2) SignUp - For new users\n%s\n", lineBreakThin);

    scanf("%d", &selecNum);
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

    repeat:
    printf("Who are you trying to run this program?\n(A) Admin\n(U) User");
    scanf("%d", &personId);

    switch (tolower(personId)) {
        case 'a':
            isAdmin();
            break;
        case 'b':
            isUser();
            break;
        default:
            printf("You gave an invalid input! Please choose (A) for Admin, (U) for User.");
            goto repeat;
            break;
    }
}

// To check if Admin is trying to run configurations ================================================== >>>>>
void isAdmin() {

}

// To check if User is trying to enter and use the program ================================================== >>>>>
void isUser() {
    printf("Welcome to Fluix\n%s\n", lineBreakThick);
    Sleep(1000);
    printf("What would you like to do?\n");
    Sleep(1000);
    printf("(1) Sign In - For registered users\n(2) SignUp - For new users\n%s\n", lineBreakThin);
}