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

    char botFilePath[256];
    snprintf(botFilePath, sizeof(botFilePath), "%s\\%s.json", path, bot_name);

    char *jsonText = readJSON(botFilePath);
    if (!jsonText) {
        printf("%sFailed to read bot file.%s\n", CMD_COL_RED, CMD_COL_RESET);
        return;
    }

    cJSON *root = cJSON_Parse(jsonText);
    free(jsonText);

    if (!root) {
        printf("%sInvalid JSON file.%s\n", CMD_COL_RED, CMD_COL_RESET);
        return;
    }

    cJSON *entries = cJSON_GetObjectItem(root, "entries");
    if (!cJSON_IsArray(entries)) {
        printf("%sNo entries found.%s\n", CMD_COL_YELLOW, CMD_COL_RESET);
        cJSON_Delete(root);
        return;
    }

    int count = cJSON_GetArraySize(entries);
    if (count == 0) {
        printf("%sNo questions added yet.%s\n", CMD_COL_YELLOW, CMD_COL_RESET);
        cJSON_Delete(root);
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

        printf("\n---------------------------------\n");
    }

    cJSON_Delete(root);
    system("pause");
}

void optAdd(char path[], char username[], char bot_name[]) {
    system("cls");

    char botFilePath[256];
    snprintf(botFilePath, sizeof(botFilePath), "%s\\%s.json", path, bot_name);

    char *jsonText = readJSON(botFilePath);
    if (!jsonText) {
        printf("%sFailed to read bot file.%s\n", CMD_COL_RED, CMD_COL_RESET);
        return;
    }

    cJSON *root = cJSON_Parse(jsonText);
    free(jsonText);

    if (!root) {
        printf("%sInvalid JSON.%s\n", CMD_COL_RED, CMD_COL_RESET);
        return;
    }

    cJSON *entries = cJSON_GetObjectItem(root, "entries");
    if (!cJSON_IsArray(entries)) {
        cJSON_Delete(root);
        return;
    }

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

    printf("Enter Question:\n> ");
    fgets(question, sizeof(question), stdin);
    question[strcspn(question, "\n")] = '\0';

    printf("Enter Answer:\n> ");
    fgets(answer, sizeof(answer), stdin);
    answer[strcspn(answer, "\n")] = '\0';

    cJSON *entry = cJSON_CreateObject();
    cJSON_AddNumberToObject(entry, "id", nextID);
    cJSON_AddStringToObject(entry, "question", question);
    cJSON_AddStringToObject(entry, "answer", answer);

    cJSON *tags = cJSON_CreateArray();
    printf("Enter tags (empty line to finish):\n");

    while (1) {
        printf("> ");
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

    printf("%sEntry added successfully!%s\n", CMD_COL_GREEN, CMD_COL_RESET);
    system("pause");
}

void optEdit(char path[], char username[], char bot_name[]) {};

void optDelete(char path[], char username[], char bot_name[]) {
    system("cls");

    char botFilePath[256];
    snprintf(botFilePath, sizeof(botFilePath), "%s\\%s.json", path, bot_name);

    char *jsonText = readJSON(botFilePath);
    if (!jsonText) {
        printf("%sFailed to read bot file.%s\n", CMD_COL_RED, CMD_COL_RESET);
        return;
    }

    cJSON *root = cJSON_Parse(jsonText);
    free(jsonText);

    if (!root) {
        printf("%sInvalid JSON.%s\n", CMD_COL_RED, CMD_COL_RESET);
        return;
    }

    cJSON *entries = cJSON_GetObjectItem(root, "entries");
    if (!cJSON_IsArray(entries)) {
        cJSON_Delete(root);
        return;
    }

    int id;
    printf("Enter ID to delete: ");
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
        system("pause");
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

    printf("%sEntry deleted successfully!%s\n", CMD_COL_GREEN, CMD_COL_RESET);
    system("pause");
}