// Headers
#include "user.h"
#include "colors.h"
#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>


/*
----------------------------------------------------------------------------------------------------
MAIN FUNCTION
----------------------------------------------------------------------------------------------------
*/
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


/*
----------------------------------------------------------------------------------------------------
OTHER FUNCTIONS
----------------------------------------------------------------------------------------------------
*/