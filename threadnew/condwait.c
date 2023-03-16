#include <pthread.h>
#include <stdio.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int flag = 0;

void* thread1(void* arg) {
    printf("Thread 1: acquiring lock...\n");
    pthread_mutex_lock(&mutex);
    while (flag == 0) {
        printf("Thread 1: waiting for signal...\n");
        pthread_cond_wait(&cond, &mutex);
    }
    printf("Thread 1: received signal, flag = %d\n", flag);
    pthread_mutex_unlock(&mutex);
    printf("Thread 1: releasing lock...\n");
    return NULL;
}

void* thread2(void* arg) {
    printf("Thread 2: acquiring lock...\n");
    pthread_mutex_lock(&mutex);
    printf("Thread 2: setting flag to 1...\n");
    flag = 1;
    printf("Thread 2: signaling thread 1...\n");
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&mutex);
    printf("Thread 2: releasing lock...\n");
    return NULL;
}

int main() {
    pthread_t t1, t2;
    pthread_create(&t1, NULL, thread1, NULL);
    pthread_create(&t2, NULL, thread2, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}
