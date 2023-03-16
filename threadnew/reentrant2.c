#include <stdio.h>
#include <pthread.h>

void *increment(void *arg) {
    int* count_ptr = (int*)arg;
    int i;
    for (i = 0; i < 100000; i++) {
        (*count_ptr)++;
    }
    return NULL;
}

int main() {
    int count1 = 0, count2 = 0;
    pthread_t t1, t2;
    pthread_create(&t1, NULL, increment, &count1);
    pthread_create(&t2, NULL, increment, &count2);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("Count 1: %d\n", count1);
    printf("Count 2: %d\n", count2);
    return 0;
}
