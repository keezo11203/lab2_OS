/* signals.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int handler_invoked = 0; // Global variable to track if the handler is invoked

void handler(int signum)
{ // Signal handler
  printf("Hello World!\n");
  handler_invoked = 1; // Set the flag to indicate handler invocation
}

int main(int argc, char *argv[])
{
  signal(SIGALRM, handler); // Register handler to handle SIGALRM
  alarm(1);                 // Schedule a SIGALRM for 1 second

  while (!handler_invoked)
  {
    // Busy wait for signal to be delivered
  }

  printf("Turing was right!\n"); // Additional print after handler invocation
  return 0;
}
