#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *rotine()
{
    printf("Testing threads!\n");
    sleep(3);
    printf("Ending thread...\n");
}

int main(int ac, char **av)
{
    pthread_t t1, t2;

    if (pthread_create(&t1, NULL, &rotine, NULL) != 0)
        return 1;
    if (pthread_create(&t2, NULL, &rotine, NULL) != 0)
        return 2;
    if (pthread_join(t1, NULL) != 0)
        return 3;
    if (pthread_join(t2, NULL) != 0)
        return 4;

    return 0;
}