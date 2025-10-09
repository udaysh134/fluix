#include <stdio.h>
#include <conio.h>  // for getch()

int main() {
    char password[50];
    int i = 0;
    char ch;

    printf("Enter password: ");

    while (1) {
        ch = getch();  // read character without showing it

        if (ch == 13) {  // Enter key (ASCII 13)
            password[i] = '\0';
            break;
        } 
        else if (ch == 8) {  // Backspace (ASCII 8)
            if (i > 0) {
                i--;
                printf("\b \b");  // erase last star
            }
        } 
        else {
            password[i++] = ch;
            printf("*");  // print star instead of character
        }
    }

    printf("\nYour password is: %s\n", password); // For testing — remove in real programs
    return 0;
}