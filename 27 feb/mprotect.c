#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    int fd = open("test.txt", O_RDWR); 
    if (fd == -1) {
        perror("open failed");
        exit(EXIT_FAILURE);
    }

    struct stat sb;
    if (fstat(fd, &sb) == -1) { 
        perror("fstat failed");
        exit(EXIT_FAILURE);
    }

    void *ptr = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);  // map file into memory
    if (ptr == MAP_FAILED) {
        perror("mmap failed");
        exit(EXIT_FAILURE);
    }

    printf("File mapped into memory at address %p with PROT_READ\n", ptr);

    if (mprotect(ptr, sb.st_size, PROT_READ | PROT_WRITE) == -1) { 
        perror("mprotect failed");
        exit(EXIT_FAILURE);
    }

    printf("File protection changed to PROT_READ | PROT_WRITE\n");

    if (munmap(ptr, sb.st_size) == -1) { 
        perror("munmap failed");
        exit(EXIT_FAILURE);
    }

    printf("Memory released\n");

    if (close(fd) == -1) { 
        perror("close failed");
        exit(EXIT_FAILURE);
    }

    printf("File closed\n");

    return 0;
}
