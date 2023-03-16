#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>

int main() {
    int shmid1, shmid2;
    key_t key1, key2;
    char *shmaddr1, *shmaddr2;
    int size = 1024;

    key1 = ftok(".", 'A');
    key2 = ftok(".", 'B');

if ((shmid1 = shmget(key1, size,IPC_CREAT| IPC_EXCL | 0666)) == -1) {
        perror("shmget");
        exit(1);
    }
    if ((shmid2 = shmget(key2, size,IPC_CREAT|  IPC_EXCL | 0666)) == -1) {
        perror("shmget");
        exit(1);
    }

    if ((shmaddr1 = shmat(shmid1, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }
    if ((shmaddr2 = shmat(shmid2, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    sprintf(shmaddr1, "Hello, shared memory 1!");


    sprintf(shmaddr2, "Hello, shared memory 2!");

    printf("Shared memory 1: %s\n", shmaddr1);
    printf("Shared memory 2: %s\n", shmaddr2);

    if (shmdt(shmaddr1) == -1) {
        perror("shmdt");
        exit(1);
    }
     if (shmdt(shmaddr2) == -1) {
        perror("shmdt");
        exit(1);
    }
    if (shmctl(shmid1, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }
    if (shmctl(shmid2, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}
