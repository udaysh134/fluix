// Headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

#include "../include/admin.h"
#include "../include/colors.h"
#include "../include/utils.h"

// Definitions
const char configPass[] = "fluixo"; //this code should be replaced if env parser is working fine

//this code to be used in replacement to the code line no.12 char *configPass = NULL;


/*
----------------------------------------------------------------------------------------------------
MAIN FUNCTION
----------------------------------------------------------------------------------------------------
*/
void isAdmin() {
    /*
     // Load password at runtime
    configPass = getEnvValue("PASS");  // This here will use exact key value from settings.env file

    if (configPass == NULL) {
        printf("%sAdmin password not configured in settings.env%s\n", CMD_COL_RED, CMD_COL_RESET);
        Sleep(2000);
        return;
    }*/
    // above commented code should be unfreezed upon replacing code line no.12
    char *prefix = inputPrefix();
    char *lsThick = lineSep('=', 50);
    char *lsThin = lineSep('-', 50);
    char pass[20];

    system("cls");
    
    while (1) {
        char jumpCode_1[] = "0";

        printf("%s%sWhat's the PASSCODE? : %s", prefix, CMD_COL_CYAN, CMD_COL_RESET);
        maskInput(pass, sizeof(pass));

        if (pass == NULL) {
            printf("%sThere was an error! Please provide a valid input.%s", CMD_COL_RED, CMD_COL_RESET);
            break;
        }

        pass[strcspn(pass, "\n")] = '\0';

        if (strcmp(pass, configPass) == 0) {
            system("cls");
            printf("%sAdmin Panel%s\n%s\nThere's nothing to show here for now.\n%s\n", CMD_COL_GREEN, CMD_COL_RESET, lsThick, lsThin);
            Sleep(2000);
            printf("%s%sPress \"Enter\" to go back or \"0\" to exit : %s", prefix, CMD_COL_CYAN, CMD_COL_RESET);

            free(lsThick);
            free(lsThin);

            char jumpCode_2 = getchar();

            if(jumpCode_2 == 48) { // 48 is 0 in ASCII
                exitThanks('y');
                exit(0);
            } else {
                system("cls");
                return;
            }
        } else if (strcmp(pass, jumpCode_1) == 0) {
            system("cls");
            return;
        } else {
            printf("%sThat was a wrong try! Press \"0\" to go back.%s\n", CMD_COL_RED, CMD_COL_RESET);
        }
    }
}


/*
----------------------------------------------------------------------------------------------------
OTHER FUNCTIONS
----------------------------------------------------------------------------------------------------
*/
