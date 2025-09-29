#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX_INPUT 256
void respond(const char *input) 
{
     if (strstr(input, "hello") || strstr(input, "hi")) {
          printf("Chatbot: Hello! How can I help you?\n");
     } else if (strstr(input, "name"))
      {
          printf("Chatbot: My name is GitHub Copilot.\n");
     } else if (strstr(input, "bye")) {
          printf("Chatbot: Goodbye!\n");
     } else {
          printf("Chatbot: I'm not sure how to respond to that.\n");
     }
} 
//advanced feature: simple math evaluation
int main() {
     char input[MAX_INPUT];
     printf("Chatbot: Hello! I am a simple chatbot. Type 'bye' to exit.\n");
     while (1) {
          printf("You: ");
          if (!fgets(input, MAX_INPUT, stdin)) break;
          // Remove newline
          input[strcspn(input, "\n")] = 0;
          if (strstr(input, "bye")) {
               respond(input);
               break;
          }
          respond(input);
     }

     return 0;
}