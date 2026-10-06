/* 
Name: Bahar Ozer
Description: Create two children and run date and whoami.
*/

#include <stdio.h>      // printf
#include <stdlib.h>     // exit
#include <unistd.h>     // fork execlp getpid getppid
#include <sys/types.h>  // pid_t
#include <sys/wait.h>   // wait

int main(void)
{
    pid_t p1, p2;       // child pids
    int status;         // wait status

    p1 = fork();        // first child

    if (p1 < 0)
    {
        perror("fork error");   // fork failed
        exit(1);
    }
    else if (p1 == 0)
    {
        printf("child 1: pid = %d\n", getpid());      // child pid
        printf("child 1: parent = %d\n", getppid());  // parent pid

        execlp("date", "date", NULL);                 // run date
        perror("execlp error");                       // execlp failed
        _exit(1);                                     // stop child
    }

    p2 = fork();        // second child

    if (p2 < 0)
    {
        perror("fork error");   // fork failed
        exit(1);
    }
    else if (p2 == 0)
    {
        printf("child 2: pid = %d\n", getpid());      // child pid
        printf("child 2: parent = %d\n", getppid());  // parent pid

        execlp("whoami", "whoami", NULL);             // run whoami
        perror("execlp error");                       // execlp failed
        _exit(1);                                     // stop child
    }

    wait(&status);                                    // wait child
    printf("parent: a child terminated\n");           // parent message

    wait(&status);                                    // wait child
    printf("parent: a child terminated\n");           // parent message

    return 0;                                         // end
}
