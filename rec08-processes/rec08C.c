/* 
Name: Bahar Ozer
Description: Create an orphan process.
*/

#include <stdio.h>      // printf perror
#include <stdlib.h>     // exit
#include <unistd.h>     // fork sleep getpid getppid
#include <sys/types.h>  // pid_t

int main(void)
{
    char *name;         // process name
    pid_t pid;          // process id

    pid = fork();       // create child

    if (pid == 0)
    {
        printf("child: %d started\n", getpid());      // child start
        printf("child: parent = %d\n", getppid());    // parent id
        printf("child: going to sleep\n");            // before sleep

        sleep(20);                                    // keep child alive

        printf("child: just woke up\n");              // after sleep
    }
    else if (pid > 0)
    {
        printf("parent: %d started\n", getpid());     // parent start
        printf("parent: parent = %d\n", getppid());   // parent's parent
    }
    else
    {
        perror("fork error");                         // fork failed
        exit(1);
    }

    name = (pid == 0) ? "child" : "parent";          // ternary
    printf("%s: terminating...\n", name);            // final line

    return 0;                                        // end
}
