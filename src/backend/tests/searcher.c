#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../packages/cJson/cJSON.h"


void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}


void removeNewline(char *str) {
    str[strcspn(str, "\n")] = '\0';
}

int main() {
    FILE *fp = fopen("dbstruct002.json", "r");
    if (!fp) {
        printf("Could not open dbstruct002.json\n");
        return 1;
    }

   
    char buffer[20000];
    size_t bytesRead = fread(buffer, 1, sizeof(buffer) - 1, fp);
    buffer[bytesRead] = '\0';
    fclose(fp);

    cJSON *json = cJSON_Parse(buffer);
    if (!json) {
        printf("Error parsing JSON!\n");
        return 1;
    }

    printf("Database loaded successfully.\n");
    printf("Type your question (or 'exit' to quit):\n\n");

    char userInput[512];

    while (1) {
        printf("You: ");
        fgets(userInput, sizeof(userInput), stdin);
        removeNewline(userInput);
        toLowerCase(userInput);

        if (strcmp(userInput, "exit") == 0) {
            printf("FLUIX AI: Goodbye, User!\n");
            break;
        }

        int bestMatchIndex = -1;
        int highestScore = 0;

        int totalItems = cJSON_GetArraySize(json);

       
        for (int i = 0; i < totalItems; i++) {
            cJSON *item = cJSON_GetArrayItem(json, i);
            cJSON *tags = cJSON_GetObjectItemCaseSensitive(item, "tags");

            int score = 0;
            if (cJSON_IsArray(tags)) {
                cJSON *tag = NULL;
                cJSON_ArrayForEach(tag, tags) {
                    char tagWord[100];
                    strcpy(tagWord, tag->valuestring);
                    toLowerCase(tagWord);
                    if (strstr(userInput, tagWord)) {
                        score++;
                    }
                }
            }

            if (score > highestScore) {
                highestScore = score;
                bestMatchIndex = i;
            }
        }

        if (highestScore == 0) {
            printf("Sorry, I don't have an answer for that.\n\n");
        } else {
            cJSON *bestItem = cJSON_GetArrayItem(json, bestMatchIndex);
            cJSON *answers = cJSON_GetObjectItemCaseSensitive(bestItem, "ans");

            printf("FLUIX AI: ");
            if (cJSON_IsArray(answers)) {
                cJSON *a = NULL;
                cJSON_ArrayForEach(a, answers) {
                    printf("%s ", a->valuestring);
                }
            } else {
                printf("%s", answers->valuestring);
            }
            printf("\n\n");
        }
    }

    cJSON_Delete(json);
    return 0;
}