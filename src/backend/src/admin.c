// Headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <ctype.h>

#include "../include/admin.h"
#include "../include/colors.h"
#include "../include/utils.h"


/*
----------------------------------------------------------------------------------------------------
MAIN FUNCTION
----------------------------------------------------------------------------------------------------
*/
void isAdmin() {
    char *configPass = parseEnv(".\\src\\config\\settings.env", "PASS");

    if(!configPass) {
        printf("%sAn internal error occurred! Problem with ENV file.\n%s", CMD_COL_RED, CMD_COL_RESET);
        Sleep(1000);
        printf("Exiting the program!%s", CMD_COL_RESET);
        Sleep(2000);
        exit(0);
    }

    char *prefix = inputPrefix();
    char *lsThick = lineSep('=', 50);
    char *lsThin = lineSep('-', 50);
    char pass[20];

    system("cls");
    
    while (1) {
        char jumpCode_1[] = "0";

        printf("%s%sWhat's the PASSCODE? : %s", prefix, CMD_COL_CYAN, CMD_COL_RESET);
        maskInput(pass, sizeof(pass));

        if (!pass || pass == NULL) {
            printf("%sAn error occured. Please provide a valid input..%s\n", CMD_COL_RED, CMD_COL_RESET);
            break;
        }

        pass[strcspn(pass, "\n")] = '\0';

        if (strcmp(pass, configPass) == 0) {
            rptr1:

            system("cls");
            printf("%s\n%s\t\t   ADMIN PANEL%s\n%s\n(R) - Return back\n(0) - Exit\n%s\n", lsThick, CMD_COL_GREEN, CMD_COL_RESET, lsThick, lsThin);
            printf("%s%sWhat now? : %s", prefix, CMD_COL_CYAN, CMD_COL_RESET);

            char selection = getchar();

            switch (tolower(selection)) {
                case 'r':
                    system("cls");

                    free(configPass);
                    free(lsThick);
                    free(lsThin);

                    return;
                case '0':
                    exitThanks('y');

                    free(configPass);
                    free(lsThick);
                    free(lsThin);

                    exit(0);
                default:
                    goto rptr1;
            }
        } else if (strcmp(pass, jumpCode_1) == 0) {
            system("cls");

            free(configPass);
            free(lsThick);
            free(lsThin);
            
            return;
        } else {
            printf("%sThat was a wrong try! Press \"0\" to go back.%s\n", CMD_COL_RED, CMD_COL_RESET);
        }
    }
}