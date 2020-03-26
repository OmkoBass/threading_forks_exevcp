#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <unistd.h>

#include <sys/wait.h>

void doSomething(void)
{
    int i = 0;

    for(i = 0; i < 12; i++)
    {
        sleep(rand() % 2);
        printf("Done with %d iteration.\n", i);
    }
}

int main() 
{ 
    printf("I am: %d\n", (int) getpid());

    pid_t pid = fork();
    printf("Fork returned %d\n", (int) pid);

    if(pid < 0)
    {
        perror("Fork failed");
    }
    else if(pid == 0)
    {
        printf("I am the child with pid %d\n", (int) getpid());
        doSomething();
        exit(0);
    }

    //We must be parent
    printf("I am the parent, waiting for child to end.\n");
    wait(NULL);
    printf("Parent ending...\n");

    return 0; 
} 