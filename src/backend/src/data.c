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
/*
----------------------------------------------------------------------------------------------------
MAIN FUNCTIONS
----------------------------------------------------------------------------------------------------
*/
void optView(char path[], char username[]){
     
     printf("%s>> Loading all bot file(s) under the username: %s...%s\n", CMD_COL_GREEN, username, CMD_COL_RESET);

     Sleep(2000);

     printf("%s>> Loaded all bot file(s) successfully!%s\n", CMD_COL_GREEN, CMD_COL_RESET);

     Sleep(1000);

     system("cls");

     char bot_name[10];

     printf("%s>> enter the name of the bot you want to view data from: %s", CMD_COL_YELLOW, CMD_COL_RESET);
     

     scanf("%s%9s %s",CMD_COL_BLUE,bot_name,CMD_COL_RESET);
     eatBuffer();

     printf("%s>> Fetching data from bot file: %s.json...%s\n", CMD_COL_GREEN, bot_name, CMD_COL_RESET);

     Sleep(2000);

     printf("%s>>CRITICAL ERROR: EVALUATION FILES MISSING< COMPLETE THE:%s\n", CMD_COL_RED, CMD_COL_RESET);

}


void optAdd() {};
void optEdit() {};
void optDelete() {};