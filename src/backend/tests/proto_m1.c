#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1000
// Function to remove a specific sentence from the file
void removeSentence(const char *filename, const char *sentenceToRemove) {
    FILE *file = fopen("PSIT.txt", "r");
     if (file == NULL) {
          perror("Error opening file");
          return ;
     }
     char buffer[MAX];
// Temporary file to store updated content
     FILE *tempFile = fopen("temp.txt", "w");
     if (tempFile == NULL) {
          perror("Error opening temporary file");
          fclose(file);
          return ;
     }
// Read each line and write to temp file if it doesn't match the sentence to remove
     while (fgets(buffer, MAX, file) != NULL) {
          if (strstr(buffer, sentenceToRemove) == NULL) {
               fputs(buffer, tempFile);
          }
     }
// Close both files and replace original file with updated content
     fclose(file);
     fclose(tempFile);
     remove("PSIT.txt");
     rename("temp.txt", "PSIT.txt");
     printf("Sentence removed successfully.\n");
}
int main()
// Main function to demonstrate the removal
{
     const char *filename = "PSIT.txt";
     const char *sentenceToRemove = "This is the sentence to be removed.";
     removeSentence(filename, sentenceToRemove);
     return 0;
}


