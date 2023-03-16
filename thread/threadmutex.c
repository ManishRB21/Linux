#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define COUNT_TO  100000
#define MAX_THREADS 12 

pthread_mutex_t mutex; 
long long i = 0;
pthread_t tid[MAX_THREADS];
void *start_counting(void *arg) {
    for (;;) {
        pthread_mutex_lock(&mutex);
        if (i >= COUNT_TO) {
            pthread_mutex_unlock(&mutex);
            return NULL;
        }
        ++i;
	printf("i = %lld\n",i);
        pthread_mutex_unlock(&mutex);

    }
}

int main(void) {
    int i = 0;
    for (i = 0; i < MAX_THREADS; ++i) {
        pthread_create(&(tid[i]), NULL, start_counting, NULL);
    }

    for (i = 0; i < MAX_THREADS; ++i) {
        pthread_join(tid[i], NULL);
    }
    return EXIT_SUCCESS;
}
