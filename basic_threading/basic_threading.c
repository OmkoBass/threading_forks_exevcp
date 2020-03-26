#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_function(void *arg)
{
    int *x;
    long int allocated = 1000000000000000;

    x = malloc(sizeof(int) * allocated);

    printf("Allocated %ld elements!\n", allocated);

    return NULL;
}

int main()
{
    pthread_t my_thread;

    printf("Before Thread\n");

    pthread_create(&my_thread, NULL, thread_function, NULL);
    pthread_join(my_thread, NULL);

    printf("Finished thread\n");

    return 0;
}