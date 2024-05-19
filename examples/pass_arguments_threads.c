#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void *rotine(void* arg)
{
    int index = *(int*)arg;
    int sum = 0;

    for(int i = 0; i < 5; i++)
    {
        sum += primes[index + i];
    }

    printf("Local sum: %d\n", sum);

    *(int*)arg = sum;
    return arg;
}

int main(int ac, char **av)
{
    pthread_t th[2];

    for (int i = 0; i < 2; i++)
    {
        int* a = malloc(sizeof(int));
        *a = i * 5;
        if (pthread_create(&th[i], NULL, &rotine, a) != 0)
            perror("Failed to create thread.\n");
    }

    int total_sum = 0;

    for (int i = 0; i < 2; i++)
    {
        int* value;
        if (pthread_join(th[i], (void**)&value) != 0)
            perror("Failed to join thread.\n");
        total_sum += *value;
        free(value);
    }

    printf("Total sum: %d\n", total_sum);

    return 0;
}