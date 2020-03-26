#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

char *caesar(char *word)
{
    int i = 0;
    while(word[i] != '\0')
    {
        word[i] = word[i] + 3;
        i++;

    }

    return word;
}

void *do_something(void *word)
{
    pthread_t thread;

    char *ceasered = (char*)pthread_create(&thread, NULL, (void*)caesar, word);

    pthread_join(thread, (void*)ceasered);

    wait(NULL);
    printf("Was waiting untill the word editing is done...\n");

    return word;
}

int main()
{
    printf("I am another file!\n");
    printf("execvp is running me!\n");

    char *word;

    printf("Enter a word to be caesared on another thread: ");
    scanf("%s", word);

    pid_t pid = fork();

    if(pid < 0)
    {
        perror("Error!");
    }
    else if(pid == 0)
    {
        printf("This is the child. ID: %d \n", (int) getpid());

        char *caesar = do_something(word);

        printf("Thread finished and the word is: %s\n", caesar);
        printf("Child finished...\n");
    }

    printf("Parent finished...\n");

    return 0;
}