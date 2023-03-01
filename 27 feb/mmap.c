#include<stdio.h>
#include<stdlib.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char *argv[]) {
int fd;
struct stat st;
char *addr;

if (argc != 2) { 
 fprintf(stderr, "Usage: %s <file>\n", argv[0]);
 exit(1);
}
fd = open(argv[1], O_RDONLY);  
if (fd == -1) {
perror("open");
exit(1);
}
if (fstat(fd, &st) == -1) {
 perror("fstat");
exit(EXIT_FAILURE);
}








addr = mmap(NULL,st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
if (addr == MAP_FAILED) {
        perror("mmap");
        exit(1);
}

close(fd);
printf("memmory %p\n",addr);
printf("%s\n",addr);
if (munmap(addr,st.st_size) == -1) {
perror("munmap");
exit(1);
}
printf("memory unmapped\n");
exit(EXIT_SUCCESS);
}

