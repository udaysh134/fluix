// Headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <ctype.h>

#include "../include/colors.h"
#include "../include/utils.h"
#include "../include/data.h"
#include "../include/bot.h"
#include "../include/user.h"
#include "../packages/cJson/cJSON.h"
/*
----------------------------------------------------------------------------------------------------
MAIN FUNCTIONS
----------------------------------------------------------------------------------------------------
*/

void optView(char path[], char username[], char bot_name[]) {
    system("cls");
    char *lsThick = lineSep('=', 50);
    char *lsThin = lineSep('-', 50);

    char botFilePath[256];
    snprintf(botFilePath, sizeof(botFilePath), "%s\\%s.json", path, bot_name);

    char *jsonText = readJSON(botFilePath);
    if (!jsonText) {
        printf("%sFailed to read bot file.%s\n", CMD_COL_RED, CMD_COL_RESET);
        free(lsThick); free(lsThin);
        return;
    }

    cJSON *root = cJSON_Parse(jsonText);
    free(jsonText);

    if (!root) {
        printf("%sInvalid JSON file.%s\n", CMD_COL_RED, CMD_COL_RESET);
        free(lsThick); free(lsThin);
        return;
    }

    cJSON *entries = cJSON_GetObjectItem(root, "entries");
    if (!cJSON_IsArray(entries)) {
        printf("%sNo entries found.%s\n", CMD_COL_YELLOW, CMD_COL_RESET);
        cJSON_Delete(root);
        free(lsThick); free(lsThin);
        return;
    }

    // Header
    char menu[1024];
    snprintf(menu, sizeof(menu),
        "%s"
        "\n%s\t   USER PANEL - %s"
        "%s%s%s"
        "\n\t      (%s)"
        "\n%s"
        "\n(View Entries)"
        "\n%s\n",
        lsThick,
        CMD_COL_GREEN, CMD_COL_RESET,
        CMD_COL_BLACK, username, CMD_COL_RESET,
        bot_name,
        lsThick,
        lsThin
    );
    printf("%s", menu);

    int count = cJSON_GetArraySize(entries);
    if (count == 0) {
        printf("%sNo questions added yet.%s\n", CMD_COL_YELLOW, CMD_COL_RESET);
        cJSON_Delete(root);
        free(lsThick); free(lsThin);
        return;
    }

    for (int i = 0; i < count; i++) {
        cJSON *entry = cJSON_GetArrayItem(entries, i);

        printf("\n%sID:%s %d\n", CMD_COL_MAGENTA, CMD_COL_RESET,
               cJSON_GetObjectItem(entry, "id")->valueint);

        printf("%sQ:%s %s\n", CMD_COL_CYAN, CMD_COL_RESET,
               cJSON_GetObjectItem(entry, "question")->valuestring);

        printf("%sA:%s %s\n", CMD_COL_GREEN, CMD_COL_RESET,
               cJSON_GetObjectItem(entry, "answer")->valuestring);

        printf("%sTags:%s ", CMD_COL_YELLOW, CMD_COL_RESET);
        cJSON *tags = cJSON_GetObjectItem(entry, "tags");
        for (int t = 0; t < cJSON_GetArraySize(tags); t++) {
            printf("#%s ", cJSON_GetArrayItem(tags, t)->valuestring);
        }

        printf("\n%s\n", lsThin);
    }

    cJSON_Delete(root);
    printf("Press any key to continue! : ");
    getchar();
    
    free(lsThick);
    free(lsThin);
}

void optAdd(char path[], char username[], char bot_name[]) {
    system("cls");
    char *prefix = inputPrefix();
    char *lsThick = lineSep('=', 50);
    char *lsThin = lineSep('-', 50);

    char botFilePath[256];
    snprintf(botFilePath, sizeof(botFilePath), "%s\\%s.json", path, bot_name);

    char *jsonText = readJSON(botFilePath);
    if (!jsonText) {
        printf("%sFailed to read bot file.%s\n", CMD_COL_RED, CMD_COL_RESET);
        free(lsThick); free(lsThin);
        return;
    }

    cJSON *root = cJSON_Parse(jsonText);
    free(jsonText);

    if (!root) {
        printf("%sInvalid JSON.%s\n", CMD_COL_RED, CMD_COL_RESET);
        free(lsThick); free(lsThin);
        return;
    }

    cJSON *entries = cJSON_GetObjectItem(root, "entries");
    if (!cJSON_IsArray(entries)) {
        cJSON_Delete(root);
        free(lsThick); free(lsThin);
        return;
    }

    // Header
    char menu[1024];
    snprintf(menu, sizeof(menu),
        "%s"
        "\n%s\t   USER PANEL - %s"
        "%s%s%s"
        "\n\t      (%s)"
        "\n%s"
        "\n(Add Entry)"
        "\n%s\n",
        lsThick,
        CMD_COL_GREEN, CMD_COL_RESET,
        CMD_COL_BLACK, username, CMD_COL_RESET,
        bot_name,
        lsThick,
        lsThin
    );
    printf("%s", menu);

    // Determine next ID
    int nextID = 1;
    int size = cJSON_GetArraySize(entries);
    if (size > 0) {
        cJSON *last = cJSON_GetArrayItem(entries, size - 1);
        nextID = cJSON_GetObjectItem(last, "id")->valueint + 1;
    }

    char question[512];
    char answer[1024];
    char tag[128];

    printf("%s %sEnter Question: %s", prefix, CMD_COL_CYAN, CMD_COL_RESET);
    fgets(question, sizeof(question), stdin);
    question[strcspn(question, "\n")] = '\0';

    printf("%s %sEnter Answer: %s", prefix, CMD_COL_CYAN, CMD_COL_RESET);
    fgets(answer, sizeof(answer), stdin);
    answer[strcspn(answer, "\n")] = '\0';

    cJSON *entry = cJSON_CreateObject();
    cJSON_AddNumberToObject(entry, "id", nextID);
    cJSON_AddStringToObject(entry, "question", question);
    cJSON_AddStringToObject(entry, "answer", answer);

    cJSON *tags = cJSON_CreateArray();
    printf("%s %sEnter tags (empty to finish): %s\n", prefix, CMD_COL_CYAN, CMD_COL_RESET);

    while (1) {
        printf("%s ", prefix);
        fgets(tag, sizeof(tag), stdin);
        tag[strcspn(tag, "\n")] = '\0';

        if (strlen(tag) == 0)
            break;

        cJSON_AddItemToArray(tags, cJSON_CreateString(tag));
    }

    cJSON_AddItemToObject(entry, "tags", tags);
    cJSON_AddItemToArray(entries, entry);

    char *updatedJSON = cJSON_Print(root);
    FILE *fp = fopen(botFilePath, "w");
    if (fp) {
        fwrite(updatedJSON, 1, strlen(updatedJSON), fp);
        fclose(fp);
    }

    free(updatedJSON);
    cJSON_Delete(root);

    printf("\n%sEntry added successfully!%s\n", CMD_COL_GREEN, CMD_COL_RESET);
    Sleep(2000);
    
    free(lsThick);
    free(lsThin);
}

void optEdit(char path[], char username[], char bot_name[]) {
    system("cls");
    char *prefix = inputPrefix();
    char *lsThick = lineSep('=', 50);
    char *lsThin = lineSep('-', 50);

    char botFilePath[256];
    snprintf(botFilePath, sizeof(botFilePath), "%s\\%s.json", path, bot_name);

    char *jsonText = readJSON(botFilePath);
    if (!jsonText) {
        printf("%sFailed to read bot file.%s\n", CMD_COL_RED, CMD_COL_RESET);
        free(lsThick); free(lsThin);
        Sleep(2000);
        return;
    }

    cJSON *root = cJSON_Parse(jsonText);
    free(jsonText);

    if (!root) {
        printf("%sInvalid JSON.%s\n", CMD_COL_RED, CMD_COL_RESET);
        free(lsThick); free(lsThin);
        Sleep(2000);
        return;
    }

    cJSON *entries = cJSON_GetObjectItem(root, "entries");
    if (!cJSON_IsArray(entries)) {
        printf("%sNo entries found or invalid structure.%s\n", CMD_COL_YELLOW, CMD_COL_RESET);
        cJSON_Delete(root);
        free(lsThick); free(lsThin);
        Sleep(2000);
        return;
    }

    // Header
    char menu[1024];
    snprintf(menu, sizeof(menu),
        "%s"
        "\n%s\t   USER PANEL - %s"
        "%s%s%s"
        "\n\t      (%s)"
        "\n%s"
        "\n(Edit Entry)"
        "\n%s\n",
        lsThick,
        CMD_COL_GREEN, CMD_COL_RESET,
        CMD_COL_BLACK, username, CMD_COL_RESET,
        bot_name,
        lsThick,
        lsThin
    );
    printf("%s", menu);

    int id;
    printf("%s %sEnter ID to edit: %s", prefix, CMD_COL_CYAN, CMD_COL_RESET);
    scanf("%d", &id);
    eatBuffer();

    int found = 0;
    int size = cJSON_GetArraySize(entries);
    cJSON *targetEntry = NULL;

    for (int i = 0; i < size; i++) {
        cJSON *entry = cJSON_GetArrayItem(entries, i);
        if (cJSON_GetObjectItem(entry, "id")->valueint == id) {
            targetEntry = entry;
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("%sEntry with ID %d not found.%s\n", CMD_COL_RED, id, CMD_COL_RESET);
        cJSON_Delete(root);
        free(lsThick); free(lsThin);
        Sleep(2000);
        return;
    }

    // Edit Menu
    printf("\n%sWhat to edit?%s\n", CMD_COL_YELLOW, CMD_COL_RESET);
    printf("(1) Question\n");
    printf("(2) Answer\n");
    printf("(3) Tags\n");
    printf("(0) Cancel\n");
    printf("%s %sSelect option: %s", prefix, CMD_COL_CYAN, CMD_COL_RESET);
    
    char choice = getchar();
    eatBuffer();

    if (choice == '0') {
        cJSON_Delete(root);
        free(lsThick); free(lsThin);
        return;
    }

    char buffer[1024];

    switch (choice) {
        case '1':
            printf("%s %sEnter new Question: %s", prefix, CMD_COL_CYAN, CMD_COL_RESET);
            fgets(buffer, sizeof(buffer), stdin);
            buffer[strcspn(buffer, "\n")] = '\0';
            cJSON_ReplaceItemInObject(targetEntry, "question", cJSON_CreateString(buffer));
            break;
        case '2':
            printf("%s %sEnter new Answer: %s", prefix, CMD_COL_CYAN, CMD_COL_RESET);
            fgets(buffer, sizeof(buffer), stdin);
            buffer[strcspn(buffer, "\n")] = '\0';
            cJSON_ReplaceItemInObject(targetEntry, "answer", cJSON_CreateString(buffer));
            break;
        case '3': {
            cJSON *newTags = cJSON_CreateArray();
            printf("%s %sEnter new tags (empty to finish): %s\n", prefix, CMD_COL_CYAN, CMD_COL_RESET);
            char tagBuf[128];
            while (1) {
                printf("%s ", prefix);
                fgets(tagBuf, sizeof(tagBuf), stdin);
                tagBuf[strcspn(tagBuf, "\n")] = '\0';
                if (strlen(tagBuf) == 0) break;
                cJSON_AddItemToArray(newTags, cJSON_CreateString(tagBuf));
            }
            cJSON_ReplaceItemInObject(targetEntry, "tags", newTags);
            break;
        }
        default:
            printf("%sInvalid choice!%s\n", CMD_COL_RED, CMD_COL_RESET);
            cJSON_Delete(root);
            free(lsThick); free(lsThin);
            Sleep(2000);
            return;
    }

    char *updatedJSON = cJSON_Print(root);
    FILE *fp = fopen(botFilePath, "w");
    if (fp) {
        fwrite(updatedJSON, 1, strlen(updatedJSON), fp);
        fclose(fp);
    }

    free(updatedJSON);
    cJSON_Delete(root);

    printf("\n%sEntry updated successfully!%s\n", CMD_COL_GREEN, CMD_COL_RESET);
    Sleep(2000);
    
    free(lsThick);
    free(lsThin);
}

void optDelete(char path[], char username[], char bot_name[]) {
    system("cls");
    char *prefix = inputPrefix();
    char *lsThick = lineSep('=', 50);
    char *lsThin = lineSep('-', 50);

    char botFilePath[256];
    snprintf(botFilePath, sizeof(botFilePath), "%s\\%s.json", path, bot_name);

    char *jsonText = readJSON(botFilePath);
    if (!jsonText) {
        printf("%sFailed to read bot file.%s\n", CMD_COL_RED, CMD_COL_RESET);
        free(lsThick); free(lsThin);
        return;
    }

    cJSON *root = cJSON_Parse(jsonText);
    free(jsonText);

    if (!root) {
        printf("%sInvalid JSON.%s\n", CMD_COL_RED, CMD_COL_RESET);
        free(lsThick); free(lsThin);
        return;
    }

    cJSON *entries = cJSON_GetObjectItem(root, "entries");
    if (!cJSON_IsArray(entries)) {
        cJSON_Delete(root);
        free(lsThick); free(lsThin);
        return;
    }

    // Header
    char menu[1024];
    snprintf(menu, sizeof(menu),
        "%s"
        "\n%s\t   USER PANEL - %s"
        "%s%s%s"
        "\n\t      (%s)"
        "\n%s"
        "\n(Delete Entry)"
        "\n%s\n",
        lsThick,
        CMD_COL_GREEN, CMD_COL_RESET,
        CMD_COL_BLACK, username, CMD_COL_RESET,
        bot_name,
        lsThick,
        lsThin
    );
    printf("%s", menu);

    int id;
    printf("%s %sEnter ID to delete: %s", prefix, CMD_COL_CYAN, CMD_COL_RESET);
    scanf("%d", &id);
    eatBuffer();

    int found = 0;
    int size = cJSON_GetArraySize(entries);

    for (int i = 0; i < size; i++) {
        cJSON *entry = cJSON_GetArrayItem(entries, i);
        if (cJSON_GetObjectItem(entry, "id")->valueint == id) {
            cJSON_DeleteItemFromArray(entries, i);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("%sEntry with ID %d not found.%s\n", CMD_COL_RED, id, CMD_COL_RESET);
        cJSON_Delete(root);
        free(lsThick); free(lsThin);
        Sleep(2000);
        return;
    }

    char *updatedJSON = cJSON_Print(root);
    FILE *fp = fopen(botFilePath, "w");
    if (fp) {
        fwrite(updatedJSON, 1, strlen(updatedJSON), fp);
        fclose(fp);
    }

    free(updatedJSON);
    cJSON_Delete(root);

    printf("\n%sEntry deleted successfully!%s\n", CMD_COL_GREEN, CMD_COL_RESET);
    Sleep(2000);
    
    free(lsThick);
    free(lsThin);
}