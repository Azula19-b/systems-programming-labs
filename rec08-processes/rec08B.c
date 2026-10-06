/* 
Name: Bahar Ozer
Description: Create a zombie process.
*/

#include <stdio.h>      // perror
#include <stdlib.h>     // exit system
#include <unistd.h>     // fork sleep
#include <sys/types.h>  // pid_t

int main(void)
{
    pid_t pid;          // process id

    pid = fork();       // create child

    if (pid == 0)
    {
        exit(0);        // child exits fast
    }
    else if (pid > 0)
    {
        sleep(5);       // parent waits
        system("ps -e -o pid,ppid,stat,user,cmd | grep $USER");  // show zombie
    }
    else
    {
        perror("fork error");  // fork failed
        exit(1);
    }

    return 0;           // end
}
