#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    int shmid;
    key_t key = 1234; 
    

    if ((shmid = shmget(key, 1024, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }


    char *shmaddr;
    if ((shmaddr = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }


    sprintf(shmaddr, "Hello, shared memory!");


    if (shmdt(shmaddr) == -1) {
        perror("shmdt");
        exit(1);
    }


    if ((shmaddr = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }


    printf("%s\n", shmaddr);


    if (shmdt(shmaddr) == -1) {
        perror("shmdt");
        exit(1);
    }


    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}
