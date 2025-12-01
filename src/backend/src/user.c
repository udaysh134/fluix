// Headers
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <ctype.h>
#include <string.h>

#include "../include/user.h"
#include "../include/colors.h"
#include "../include/utils.h"
#include "../include/bot.h"

// Definitions
#define DB_PATH ".\\src\\db\\"

// Declarations
void optSignIn(char name[]);
void optSignUp(char name[]);
void *validateUsername(char name[]);


/*
----------------------------------------------------------------------------------------------------
MAIN FUNCTION
----------------------------------------------------------------------------------------------------
*/
void isUser() {
    char *prefix = inputPrefix();
    char *lsThin = lineSep('-', 50);
    char userInput[16];

    system("cls");
    rptr1:

    printf("%s%sPlease provide your USERNAME : %s", prefix, CMD_COL_CYAN, CMD_COL_RESET);
    maskInput(userInput, sizeof(userInput));

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
    

    // ------=>> | Main work starts from here, by searching the folder with the user input | <<=------
    SearchResult res;
    res = searchDir(DB_PATH, "folder", 0, userInput);

    /**
     * If "res.code = 0", it means success
     * If "res.code = 1", it means failure, directory not found
     * If "res.code = 2", it means failure, unable to open directory
     * If "res.code = 3", it means failure, mode not defined correctly
     */
    if (res.code == 0) { // Eventually leading to optSignIn() function
        char answer1;

        printf("An account was found with the username %s\"%s\"%s.\n", CMD_COL_GREEN, res.name, CMD_COL_RESET);
        Sleep(500);

        rptr2:

        printf("%s%sWould you like to continue signing in with this username? (Y/N) : %s", prefix, CMD_COL_CYAN, CMD_COL_RESET);
        scanf("%c", &answer1);
        eatBuffer();

        switch (tolower(answer1)) {
            case 'y':
                optSignIn(res.name);
                free(lsThin);
                break;
            case 'n':
                printf("%s\nRedirecting to the main menu...", lsThin);
                Sleep(2000);

                system("cls");
                free(lsThin);
                break;
            default:
                printf("%sYou chose a wrong option! Please provide a valid input (Y/N).%s", CMD_COL_RED, CMD_COL_RESET);
                goto rptr2;
        }

        free(lsThin);
        return;
    } 
    
    else if (res.code == 1) {  // Eventually leading to optSignUp() function
        char answer2;

        printf("Seems like there's no user with the username %s\"%s\"%s in our database.", CMD_COL_GREEN, userInput, CMD_COL_RESET);
        Sleep(500);

        rptr3:

        printf("\n%s%sWould you like to create one? (Y/N) : %s", prefix, CMD_COL_CYAN, CMD_COL_RESET);
        scanf("%c", &answer2);
        eatBuffer();

        switch (tolower(answer2)) {
            case 'y':
                optSignUp(userInput);
                free(lsThin);
                break;
            case 'n':
                printf("%s\nRedirecting to the main menu...", lsThin);
                Sleep(2000);

                system("cls");
                free(lsThin);
                break;
            default:
                printf("%sYou chose a wrong option! Please provide a valid input (Y/N).%s", CMD_COL_RED, CMD_COL_RESET);
                goto rptr3;
        }

        free(lsThin);
        return;
    } 
    
    else if (res.code == 2) { // Error handling : Need to give proper path
        printf("%sAn internal error occurred! Error code : 2\n", CMD_COL_RED);
        Sleep(1000);

        printf("Exiting the program!%s", CMD_COL_RESET);
        Sleep(2000);

        free(lsThin);
        exit(0);
    } 
    
    else if (res.code == 3) { // Error handling : Provide MODE for searchDir() function
        printf("%sAn internal error occurred! Error code 3\n", CMD_COL_RED);
        Sleep(1000);

        printf("Exiting the program!%s", CMD_COL_RESET);
        Sleep(2000);

        free(lsThin);
        exit(0);
    }
}


/*
----------------------------------------------------------------------------------------------------
MAJOR FUNCTIONS
----------------------------------------------------------------------------------------------------
*/
void optSignIn(char name[]) {
    /**
     * 1. Directly provide the "User Panel" for this user with three options.
     * 2. These options will be : "New Bot", "My Bots (...)", "Exit"
     * 3. Provide further functionalities by redirecting to bot.c
     */

     printf("Sign In");
}


void optSignUp(char name[]) {
    /**
     * 1. Run the validation of username in a loop, untill it's validated.
     * 2. Create a folder for the user, "src/db/<validated_username>".
     * 3. Direct the user to the "User Panel" with three options : "New Bot", "My Bots (...)", "Exit"
     * 4. Provide further functionalities by redirecting to bot.c
     */

    while (1) {
        if (validateUsername(name) != NULL) {break;} // username is valid
        else{
            printf("\nTry again.\n\n");}
        // 4. Create directory inside db/
        char userPath[50]= DB_PATH;
        sprintf(userPath, name);

        if (CreateDirectory(userPath, NULL)) 
        { 
            // Directory created successfully
            printf(" User created successfully!\n");
            printf(" Folder created: %s\n", userPath);

            // 5. User is now in User Panel
            printf("===== Welcome to User Panel, %s =====\n", name);
            printf("You can now add your bots...\n");

            // 6. Work is done
            return;
        }
        else 
        {
            if (!CreateDirectory(userPath, NULL)) {
                printf("Directory not created. Possibly already exists.\n");}
            else{
                printf("failed to create directory. error code");
            }
        }   
    }
}


/*
----------------------------------------------------------------------------------------------------
MINOR FUNCTIONS
----------------------------------------------------------------------------------------------------
*/
void *validateUsername(char name[]) {
    name[strcspn(name, "\n")] = '\0';

    if (isdigit(name[0])) {
        return printf("%sError : You can't initiate a username with a number.%s", CMD_COL_RED, CMD_COL_RESET);
    } else if (ispunct(name[0])) {
        return printf("%sError : You can't initiate a username with a special character.%s", CMD_COL_RED, CMD_COL_RESET);
    } else if (strlen(name) > 16) {
        return printf("%sError : Your username cannot exceed 15 characters.%s", CMD_COL_RED, CMD_COL_RESET);
    } else {
        return name;
    }
}