#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_COUNT 200
#define BUF_SIZE 100

int main(void)
{
    pid_t pid;
    int i;
    char buf[BUF_SIZE];

    pid = fork();

    if (pid < 0)
    {
        fprintf(stderr, "Fork failed\n");
        return 1;
    }
    else if (pid == 0)
    {
        // Child process
        for (i = 1; i <= MAX_COUNT; i++)
        {
            sprintf(buf, "   This line is from child, value = %d\n", i);
            write(STDOUT_FILENO, buf, strlen(buf)); // Using write() for unbuffered output
        }
    }
    else
    {
        // Parent process
        for (i = 1; i <= MAX_COUNT; i++)
        {
            sprintf(buf, "This line is from parent, value = %d\n", i);
            printf("%s", buf);
        }
    }

    return 0;
}
