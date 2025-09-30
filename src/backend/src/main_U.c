#include <stdio.h>
#include <Windows.h>

char lineBreakThick[50] = "========================================";
char lineBreakThin[50] = "----------------------------------------";


int main () {
    int selecNum;

    system("cls");

    printf("Welcome to Fluix\n%s\n", lineBreakThick);
    Sleep(1000);
    printf("What would you like to do?\n");
    Sleep(1000);
    printf("(1) Sign In - For registered users\n(2) SignUp - For new users\n%s\n", lineBreakThin);

    scanf("%d", &selecNum);
}