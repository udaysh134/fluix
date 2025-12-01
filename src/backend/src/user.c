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
char *validateUsername(char name[]);


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
    printf("Sign In : ");
    printf("%s\n", name);
}


void optSignUp(char name[]) {
    /**
     * 1. Run the validation of username in a loop, untill it's validated.
     * 2. Create a folder for the user, "src/db/<validated_username>".
     * 3. Direct the user to the "User Panel" with three options : "New Bot", "My Bots (...)", "Exit"
     * 4. Provide further functionalities by redirecting to bot.c
     */
    char *finalName = validateUsername(name);
}


/*
----------------------------------------------------------------------------------------------------
MINOR FUNCTIONS
----------------------------------------------------------------------------------------------------
*/
char *validateUsername(char name[]) {
    char *prefix = inputPrefix();
    char *lsThin = lineSep('-', 50);
    static char nameInput[17];
    strcpy(nameInput, name);

    rptr4:
    
    nameInput[strcspn(nameInput, "\n")] = '\0';

    if (isdigit(nameInput[0])) { // Error handling : In case, name starts with a number
        printf("\n%s\n%sError : You can't initiate a username with a number.%s\n", lsThin, CMD_COL_RED, CMD_COL_RESET);
        printf("%s%sPlease provide a new updated username : %s", prefix, CMD_COL_CYAN, CMD_COL_RESET);
        fgets(nameInput, sizeof(nameInput), stdin);

        goto rptr4;
    }

    if (ispunct(nameInput[0])) { // Error handling : In case, name starts with punctuations
        printf("\n%s\n%sError : You can't initiate a username with a special character.%s\n", lsThin, CMD_COL_RED, CMD_COL_RESET);
        printf("%s%sPlease provide a new updated username : %s", prefix, CMD_COL_CYAN, CMD_COL_RESET);
        fgets(nameInput, sizeof(nameInput), stdin);
        
        goto rptr4;
    }

    if (strlen(nameInput) > 15) { // Error handling : In case, name contains more than 15 characters
        printf("\n%s\n%sError : Your username cannot exceed 15 characters.%s\n", lsThin, CMD_COL_RED, CMD_COL_RESET);
        printf("%s%sPlease provide a new updated username : %s", prefix, CMD_COL_CYAN, CMD_COL_RESET);
        eatBuffer();
        fgets(nameInput, sizeof(nameInput), stdin);

        goto rptr4;
    }

    if (strlen(nameInput) < 3) { // Error handling : In case, name contains less than 3 characters
        printf("\n%s\n%sError : Your username needs to be of at least 3 letters.%s\n", lsThin, CMD_COL_RED, CMD_COL_RESET);
        printf("%s%sPlease provide a new updated username : %s", prefix, CMD_COL_CYAN, CMD_COL_RESET);
        fgets(nameInput, sizeof(nameInput), stdin);

        goto rptr4;
    }

    SearchResult res;
    res = searchDir(DB_PATH, "folder", 0, nameInput);

    if (res.code == 0) { // Error handling : In case, folder already exists
        printf("\n%s\n%sError : Please choose another username, this already exists.%s\n", lsThin, CMD_COL_RED, CMD_COL_RESET);
        printf("%s%sPlease provide a new updated username : %s", prefix, CMD_COL_CYAN, CMD_COL_RESET);
        fgets(nameInput, sizeof(nameInput), stdin);

        goto rptr4;
    }

    free(lsThin);
    return nameInput;
}