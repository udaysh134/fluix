#include<stdio.h>
#include<ctype.h>
#include<string.h>

void recdata(char Q[], char A[]){
    FILE *fp;
    static int Qcount=0;
    Qcount++;
    printf("\n\t\t\t***Registering Custom Questions & Answers***\n");
    fp = fopen("CustomQA.txt","a");
    if(fp == NULL){
        printf("Error opening file!\n");
        return;
    }
    fprintf(fp,"\nQ%d: %sA%d: %s\n", Qcount, Q, Qcount, A); 
    fclose(fp);
}



//void func1(){}

int main(){
    static int Qcount=0; 
    char choice, Q[84], A[1000];
    
        printf("\n\t\t\t***Welcome USER!***\n\n\t\t\tHow can you be assisted?\n");
        label:
        printf("\n\t1.I would like to register Custom Questions & Answers\n\t2.Delete registered intel\n\t3.Update registered intel\n\t4.Exit Program!\n");
        printf("Input valid choice number here: ");
        scanf("%c",&choice);
        printf("\r");

        if(choice=='1'){
            Qcount++;
            getchar(); // Clear newline character from input buffer
           
            printf("\nEnter your question: ");
            fgets(Q,84,stdin); // Read string with spaces
            printf("Enter your answer: ");
            fgets(A,1000,stdin); // Read string with spaces
            printf("\nYour question is:Q%d\t %s\nYour answer is:A%d\t%s\n",Qcount, Q,Qcount, A);
            recdata(Q ,A);
            goto label;

        }
        else if(choice=='2'){
            printf("\n\t\t\t***Updating coming soon!!!***\n");
            // Add code to delete registered intel
            goto label;
        }
        else if(choice=='3'){
            
            printf("\n\t\t\t***Updating coming soon!!!***\n");

            // Add code to update registered intel
            goto label;
        }
        else if(choice=='4'){
            printf("\nExiting Program...\n");
            return 0;
        }
        else{
            printf("\nInvalid choice! Please try again.\n");
            goto label; // Loop back for valid input

        }

        return 0;   }