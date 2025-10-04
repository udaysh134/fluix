// Headers
#include "admin.h"
#include "colors.h"
#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    while (1) {
        printf("What's the PASSCODE? : ");

        if (fgets(pass, sizeof(pass), stdin) == NULL) {
            printf("There was an error! Please provide a valid input.");
            break;
        }

        pass[strcspn(pass, "\n")] = '\0';

        if (strcmp(pass, configPass) == 0) {
            printf("You're now in ADMIN portal, but there's nothing to show here for now.");
            printf("\nPress any key to exit...");

            fgets(pass, sizeof(pass), stdin);

            break;
        } else {
            printf("That was a wrong try!\n");
        }
    }
}


/*
----------------------------------------------------------------------------------------------------
OTHER FUNCTIONS
----------------------------------------------------------------------------------------------------
*/