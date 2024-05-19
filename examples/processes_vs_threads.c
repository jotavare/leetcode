#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

/* int main(int ac, char **av)
{
    int x = 2;
    int pid = fork();
    if(pid == -1)
        return 1;

    printf("Process ID: %d\n", getpid());

    if (pid == 0)
        x++;

    sleep(2);

    printf("Value of x: %d\n", x);

    if(pid != 0)
        wait(NULL);

    return 0;
} */

int x = 2;


void *rotine()
{
    x++;
    sleep(2);
    printf("Value of x: %d\n", x);
}

void* rotine2()
{
    sleep(2);
    printf("Value of x: %d\n", x);
}


int main(int ac, char **av)
{
    pthread_t t1, t2;

    if (pthread_create(&t1, NULL, &rotine, NULL) != 0)
        return 1;
    if (pthread_create(&t2, NULL, &rotine2, NULL) != 0)
        return 2;
    if (pthread_join(t1, NULL) != 0)
        return 3;
    if (pthread_join(t2, NULL) != 0)
        return 4;

    return 0;
}