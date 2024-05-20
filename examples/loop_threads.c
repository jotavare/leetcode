#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int mails = 0;
pthread_mutex_t mutex;

void *routine()
{
    for (int i = 0; i < 10000000; i++)
    {
        pthread_mutex_lock(&mutex);
        mails++;
        pthread_mutex_unlock(&mutex);
    }
}

int main(int ac, char **av)
{
    int nThreads = 4;
    pthread_t th[nThreads];
    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < nThreads; i++)
    {
        if (pthread_create(&th[i], NULL, &routine, NULL) != 0)
        {
            perror("Failed to create thread.");
            return 1;
        }
        printf("Thread %d has started.\n", i);
    }

    for (int i = 0; i < nThreads; i++)
    {
        if (pthread_join(th[i], NULL) != 0)
        {
            perror("Failed to join thread.");
            return 2;
        }
        printf("Thread %d has finished execution.\n", i);
    }

    pthread_mutex_destroy(&mutex);
    printf("Number of mails: %d\n", mails);
    return 0;
}