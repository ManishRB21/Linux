#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
    struct stat st;
    char* filename = "lstat.c";


    if (lstat(filename, &st) == -1) {
        perror("lstat");
        exit(EXIT_FAILURE);
    }


    printf("File type: ");
    switch (st.st_mode & S_IFMT) {
        case S_IFREG:
            printf("regular file\n");
            break;
        case S_IFDIR:
            printf("directory\n");
            break;
        case S_IFLNK:
            printf("symbolic link\n");
            break;
        default:
            printf("unknown file type\n");
            break;
    }

    printf("File size: %lld bytes\n", (long long) st.st_size);
    printf("Owner ID: %d\n", st.st_uid);
    printf("Group ID: %d\n", st.st_gid);

    return 0;
}
