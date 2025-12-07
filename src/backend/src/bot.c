// Headers
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
#include <string.h>

#include "../include/colors.h"
#include "../include/utils.h"


/*
----------------------------------------------------------------------------------------------------
MAIN FUNCTIONS
----------------------------------------------------------------------------------------------------
*/
// ------=>> | Process intiates for creation of a new bot | <<=------
void createBot(char path[], char username[]) {
    /**
     * 1. The text based user panel UI will stay ON in this page, but options will change.
     * 2. The user should be asked the Name, Description (optional) and Tags (optional) of the bot they're creating.
     * 3. Taking this info, we'll now first - create a JSON with the name provided by the user
     * 4. And then - we'll copy the basic structure we have from 'dataSchema.json' into this newly created bot file
     * 5. Now that we have the file and the structure inside it, we'll start appending some data into data fields of that structure
     */


    /**
     * 1. These data will be picked right then and there during the creation of the bot, like - name, description, tags
     * 2. Other data fields include : 
     *    ~ id - (which we'll assign right there)
     *    ~ entryCount - (will be 0, as the bot was just created)
     *    ~ owner - (will the username of that user)
     *    ~ createdAt - (will be the exact current time in milliseconds)
     *    ~ modifiedAt - (will be same as cretedAt, as the bot was just created)
     */


    /**
     * 1. Once we insert all this data into their respective fields inside that user's specific bot's JSON file...
     * 2. We'll then give the user a message that a bot with that specific name was created and now they can access their bot...
     * 3. Using the second option from the User Panel, which is '(A) - Access your bots'.
     * 4. And then we finally redirect the user to it's user panel.
     */


    /**
     * That's it, that's all we need to do inside this function.
     */
    char *prefix = inputPrefix();
    char *lsThick = lineSep('=', 50);
    char *lsThin = lineSep('-', 50);

    char name[10];
    char desc[1002] = "";
    char tags[3][12] = {0};

    char tempDesc[1002];
    char tempTags[40] = "";

    // ------=>> | Actual functioning starts from here | <<=------
    system("cls");
      
    char printOptions[1024];
    snprintf(printOptions, sizeof(printOptions),
        "%s"
        "\n%s\t   USER PANEL - %s"
        "%s%s%s"
        "\n\t      (Bot Creation)"
        "\n%s"
        "\n(R) - Return back"
        "\n(0) - Exit"
        "\n%s"
        "\n",

        lsThick,
        CMD_COL_GREEN, CMD_COL_RESET,
        CMD_COL_BLACK, username, CMD_COL_RESET,
        lsThick,
        lsThin
    );
    printf(printOptions);

    // Asks NAME for the bot -------------------- >>
    printf("%s %sNAME%s of the bot? : ", prefix, CMD_COL_CYAN, CMD_COL_RESET);
    scanf("%8s", &name);

    // Processing
    // 1. Check if the input is just R or 0 - that'll be treated differently
    // 2. Make sure the size is neither less than 3, nor greater than 8
    // 3. Make sure it doesn't have any special character
    // 4. Make sure the name doesn't already exist inside that user's folder



    // Asks DESCRIPTION of the bot -------------------- >>
    printf("%s %sDESCRIPTION%s of the bot? %s[Optional]%s : ", prefix, CMD_COL_CYAN, CMD_COL_RESET, CMD_COL_BLACK, CMD_COL_RESET);
    eatBuffer();
    fgets(tempDesc, sizeof(tempDesc), stdin);

    // Processing
    // 1. Check if the input is just R or 0 - that'll be treated differently
    // 3. Make sure the size is neither less than 15, nor greater than 1000
    // 4. Make sure it doesn't contain quotes (single & double) and backticks



    // Asks TAGS for the bot -------------------- >>
    printf("%s %sTAGS%s for the bot? Should be separated by comma(s) %s[Optional]%s : ", prefix, CMD_COL_CYAN, CMD_COL_RESET, CMD_COL_BLACK, CMD_COL_RESET);
    eatBuffer();
    fgets(tempTags, sizeof(tempTags), stdin);

    // Processing
    // 1. Check if the input is just R or 0 - that'll be treated differently
    // 2. Check if it contains any comma(s)...
    //    - if not, make sure the the whole input is not greater than 10
    //    - if it does, seperate strings with commas and check if they too aren't greater than 10
    // 3. After separation check each separated string if it contains any spaces...
    //    - if it does, remove all spaces and merge everything into one string
    // 4. Now treat all those separated strings as finalized, and save them one by one in "tags" array
      

    free(lsThick);
    free(lsThin);
}


// ------=>> | User accesses their bots' panel | <<=------
void accessBots(char path[], char username[]) {
    /**
     * 1. The text based user panel UI will stay ON in this page, but the 'USER PANEL' heading and the given options will change.
     * 2. 'USER PANEL' heading will change to 'BOT PANEL', and options will be the names of the bots user currently has.
     * 3. These options should be dynamic (for obvious reasons), meaning it should change according to the number of bots, user has.
     * 4. There must also be two more options '(R) - Return back' and '(0) - Exit'
     */


    /**
     * 1. When the user chooses a specific bot of their's, the program should detect which bot to select and based on that...
     * 2. The next page will be the four key options for doing operations on the bot, which are 'view', 'add', 'edit', & 'delete'.
     * 3. Now any chosen option will redirect the code flow to 'data.c' where these functions are actually defined.
     */


    /**
     * The work is completed here, we're done with the bot panel and the code is redirected to 'data.c'.
     */
}