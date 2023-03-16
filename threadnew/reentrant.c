#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void reentrant(char* message) {
    printf("Reentrant function: %s\n", message);
}
void *thread_func(void *arg) {
    char *message = (char*) arg;
    reentrant(message);
    return NULL;
}
int main() {
    pthread_t thread1, thread2;
    char* message1 = "Hello from Thread 1";
    char* message2 = "Hello from Thread 2";

    pthread_create(&thread1, NULL, thread_func, message1);
    pthread_create(&thread2, NULL, thread_func, message2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}
