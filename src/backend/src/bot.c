// Headers
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <inttypes.h>

#include "../include/colors.h"
#include "../include/utils.h"
#include "../include/user.h"
#include "../include/data.h"

#include "../packages/cJson/cJSON.h"

// Definitions
#define SCHEMA_VERSION 1.0

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

    // Processing data before displaying ---------------------------------------- >>
    char *prefix = inputPrefix();
    char *lsThick = lineSep('=', 50);
    char *lsThin = lineSep('-', 50);
    int tagsCount = 3;

    char resDesc[1000], resTags[50] = "";

    // For DESCRIPTION
    (strcmp(res.desc, "") != 0) ? (strcpy(resDesc, res.desc)) : (strcpy(resDesc, CMD_COL_BLACK "[ SKIPPED ]" CMD_COL_RESET));

    // For TAGS
    int found = 0;
    for (int i = 0; i < tagsCount; i++) {
        if (strcmp(res.tags[i], "") != 0) {
            if (found != 0) { strncat(resTags, ", ", sizeof(resTags) - strlen(resTags) - 1); }
            
            strncat(resTags, res.tags[i], sizeof(resTags) - strlen(resTags) - 1);
            found = 1;
        }
    }

    if (!found) { strcpy(resTags, CMD_COL_BLACK "[ SKIPPED ]" CMD_COL_RESET); }


    // Execution starts from here ---------------------------------------- >>
    system("cls");

    char printOptions[1024];
    snprintf(printOptions, sizeof(printOptions),
        "%s"
        "\n%s\t   USER PANEL - %s"
        "%s%s%s"
        "\n\t      (Bot Creation)"
        "\n%s"
        "\n(o) %sName%s : %s"
        "\n(o) %sDescription%s : %s"
        "\n(o) %sTags%s : %s"
        "\n%s"
        "\n",

        lsThick,
        CMD_COL_GREEN, CMD_COL_RESET,
        CMD_COL_BLACK, username, CMD_COL_RESET,
        lsThick,
        CMD_COL_MAGENTA, CMD_COL_RESET, res.name,
        CMD_COL_MAGENTA, CMD_COL_RESET, resDesc,
        CMD_COL_MAGENTA, CMD_COL_RESET, resTags,
        lsThin
    );
    printf("%s", printOptions);

    printf("%s %sWould you like to continue with this? (Y/N)%s : ", prefix, CMD_COL_CYAN, CMD_COL_RESET);
    char confirmation = tolower(getchar());


    switch (confirmation) {
        case 'y':
            printf("Creating your bot...");
            Sleep(2000);
            printf("\nPlease wait...");
            Sleep(3000);

            // Read "user_config.json" and extract value of "maxBots" to use it as bot ID
            char configPath[100];
            snprintf(configPath, sizeof(configPath), "%s\\user_config.json", path);

            char *userConfig = readJSON(configPath);
            if (!userConfig) {
                printf("%sInternal Error! Failed to read the user file.%s", CMD_COL_RED, CMD_COL_RESET);
                Sleep(1000);
                printf("Exiting the program!%s", CMD_COL_RESET);
                Sleep(2000);

                free(lsThin);
                exit(0);
            }

            cJSON *userConfigRoot = cJSON_Parse(userConfig);
            free(userConfig);

            if (!userConfigRoot) {
                printf("%sInternal Error! Invalid JSON!%s", CMD_COL_RED, CMD_COL_RESET);
                Sleep(1000);
                printf("Exiting the program!%s", CMD_COL_RESET);
                Sleep(2000);

                free(lsThin);
                exit(0);
            }

            cJSON *maxBots = cJSON_GetObjectItem(userConfigRoot, "maxBots");

            // Creating final JSON object here
            int maxBotsValue = maxBots->valueint;
            uint64_t creationTime = getEpochTime();

            cJSON *tags = cJSON_CreateArray();
                for (int i = 0; i < tagsCount; i++) { cJSON_AddItemToArray(tags, cJSON_CreateString(res.tags[i])); }

            cJSON *bot = cJSON_CreateObject();
                cJSON_AddNumberToObject(bot, "id", (maxBotsValue + 1));
                cJSON_AddStringToObject(bot, "name", res.name);
                cJSON_AddStringToObject(bot, "description", res.desc);
                cJSON_AddItemToObject(bot, "tags", tags);
                cJSON_AddNumberToObject(bot, "entryCount", 0);
                cJSON_AddNumberToObject(bot, "maxEntries", 0);
                cJSON_AddStringToObject(bot, "owner", username);
                cJSON_AddNumberToObject(bot, "createdAt", creationTime);
                cJSON_AddNumberToObject(bot, "modifiedAt", creationTime);

            cJSON *root = cJSON_CreateObject();
                cJSON_AddNumberToObject(root, "schemaVersion", SCHEMA_VERSION);
                cJSON_AddItemToObject(root, "bot", bot);
                cJSON_AddArrayToObject(root, "entries");

            char *txt = cJSON_Print(root);
            char botFilePath[100];
            snprintf(botFilePath, sizeof(botFilePath), "%s\\%s.json", path, res.name);

            FILE *createdBotFile = fopen(botFilePath, "w");
            if (!createdBotFile) {
                printf("%sCouldn't create the bot file. Internal Error!%s", CMD_COL_RED, CMD_COL_RESET);
                Sleep(1000);
                printf("Exiting the program!%s", CMD_COL_RESET);
                Sleep(2000);

                free(lsThin);
                free(txt);
                exit(0);
            }

            fprintf(createdBotFile, txt);
            fclose(createdBotFile);
            free(txt);

            // Updating "user_config" with incremented value for "maxBots"
            maxBots->valueint = maxBotsValue + 1;
            cJSON_SetIntValue(maxBots, maxBotsValue + 1);

            char *updatedUserJSON = cJSON_Print(userConfigRoot);

            FILE *fp = fopen(configPath, "wb");
            if (fp) {
                fwrite(updatedUserJSON, 1, strlen(updatedUserJSON), fp);
                fclose(fp);
            }

            free(updatedUserJSON);
            cJSON_Delete(root);
            break;
        case 'n':
            printf("NO");
            break;
        default:
            break;
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

    SearchResult res;
    res = searchDir(path, "file", 1, "");
    
    // Filter and collect valid bots
    char botNames[50][MAX_PATH];
    int botCount = 0;

    if (res.code == 0) {
        for (int i = 0; i < res.count; i++) {
            if (strcmp(res.names[i], "user_config.json") != 0) {
                // Strip .json extension for display
                char *dot = strrchr(res.names[i], '.');
                if (dot && strcmp(dot, ".json") == 0) {
                    size_t len = dot - res.names[i];
                    strncpy(botNames[botCount], res.names[i], len);
                    botNames[botCount][len] = '\0';
                    botCount++;
                }
            }
        }
    }

    // List Bots
    char listMenu[2048] = "";
    char botListStr[1024] = "";

    if (botCount == 0) {
        snprintf(botListStr, sizeof(botListStr), "%sNo bots found. Go create one!%s", CMD_COL_YELLOW, CMD_COL_RESET);
    } else {
        for (int i = 0; i < botCount; i++) {
            char line[100];
            snprintf(line, sizeof(line), "(%d) %s\n", i + 1, botNames[i]);
            strcat(botListStr, line);
        }
        
        botListStr[strlen(botListStr) - 1] = '\0';
    }

    snprintf(listMenu, sizeof(listMenu),
        "%s"
        "\n%s\t   USER PANEL - %s"
        "%s%s%s"
        "\n\t      (Access Bots)"
        "\n%s"
        "\n%s"
        "\n%s"
        "\n(R) - Return back"
        "\n(0) - Exit"
        "\n%s"
        "\n",
        lsThick,
        CMD_COL_GREEN, CMD_COL_RESET,
        CMD_COL_BLACK, username, CMD_COL_RESET,
        lsThick,
        botListStr,
        lsThin,
        lsThin
    );
    printf("%s", listMenu);


    // Selection
    printf("%s %sSelect a bot (number) or option: %s", prefix, CMD_COL_CYAN, CMD_COL_RESET);
    
    char inputBuffer[100];
    fgets(inputBuffer, sizeof(inputBuffer), stdin);
    inputBuffer[strcspn(inputBuffer, "\n")] = '\0';

    if (tolower(inputBuffer[0]) == 'r' && inputBuffer[1] == '\0') {
        free(lsThick);
        free(lsThin);
        userPanel(path, username);
        return;
    } else if (inputBuffer[0] == '0' && inputBuffer[1] == '\0') {
        exitThanks('y');
        exit(0);
    }

    int selection = atoi(inputBuffer);
    if (selection < 1 || selection > botCount) {
        printf("%sInvalid selection!%s\n", CMD_COL_RED, CMD_COL_RESET);
        Sleep(1000);
        free(lsThick);
        free(lsThin);
        goto access_block_1;
    }

    char *selectedBot = botNames[selection - 1];

    // Bot Operation Menu
    bot_menu:
    system("cls");

    char botMenu[1024];
    snprintf(botMenu, sizeof(botMenu),
        "%s"
        "\n%s\t   USER PANEL - %s"
        "%s%s%s"
        "\n\t      (%s)"
        "\n%s"
        "\n(V) - View entries"
        "\n(A) - Add entry"
        "\n(E) - Edit entry"
        "\n(D) - Delete entry"
        "\n(R) - Return to Bot List"
        "\n(0) - Exit"
        "\n%s"
        "\n",
        lsThick,
        CMD_COL_GREEN, CMD_COL_RESET,
        CMD_COL_BLACK, username, CMD_COL_RESET,
        selectedBot,
        lsThick,
        lsThin
    );
    printf("%s", botMenu);

    printf("%s %sChoose an action: %s", prefix, CMD_COL_CYAN, CMD_COL_RESET);
    
    char action = tolower(getchar());
    eatBuffer();

    switch (action) {
        case 'v':
            optView(path, username, selectedBot);
            goto bot_menu;
        case 'a':
            optAdd(path, username, selectedBot);
            goto bot_menu;
        case 'e':
            optEdit(path, username, selectedBot);
            goto bot_menu;
        case 'd':
            optDelete(path, username, selectedBot);
            goto bot_menu;
        case 'r':
            free(lsThick);
            free(lsThin);
            goto access_block_1;
        case '0':
            exitThanks('y');
            exit(0);
        default:
            printf("%sInvalid option!%s\n", CMD_COL_RED, CMD_COL_RESET);
            Sleep(1000);
            goto bot_menu;
    }

    free(lsThick);
    free(lsThin);
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

    printf("%s %sDESCRIPTION%s? %s[ Optional ]%s : ", prefix, CMD_COL_CYAN, CMD_COL_RESET, CMD_COL_BLACK, CMD_COL_RESET);
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

    printf("%s %sTAGS%s? Separate by comma(s), no space. %s[ Optional ]%s : ", prefix, CMD_COL_CYAN, CMD_COL_RESET, CMD_COL_BLACK, CMD_COL_RESET);
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