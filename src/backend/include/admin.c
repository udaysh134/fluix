// Headers
#include "admin.h"
#include "colors.h"
#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

// Definitions
const char configPass[] = "fluixo";


/*
----------------------------------------------------------------------------------------------------
MAIN FUNCTION
----------------------------------------------------------------------------------------------------
*/
void isAdmin() {
    char *prefix = inputPrefix();
    char *lsThick = lineSep('=', 50);
    char *lsThin = lineSep('-', 50);
    char pass[20];

    system("cls");
    
    while (1) {
        printf("%s%sWhat's the PASSCODE? : %s", prefix, CMD_COL_CYAN, CMD_COL_RESET);

        if (fgets(pass, sizeof(pass), stdin) == NULL) {
            printf("%sThere was an error! Please provide a valid input.%s", CMD_COL_CYAN, CMD_COL_RESET);
            break;
        }

        pass[strcspn(pass, "\n")] = '\0';

        if (strcmp(pass, configPass) == 0) {
            system("cls");
            printf("%sYou're now in ADMIN portal%s\n%s\nThere's nothing to show here for now.\n%s\n", CMD_COL_GREEN, CMD_COL_RESET, lsThick, lsThin);
            Sleep(2000);
            printf("%sPress any key to go back or \"0\" to exit : ", prefix);

            free(lsThick);
            free(lsThin);

            char jumpCode = getchar();

            if(jumpCode == 48) { // 48 is 0 in ASCII                
                exit(0);
            } else {
                system("cls");
                return;
            }
        } else {
            printf("%sThat was a wrong try!%s\n", CMD_COL_RED, CMD_COL_RESET);
        }
    }
}


/*
----------------------------------------------------------------------------------------------------
OTHER FUNCTIONS
----------------------------------------------------------------------------------------------------
*/