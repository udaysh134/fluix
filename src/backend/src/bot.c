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
#include "../include/data.h"

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

    char *prefix = inputPrefix();
    char *lsThick = lineSep('=', 50);
    char *lsThin = lineSep('-', 50);

    char resDesc[1000], resTags[50] = "", tempTags[50] = "";

    if (strcmp(res.desc, "") != 0) {
        strcpy(resDesc, res.desc);
    } else {
        strcpy(resDesc, CMD_COL_BLACK "[ SKIPPED ]" CMD_COL_RESET);
    }

    if (strcmp(res.tags[0], "") != 0) {
        if (
            (strcmp(res.tags[0], "") != 0) &&
            (strcmp(res.tags[1], "") == 0) &&
            (strcmp(res.tags[2], "") == 0) &&
            (strcmp(res.tags[3], "") == 0)
        ) {
            snprintf(tempTags, sizeof(tempTags), "%s", res.tags[0]);
            strcpy(resTags, tempTags);
        } else if (
            (strcmp(res.tags[0], "") != 0) &&
            (strcmp(res.tags[1], "") != 0) &&
            (strcmp(res.tags[2], "") == 0) &&
            (strcmp(res.tags[3], "") == 0)
        ) {
            snprintf(tempTags, sizeof(tempTags), "%s, %s", res.tags[0], res.tags[1]);
            strcpy(resTags, tempTags);
        } else if (
            (strcmp(res.tags[0], "") != 0) &&
            (strcmp(res.tags[1], "") != 0) &&
            (strcmp(res.tags[2], "") != 0) &&
            (strcmp(res.tags[3], "") == 0)
        ) {
            snprintf(tempTags, sizeof(tempTags), "%s, %s, %s", res.tags[0], res.tags[1], res.tags[2]);
            strcpy(resTags, tempTags);
        } else {
            snprintf(tempTags, sizeof(tempTags), "%s, %s, %s, %s", res.tags[0], res.tags[1], res.tags[2], res.tags[3]);
            strcpy(resTags, tempTags);
        }
    } else {
        strcpy(resTags, CMD_COL_BLACK "[ SKIPPED ]" CMD_COL_RESET);
    }


    // Execution starts from here
    // system("cls");

    char printOptions[1024];
    snprintf(printOptions, sizeof(printOptions),
        "%s"
        "\n%s\t   USER PANEL - %s"
        "%s%s%s"
        "\n\t      (Bot Creation)"
        "\n%s"
        "\n%sName :%s %s"
        "\n%sDescription :%s %s"
        "\n%sTags :%s %s"
        "\n%s"
        "\n",

        lsThick,
        CMD_COL_GREEN, CMD_COL_RESET,
        CMD_COL_BLACK, username, CMD_COL_RESET,
        lsThick,
        CMD_COL_CYAN, CMD_COL_RESET, res.name,
        CMD_COL_CYAN, CMD_COL_RESET, resDesc,
        CMD_COL_CYAN, CMD_COL_RESET, resTags,
        lsThin
    );
    printf("%s", printOptions);

    free(lsThick);
    free(lsThin);
    getchar();


    /*
    char confirmation[10];

    printf("%sBot creation data collected:%s\n", CMD_COL_GREEN, CMD_COL_RESET);
    printf("Name:        %s\n", res.name);
    printf("Description: %s\n", res.desc);

    if(res.tags[0][0]=='\0'){
    
          printf("Tags:        %sTAGS WERE SKIPPED %s\n", CMD_COL_RED,CMD_COL_RESET);

    }else{

        printf("Tags:        %s, %s, %s\n", res.tags[0], res.tags[1], res.tags[2]);
    }

    Sleep(1000);

    printf("%s>> Do you want to finalize these credentials? (Yes/No)%s: "CMD_COL_YELLOW, CMD_COL_RESET);
    scanf("%9s", confirmation);
    eatBuffer();

    if (tolower(confirmation[0]) == 'y' || tolower(confirmation[1]) == 'e' || tolower(confirmation[2]) == 's') {
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
    access_block_1: 
    
      system("cls");
      char *prefix = inputPrefix();
      char *lsThick = lineSep('=', 50);
      char *lsThin = lineSep('-', 50);

      //char name[10];
      //char desc[1002] = "";
      //char tags[3][12] = {0};

      /*char tempName[10];
      char tempDesc[1002];
      char tempTags[40] = "";*/

      char user_choice1[6];

      int fileCount = 0;
      char user_choice2[5];
      int flag =0;

      SearchResult res;

      res = searchDir(path, "file", 1, "");
      if (res.code == 0) fileCount = res.count;
      char printOptions[512];
       
      snprintf(printOptions, sizeof(printOptions), "%s\n%s\t   USER PANEL - %s%s%s%s\n%s(V) - View bot data\n(E) - Edit bot contents\n(D) - Delete bot data/bot file\n(R) - Return back to main menu\n(0) - Exit program\n%s\n", lsThick, CMD_COL_GREEN, CMD_COL_RESET, CMD_COL_MAGENTA, username, CMD_COL_RESET, lsThick, CMD_COL_BLACK, fileCount, CMD_COL_RESET, lsThin);
      printf(printOptions);

      printf("%s %sChoose an option from above to proceed: %s", prefix, CMD_COL_YELLOW, CMD_COL_RESET);
      fgets(user_choice1, sizeof(user_choice1), stdin);
      user_choice1[strcspn(user_choice1, "\n")] = '\0';

      switch(tolower(user_choice1[0])){

        case 'v':
            optView(path, username);
            break;
        case 'e':
            optEdit(path, username);
            break;
        case 'd':
            optDelete(path, username);
            break;
        case 'r':
            userPanel(path, username);
            break;
        case '0':
            exitThanks('y');
            exit(0);
            break;
        default:
            printf("\n%sThat was a wrong choice! Please provide a valid input from the options above.%s", CMD_COL_RED, CMD_COL_RESET);
            goto access_block_1;
      }

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



    // ------=>> | BOT'S NAME SECTION | <<=------
    rptrName:

    printf("%s %sNAME%s of the bot? : ", prefix, CMD_COL_CYAN, CMD_COL_RESET);
    scanf("%s", tempName);
    eatBuffer();
    
    if((tolower(tempName[0]) == 'r' && tolower(tempName[1]) == '\0') || (tolower(tempName[0]) == '0' && tolower(tempName[1]) == '\0')) {
        rptr1:

        printf("%s\n%s %sAre you sure you want to abort? (Y/N) : %s", lsThin, prefix, CMD_COL_RED, CMD_COL_RESET);
        char confirmation = tolower(getchar());

        switch (confirmation) {
            case 'y':
                if (tolower(tempName[0]) == 'r') {
                    userPanel(path, username);
                } else {
                    exitThanks('y');

                    free(lsThick);
                    free(lsThin);

                    exit(0);
                }
            case 'n':
                eatBuffer();
                goto rptrName;
            default:
                printf("\n%sThat was a wrong choice! Please provide a valid input (Y/N)%s", CMD_COL_RED, CMD_COL_RESET);
                goto rptr1;
        }
    } else {
        // Error Handling ---------------------------------------- >>
        if(!isStrClean(tempName)) {
            printf("%sError : You can only have alphabets and numbers in your bot name.%s\n", CMD_COL_RED, CMD_COL_RESET);
            goto rptrName;
        }

        if (strlen(tempName) < 3) {
            printf("%sError : Name of your bot should be of atleast 3 or more letters.%s\n", CMD_COL_RED, CMD_COL_RESET);
            goto rptrName;
        }

        if (strlen(tempName) > 8) {
            printf("%sError : Name of your bot cannot be of more than 8 letters.%s\n", CMD_COL_RED, CMD_COL_RESET);
            goto rptrName;
        }

        SearchResult res;
        res = searchDir(path, "file", 0, tempName);

        if (res.code == 0) {
            printf("%sError : A bot with the same name already exists, please choose another name.%s\n", CMD_COL_RED, CMD_COL_RESET);
            goto rptrName;
        }

        // Processing ---------------------------------------- >>
        int o = 0;

        while(tempName[o] != '\0') {
            tempName[o] = (char)tolower((unsigned char)tempName[o]);
            o++;
        }
        
        strcpy(name, tempName);
        strcpy(result.name, name);
    }



    // ------=>> | BOT'S DESCRIPTION SECTION | <<=------
    rptrDesc:

    printf("%s %sDESCRIPTION%s of the bot? %s[Optional]%s : ", prefix, CMD_COL_CYAN, CMD_COL_RESET, CMD_COL_BLACK, CMD_COL_RESET);
    fgets(tempDesc, sizeof(tempDesc), stdin);

    tempDesc[strcspn(tempDesc, "\n")] = '\0';

    if(((tolower(tempDesc[0]) == 'r') && (tempDesc[1] == '\0')) || ((tolower(tempDesc[0]) == '0') && (tempDesc[1] == '\0'))) {
        rptr2:

        printf("%s\n%s %sAre you sure you want to abort? (Y/N) : %s", lsThin, prefix, CMD_COL_RED, CMD_COL_RESET);
        char confirmation = tolower(getchar());

        switch (confirmation) {
            case 'y':
                if (tolower(tempDesc[0]) == 'r') {
                    userPanel(path, username);
                } else {
                    exitThanks('y');

                    free(lsThick);
                    free(lsThin);

                    exit(0);
                }
            case 'n':
                eatBuffer();
                goto rptrDesc;
            default:
                printf("\n%sThat was a wrong choice! Please provide a valid input (Y/N)%s", CMD_COL_RED, CMD_COL_RESET);
                goto rptr2;
        }
    } else if (tempDesc[0] == '\0') {
        strcpy(desc, "");
        strcpy(result.desc, desc);
    } else {
        // Error Handling ---------------------------------------- >>
        if (strlen(tempDesc) < 15) {
            printf("%sError : Description of your bot should be of atleast 15 or more letters.%s\n", CMD_COL_RED, CMD_COL_RESET);
            goto rptrDesc;
        }

        if (strlen(tempDesc) > 1000) {
            printf("%sError : Description of your bot cannot be of more than 1000 letters.%s\n", CMD_COL_RED, CMD_COL_RESET);
            goto rptrDesc;
        }

        // Processing ---------------------------------------- >>
        int read = 0;
        int write = 0;

        while (tempDesc[read] != '\0') {
            if (tempDesc[read] != '"' && tempDesc[read] != '\\') {
                tempDesc[write] = tempDesc[read];
                write++;
            }
            
            read++;
        }

        tempDesc[write] = '\0';

        strcpy(desc, tempDesc);
        strcpy(result.desc, desc);
    }



    // ------=>> | BOT'S TAGS SECTION | <<=------
    rptrTags:

    printf("%s %sTAGS%s for the bot? Separate by comma(s), no space. %s[Optional]%s : ", prefix, CMD_COL_CYAN, CMD_COL_RESET, CMD_COL_BLACK, CMD_COL_RESET);
    fgets(tempTags, sizeof(tempTags), stdin);

    tempTags[strcspn(tempTags, "\n")] = '\0';

    if(((tolower(tempTags[0]) == 'r') && (tempTags[1] == '\0')) || ((tolower(tempTags[0]) == '0') && (tempTags[1] == '\0'))) {
        rptr3:

        printf("%s\n%s %sAre you sure you want to abort? (Y/N) : %s", lsThin, prefix, CMD_COL_RED, CMD_COL_RESET);
        char confirmation = tolower(getchar());

        switch (confirmation) {
            case 'y':
                if (tolower(tempTags[0]) == 'r') {
                    userPanel(path, username);
                } else {
                    exitThanks('y');

                    free(lsThick);
                    free(lsThin);

                    exit(0);
                }
            case 'n':
                eatBuffer();
                goto rptrTags;
            default:
                printf("\n%sThat was a wrong choice! Please provide a valid input (Y/N)%s", CMD_COL_RED, CMD_COL_RESET);
                goto rptr3;
        }    
    } else if (tempTags[0] == '\0') {
        strcpy(result.tags[0], "");
        strcpy(result.tags[1], "");
        strcpy(result.tags[2], "");
    } else {
        // Error Handling ---------------------------------------- >>
        int i = 0, flag = 1;

        while (tempTags[i] != '\0') {
            tempTags[i] = tolower((unsigned char)tempTags[i]);

            if (tempTags[i] == ',') {
                flag++;
            }
            
            i++;
        }

        if (flag > 3) {
            printf("%sError : You cannot have more than 3 tags for your bot.%s\n", CMD_COL_RED, CMD_COL_RESET);
            goto rptrTags;
        }

        // Processing ---------------------------------------- >>
        char tagsStorage[3][12];
        int j = 0;
        char *token = strtok(tempTags, ",");


        while (token != NULL) {
            strcpy(tagsStorage[j], token);
            token = strtok(NULL, ",");
            j++;
        }

        // Error Handling ---------------------------------------- >>
        for (int m = 0; m < 3; m++) {
            for (int n = 0; n < 12; n++) {
                char strChar = tagsStorage[m][n];

                if(ispunct(strChar)) {
                    printf("%sError : No special characters are allowed with tags.%s\n", CMD_COL_RED, CMD_COL_RESET);
                    goto rptrTags;
                }

                if(strChar == 32) {
                    printf("%sError : No spaces are allowed with tags.%s\n", CMD_COL_RED, CMD_COL_RESET);
                    goto rptrTags;
                }

                if (strlen(tagsStorage[m]) > 10) {
                    printf("%sError : Your tags cannot contain more than 10 characters.%s\n", CMD_COL_RED, CMD_COL_RESET);
                    goto rptrTags;
                }
            }
        }

        // Processing ---------------------------------------- >>
        int k = 0;

        while (k < 3) {
            strcpy(tags[k], tagsStorage[k]);
            strcpy(result.tags[k], tags[k]);

            k++;
        }
    }

    free(lsThick);
    free(lsThin);

    return result;
}