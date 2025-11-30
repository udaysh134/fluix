//file: bot.c
//Description: File which will integrate QnA, parser aand other essential parsers functions
//Required files to initiate bot.c: user.c, db.JSON, parser.env


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include <ctype.h>

#include "../include/user.h"
#include "../packages/cJson/cJSON.h"
#include "../include/bot.h"

#include "../include/QNA.h"


/*
// WHAT's NEEDED TO BE CODED IN BOT.C FILE:
void Create_Bot();  //Once coded, this will allow user to create new bots {PENDING}
void Access_Bot(); //Once coded, this will allow user to access their bots {PENDING}
void Edit_Bot();  //Once coded, this will allow user to edit their existing bots {PENDING}
Void Ask_Fluix(); //Once coded, this will allow user to ask questions to their bot {DONE function uses: QNA.c , dbstruct002.json , cJSON library}


void Access_Bot(){

     // Here, we will give user the choice to whether update, ask questions or delete their bot database

     printf("\t\tWelcome to FLuix, {USERNAME_HERE}!\n\tWhat's the agenda today?");
     char choice[7];
     printf("1. Ignite your curiousity with FLUIX");
     printf("\n2. Update your bot  ");
     printf("\n3. Create a new bot\n")
   
     printf("Enter valid choice number from above options: ");
     fgets(choice,sizeof(choice),stdin);

     switch(choice){

          case '1':
               //Allow user to interact with their bots
               //Ask_Fluix();
               break;

          case '2':
               //Update existing bot according to user preferences
               //Edit_Bot();
               break;

          case '3':
               //Allow user to create new bot
               //Create_Bot();
               break;
          case '4':
              //Exit from bot access menu
              printf("Exiting from FLUIX bot access menu...\n");
              break;
              
          default:
               //invalid choice
               printf("Uhh-ohh!!\nYour input choice seems to be invalid :(\nPlease try again :)\n");
               

     }

}


int main(){
    return 0;
}
*/