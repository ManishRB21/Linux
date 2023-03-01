#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    struct stat file_stat;
    int fd=0;
    
 
    if (fstat(fd, &file_stat) < 0) {
        perror("Error getting file information");
        return 1;
    }
    

    printf("File size: %ld bytes\n", file_stat.st_size);
    printf("File owner: %d\n", file_stat.st_uid);
    printf("File group: %d\n", file_stat.st_gid);
    printf("File permissions: %o\n", file_stat.st_mode & 0777);
    
    return 0;
}
