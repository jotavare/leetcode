#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int mails = 0;

void *routine()
{
    for (int i = 0; i < 100000; i++)
        mails++;
}

int main(int ac, char **av)
{
    pthread_t t1, t2;

    if (pthread_create(&t1, NULL, &routine, NULL) != 0)
        return 1;
    if (pthread_create(&t2, NULL, &routine, NULL) != 0)
        return 2;
    if (pthread_join(t1, NULL) != 0)
        return 3;
    if (pthread_join(t2, NULL) != 0)
        return 4;

    printf("Number of mails: %d\n", mails);

    return 0;
}