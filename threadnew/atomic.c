#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdatomic.h>

int non_atomic_counter = 0;
atomic_int atomic_counter =0;

void *increment_counters(void *arg) {
    for (int i = 0; i < 1000000; i++) {
        non_atomic_counter++; 
        atomic_counter++;
    }
    return NULL;
}

int main() {
    pthread_t threads[4];
        for (int i = 0; i < 4; i++) {
        if (pthread_create(&threads[i], NULL, increment_counters, NULL)) {
            fprintf(stderr, "Error creating thread\n");
            return 1;
        }
    }
        for (int i = 0; i < 4; i++) {
        if (pthread_join(threads[i], NULL)) {
            fprintf(stderr, "Error joining thread\n");
            return 1;
        }
    }
    printf("Non-atomic counter value: %d\n", non_atomic_counter);
    printf("Atomic counter value: %d\n", atomic_counter);
    return 0;
}
