#include <stdio.h>
#include <pthread.h>

int count = 0;

void *increment(void *arg) {
    int i;
    for (i = 0; i < 100000; i++) {
        count++;
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;
    pthread_create(&t1, NULL, increment, NULL);
    pthread_create(&t2, NULL, increment, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("Count: %d\n", count);
    return 0;
}
