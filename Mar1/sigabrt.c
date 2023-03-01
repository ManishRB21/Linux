#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void sigabrt_handler(int sig)
{
    printf("Caught SIGABRT signal!\n");
    exit(1);
}

int main()
{
    signal(SIGABRT, sigabrt_handler);

    abort();

    return 0;
}
