/* timer.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int alarm_count = 0; // Global variable to track the number of alarms

void handler(int signum)
{ // Signal handler
  printf("Hello World!\n");
  alarm_count++;
}

void exit_handler(int signum)
{ // Signal handler for SIGINT
  printf("\nTotal time executed: %d seconds\n", alarm_count);
  exit(0);
}

int main(int argc, char *argv[])
{
  signal(SIGALRM, handler); // Register handler to handle SIGALRM
  signal(SIGINT, exit_handler); // Register handler to handle SIGINT

  alarm(1); // Schedule a SIGALRM for 1 second

  while (1)
  {
    // Busy wait for signals to be delivered
  }

  return 0; // Never reached
}
