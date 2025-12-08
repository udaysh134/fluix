// Headers
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
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

        printf("Account found : %s\"%s\"%s", CMD_COL_GREEN, res.name, CMD_COL_RESET);
        Sleep(500);

        rptr2:

        printf("\n%s%sWould you like to continue with this? (Y/N) : %s", prefix, CMD_COL_CYAN, CMD_COL_RESET);
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

        printf("No user found : %s\"%s\"%s", CMD_COL_GREEN, userInput, CMD_COL_RESET);
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
// ------=>> | User with Sign In flow | <<=------
void optSignIn(char name[]) {
    char path[256];
    char *lsThin = lineSep('-', 50);

    snprintf(path, sizeof(path), "%s%s", DB_PATH, name);

    printf("%s\nPlease wait...", lsThin);
    Sleep(2000);
    printf("\nLogging you in...");
    Sleep(2000);
    system("cls");

    free(lsThin);
    userPanel(path, name);
}


// ------=>> | User with Sign Up flow | <<=------
void optSignUp(char name[]) {
    char path[256];
    char *finalUsername = validateUsername(name);
    char *lsThin = lineSep('-', 50);

    snprintf(path, sizeof(path), "%s%s", DB_PATH, finalUsername);

    if (CreateDirectory(path, NULL)) {
        printf("%s\nSuccess! A user was created with the name %s\"%s\"%s", lsThin, CMD_COL_GREEN, finalUsername, CMD_COL_RESET);
        Sleep(2000);
        printf("\nTaking you to your User Panel...");
        Sleep(2000);
        system("cls");

        free(lsThin);
        userPanel(path, finalUsername);
    } else {
        printf("%s\n%sAn internal error occurred! Please contact your developers.\n", lsThin, CMD_COL_RED);
        Sleep(1000);

        printf("Exiting the program!%s", CMD_COL_RESET);
        Sleep(2000);

        free(lsThin);
        exit(0);
    }
}


// ------=>> | Final User Panel for both Sign In and Sign Up flow | <<=------
void userPanel(char dir[], char username[]) {
    char *prefix = inputPrefix();
    char *lsThick = lineSep('=', 50);
    char *lsThin = lineSep('-', 50);
    int fileCount = 0;

    SearchResult res;
    res = searchDir(dir, "file", 1, "");
    if (res.code == 0) fileCount = res.count;


    // Actual User Panel starts from here
    rptr5:
    system("cls");

    char printOptions[1024];
    snprintf(printOptions, sizeof(printOptions),
        "%s"
        "\n%s\t   USER PANEL - %s"
        "%s%s%s"
        "\n%s"
        "\n(N) - Create new Bot"
        "\n(A) - Access your Bots %s(%d)%s"
        "\n(D) - Delete your Account"
        "\n(R) - Return back"
        "\n(0) - Exit"
        "\n%s"
        "\n",

        lsThick,
        CMD_COL_GREEN, CMD_COL_RESET,
        CMD_COL_BLACK, username, CMD_COL_RESET,
        lsThick,
        CMD_COL_BLACK, fileCount, CMD_COL_RESET,
        lsThin
    );
    printf(printOptions);

    printf("%s %sWhat next? : %s", prefix,  CMD_COL_CYAN, CMD_COL_RESET);
    char selection = tolower(getchar());

    switch (selection) {
        case 'n':
            createBot(dir, username);
        case 'a':
            if (fileCount == 0) {
                printf("%sYou don't currently have any bot. Create a new bot first!%s\n", CMD_COL_RED, CMD_COL_RESET);
                goto rptr5;
            } else {
                accessBots(dir, username);
            }
        case 'd':
            rptr6:

            system("cls");
            printf(printOptions);
            printf("%s %sAre you sure you want to delete your account? This is irreversible! (Y/N) : %s", prefix, CMD_COL_CYAN, CMD_COL_RESET);

            char choice = tolower(getchar());
            eatBuffer();

            if (choice == 'y') {
                int delStatus = deleteDir(dir);

                if (delStatus == 0) {
                    printf("%sAn internal error occured while deleting your account. Please try again later!%s", CMD_COL_RED, CMD_COL_RESET);
                    Sleep(1000);

                    printf("Exiting the program!%s", CMD_COL_RESET);
                    Sleep(2000);

                    free(lsThick);
                    free(lsThin);
                    exit(0);
                } else if (delStatus == 1) {
                    printf("%s Deletion in progress...", prefix);
                    Sleep(3000);

                    system("cls");
                    printf(printOptions);
                    printf("%s Your account %s\"%s\"%s was successfully deleted from our database.", prefix, CMD_COL_RED, username, CMD_COL_RESET);
                    Sleep(5000);
                    printf("\n%s Redirecting you to the main menu...", prefix);
                    Sleep(4000);

                    system("cls");

                    free(lsThick);
                    free(lsThin);

                    break;
                } else {
                    printf("%sAn internal error occured while deleting your account. Please try again later!%s", CMD_COL_RED, CMD_COL_RESET);
                    Sleep(1000);

                    printf("Exiting the program!%s", CMD_COL_RESET);
                    Sleep(2000);

                    free(lsThick);
                    free(lsThin);
                    exit(0);
                }
            } else if (choice == 'n') {
                goto rptr5;
            } else {
                printf("%sPlease provide a valid input. Answer with either \'Y\' or \'N\'.%s", CMD_COL_RED, CMD_COL_RESET);
                Sleep(3000);
                goto rptr6;
            }
            
            break;
        case 'r':
            system("cls");
            return;
        case '0':
            exitThanks('y');
            exit(0);
        default:
            printf("%sYou gave an invalid input! Please choose among these only - N/A/D/R/0.%s\n", CMD_COL_RED, CMD_COL_RESET);
            goto rptr5;
    }
}


/*
----------------------------------------------------------------------------------------------------
HELPER FUNCTIONS
----------------------------------------------------------------------------------------------------
*/
// ------=>> | Validate username all from one place | <<=------
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