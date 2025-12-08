// Headers
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#include "../include/colors.h"
#include "../include/utils.h"
#include "../include/user.h"

// Declarations
typedef struct {
    char name[10];
    char desc[1002];
    char tags[3][12];
} dataSet;

dataSet collectData(char path[], char username[]);


/*
----------------------------------------------------------------------------------------------------
MAIN FUNCTIONS
----------------------------------------------------------------------------------------------------
*/
// ------=>> | Process intiates for creation of a new bot | <<=------
void createBot(char path[], char username[]) {
    dataSet res;
    res = collectData(path, username);

    char confirmation[10];

    printf("%sBot creation data collected:%s\n", CMD_COL_GREEN, CMD_COL_RESET);
    printf("Name:        %s\n", res.name);
    printf("Description: %s\n", res.desc);
    printf("Tags:        %s, %s, %s\n", res.tags[0], res.tags[1], res.tags[2]);

    Sleep(1000);

    printf("%s>> Do you want to finalize these crednetials? (Y/N)%s: "CMD_COL_YELLOW, CMD_COL_RESET);
    scanf("%9s", &confirmation);
    eatBuffer();

    if (tolower(confirmation[0]) == 'y' && tolower(confirmation[1]) == 'e' && tolower(confirmation[2])=='s') {
        printf("%sFinalizing bot creation...%s\n", CMD_COL_GREEN, CMD_COL_RESET);
        Sleep(2000);
 
        char filePath[260];  

    snprintf(filePath, sizeof(filePath), "%s\\%s.json", path, res.name);

    FILE *fp = fopen(filePath, "w");
    if (!fp) {
        printf("%sError: Could not create bot file at \"%s\"%s\n",
               CMD_COL_RED, filePath, CMD_COL_RESET);
        Sleep(2000);
        return;
    }

    // timestamps (seconds since epoch for now)
    time_t now = time(NULL);
    long createdAt  = (long)now;
    long modifiedAt = (long)now;

    int botId      = 1;   
    int entryCount = 0;   

    //here we will register the final data into the bot file
        fprintf(fp,
        "{\n"
        "    \"schemaVersion\": 1.0,\n"
        "    \"bot\": {\n"
        "        \"id\": %d,\n"
        "        \"name\": \"%s\",\n"
        "        \"description\": \"%s\",\n"
        "        \"tags\": [\"%s\", \"%s\", \"%s\"],\n"
        "        \"entryCount\": %d,\n"
        "        \"owner\": \"%s\",\n"
        "        \"createdAt\": %ld,\n"
        "        \"modifiedAt\": %ld\n"
        "    },\n"
        "    \"entries\": []\n"
        "}\n",
        botId,
        res.name,
        res.desc,
        res.tags[0], res.tags[1], res.tags[2],
        entryCount,
        username,
        createdAt,
        modifiedAt
    );

    fclose(fp);

    printf("%sBot \"%s\" created successfully at: %s%s\n",
           CMD_COL_GREEN, res.name, filePath, CMD_COL_RESET);
    Sleep(2000);
    printf("Redirecting to User Panel...\n");
    Sleep(2000);
    userPanel(path, username);

    } 
    
    
    else {
        printf("%sBot creation aborted. Returning to User Panel...%s\n", CMD_COL_RED, CMD_COL_RESET);
        Sleep(2000);
        userPanel(path, username);
    }

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


/*
----------------------------------------------------------------------------------------------------
HELPER FUNCTIONS
----------------------------------------------------------------------------------------------------
*/
// ------=>> | Bot creation, navigation and Data collection | <<=------
dataSet collectData(char path[], char username[]) {
    dataSet result = {0};

    char *prefix = inputPrefix();
    char *lsThick = lineSep('=', 50);
    char *lsThin = lineSep('-', 50);

    char name[10];
    char desc[1002] = "";
    char tags[3][12] = {0};

    char tempName[10];
    char tempDesc[1002];
    char tempTags[40] = "";

    // Starts here
    rptr0:
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


    // Bot's NAME section ---------------------------------------- >>
    printf("%s %sNAME%s of the bot? : ", prefix, CMD_COL_CYAN, CMD_COL_RESET);
    scanf("%8s", &tempName);
    eatBuffer();
    
    if((tolower(tempName[0]) == 'r' && tolower(tempName[1]) == '\0') || (tolower(tempName[0]) == '0' && tolower(tempName[1]) == '\0')) {
        rptr1:

        printf("%s %sAre you sure you want to abort? (Y/N) : %s", prefix, CMD_COL_RED, CMD_COL_RESET);
        char confirmation = tolower(getchar());

        switch (confirmation) {
            case 'y':
                if (tolower(tempName[0]) == 'r') {
                    userPanel(path, username);
                } else {
                    exitThanks('y');
                    exit(0);
                }
            case 'n':
                printf("Restarting bot creation...");
                Sleep(2000);

                goto rptr0;
            default:
                printf("\n%sThat was a wrong choice! Please provide a valid input (Y/N)%s", CMD_COL_RED, CMD_COL_RESET);
                goto rptr1;
        }
    } else {
        // Processing + Error Handling

        // 1. Make sure the size is neither less than 3, nor greater than 8
        // 2. Make sure it doesn't have any special character
        // 3. Make sure the name doesn't already exist inside that user's folder
    }


    // Bot's DESCRIPTION section ---------------------------------------- >>
    printf("%s %sDESCRIPTION%s of the bot? %s[Optional]%s : ", prefix, CMD_COL_CYAN, CMD_COL_RESET, CMD_COL_BLACK, CMD_COL_RESET);
    fgets(tempDesc, sizeof(tempDesc), stdin);

    tempDesc[strcspn(tempDesc, "\n")] = '\0';

    if((tolower(tempDesc[0]) == 'r' && tolower(tempDesc[1]) == '\0') || (tolower(tempDesc[0]) == '0' && tolower(tempDesc[1]) == '\0')) {
        rptr2:

        printf("%s %sAre you sure you want to abort? (Y/N) : %s", prefix, CMD_COL_RED, CMD_COL_RESET);
        char confirmation = tolower(getchar());

        switch (confirmation) {
            case 'y':
                if (tolower(tempDesc[0]) == 'r') {
                    userPanel(path, username);
                } else {
                    exitThanks('y');
                    exit(0);
                }
            case 'n':
                printf("Restarting bot creation...");
                Sleep(2000);

                goto rptr0;
            default:
                printf("\n%sThat was a wrong choice! Please provide a valid input (Y/N)%s", CMD_COL_RED, CMD_COL_RESET);
                goto rptr2;
        }
    } else {
        // Processing + Error Handling

        // 1. Make sure the size is neither less than 15, nor greater than 1000
        // 2. Make sure it doesn't contain quotes (single & double) and backticks
    }


    // Bot's TAGS section ---------------------------------------- >>
    printf("%s %sTAGS%s for the bot? Should be separated by comma(s) %s[Optional]%s : ", prefix, CMD_COL_CYAN, CMD_COL_RESET, CMD_COL_BLACK, CMD_COL_RESET);
    fgets(tempTags, sizeof(tempTags), stdin);

    tempTags[strcspn(tempTags, "\n")] = '\0';

    if((tolower(tempTags[0]) == 'r' && tolower(tempTags[1]) == '\0') || (tolower(tempTags[0]) == '0' && tolower(tempTags[1]) == '\0')) {
        rptr3:

        printf("%s %sAre you sure you want to abort? (Y/N) : %s", prefix, CMD_COL_RED, CMD_COL_RESET);
        char confirmation = tolower(getchar());

        switch (confirmation) {
            case 'y':
                if (tolower(tempTags[0]) == 'r') {
                    userPanel(path, username);
                } else {
                    exitThanks('y');
                    exit(0);
                }
            case 'n':
                printf("Restarting bot creation...");
                Sleep(2000);

                goto rptr0;
            default:
                printf("\n%sThat was a wrong choice! Please provide a valid input (Y/N)%s", CMD_COL_RED, CMD_COL_RESET);
                goto rptr3;
        }
    } else {
        // Processing + Error Handling

        // 1. Check if it contains any comma(s)...
        //    - if not, make sure the the whole input is not greater than 10
        //    - if it does, seperate strings with commas and check if they too aren't greater than 10
        // 2. After separation check each separated string if it contains any spaces...
        //    - if it does, remove all spaces and merge everything into one string
        // 3. Now treat all those separated strings as finalized, and save them one by one in "tags" array
    } 

    free(lsThick);
    free(lsThin);

    return result;
}