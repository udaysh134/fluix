#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000
// ITS UPDATED VERSION OF MAINKANTS PROTO I HAD JUST INCLUDED JASON FILE IN IT 

/*Function to remove a specific sentence from the json file 
--------------------------------------------------------------------*/
void removeSentence(const char *filename, const char *sentenceToRemove) {
     FILE *file = fopen("data.json", "r");
     char buffer[MAX];

     if (file == NULL) {
          perror("Error opening file");
          return;
     }

     /* Temporary file to store updated content
     ------------------------------------------------*/
     FILE *tempFile = fopen("temp.json", "w");
     if (tempFile == NULL) {
          perror("Error opening temporary file");
          fclose(file);
          return;
     }

     /* it will Read each line and write to temp file if it doesn't match the sentence to remove
     --------------------------------------------------------------------------------------------*/
     while (fgets(buffer, MAX, file) != NULL) {
          if (strstr(buffer, sentenceToRemove) == NULL) {
               fputs(buffer, tempFile);
          }
     }

     fclose(file);
     fclose(tempFile);
     remove("data.json");
     rename("temp.json", "data.json");
     printf("Sentence removed successfully.\n");
}

/* Main function to demonstrate the removal of the sentence from the json file 
---------------------------------------------------*/
int main() {
     const char *filename = "data.json";  // Not strictly needed here
     const char *sentenceToRemove = "This is the sentence to be removed.";
     removeSentence(filename, sentenceToRemove);
     return 0;
}
