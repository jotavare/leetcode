#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>

/*
 * Lock will always wait for the lock to be available.
 * Trylock will return immediately if the lock is not available.
 */

pthread_mutex_t mutex;

void* routine(void* arg)
{
    if(pthread_mutex_trylock(&mutex) == 0)
    {
        printf("Got lock\n");
        sleep(1);
        pthread_mutex_unlock(&mutex);
    }
    else
    {
        printf("Didn't get lock.\n");
    }
}

int main(int ac, char **av)
{
    int threads = 4;
    pthread_t th[threads];

    pthread_mutex_init(&mutex, NULL);

    for(int i = 0; i < threads; i++)
    {
        if(pthread_create(&th[i], NULL, &routine, NULL) != 0)
            perror("Failed to create thread.");
    }

    for(int i = 0; i < threads; i++)
    {
        if(pthread_join(th[i], NULL) != 0)
            perror("Failed to join thread.");
    }

    pthread_mutex_destroy(&mutex);

    return 0;
}
