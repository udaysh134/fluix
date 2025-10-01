#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include <conio.h>

void welcomeInput ();
void getPlayers();

char lineBreakThick[50] = "========================================";
char lineBreakThin[50] = "----------------------------------------";


int main () {
    srand(time(NULL));
    welcomeInput();

    int randomGenerated = rand() % 100 + 1;
    int guesses = 0;
    int guessedNum;

    printf("Guess the number : ");
    scanf("%d", &guessedNum);

    do {
        if (guessedNum < randomGenerated) {
            guesses++;
            printf("Wrong | Guess a little higher : ");
            scanf("%d", &guessedNum);
        }
        
        if (guessedNum > randomGenerated) {
            guesses++;
            printf("Wrong | Guess a little lower : ");
            scanf("%d", &guessedNum);
        }
        
        if (guessedNum == randomGenerated) {
            system("cls");

            guesses++;
            printf("Right | You guessed it (%d) and defeated me in %d guesses.", randomGenerated, guesses);
            printf("\n\nThanks for playing the Game!!\nHope you enjoyed!! See yo again!!");
        }
    } while (guessedNum != randomGenerated);
}


void welcomeInput () {
    system("cls");
    printf("Welcome to the NUMBER GUESSING GAME\n%s", lineBreakThick);
    Sleep(2000);

    printf("\n> Player(s) will be given unlimited time to guess a number from 1 to 100 and finish the game. Simple & Fun!!");
    Sleep(4000);
    printf("\n> If multiplayers, the one who guessed the number in least amount of guesses, will win the game.");
    Sleep(4000);

    printf("\n%s", lineBreakThin);
    printf("\n> So... Are you ready??");
    Sleep(1000);

    getPlayers();

    printf("Okay, let's start!!");
    Sleep(500);

    printf("\n3");
    Sleep(500);
    printf("\n2");
    Sleep(500);
    printf("\n1");
    Sleep(300);
    system("cls");
}


struct players {
    int number;
    char name[20];
};

void getPlayers() {
    int players;
    char namingChoice;
    char nameIfYes[20];
    char nameIfNo[20];

    struct players pl[10];

    askNoOfPlayers:
    printf("\n> Enter the number of players... ");
    scanf("%d", &players);

    if(players == 0 || players < 0) {
        printf("Please provide a valid value. The game cannot begin if there's no one to play!");
        goto askNoOfPlayers;
    } else if (players > 10) {
        printf("Sorry! You cannot have players more than 10. Please choose a lower number.");
        goto askNoOfPlayers;
    } else if (players < 11 && players > 0) {
        for (int i = 1; i < (players + 1); i++) {
            askNameOfPlayers:

            printf("\nWould you like to name Player_%d? (Y/N) : ", i);
            scanf(" %c", &namingChoice);

            switch (tolower(namingChoice)) {
                case 'y':
                        printf("Give a name to Player_%d : ", i);
                        fflush(stdin);
                        fgets(nameIfYes, sizeof(nameIfYes), stdin);
                        nameIfYes[strcspn(nameIfYes, "\n")] = 0;

                        printf("Okay, the name of Player_%d will be - %s\n%s", i, nameIfYes, lineBreakThin);

                        pl[i-1].number = i;
                        strcpy(pl[i-1].name, nameIfYes);
                    break;
                case 'n':
                        sprintf(nameIfNo, "Player_%d", i);
                        printf("Okay, the name of the Player_%d will be - Player_%d\n%s", i, i, lineBreakThin);

                        pl[i-1].number = i;
                        strcpy(pl[i-1].name, nameIfNo);
                    break;
                default:
                        printf("Oops! You didn't gave a valid input. Please try again, only use Y or N!");
                        goto askNameOfPlayers;
                    break;
            }
        }
        
        Sleep(3000);
        printf("\n%s%s\n", lineBreakThick, lineBreakThick);
        printf("Number of players joining this session are :\n\n");

        for (int i = 0; i < players; i++) {
            printf("%d. %s\n", pl[i].number, pl[i].name);
        }

        printf("\n%s%s\n", lineBreakThick, lineBreakThick);
        printf("Press enter when you're ready...");

        fflush(stdin);
        getchar();
    } else {
        printf("Oops!! An error occured, you gave an invalid input.");
    }
}