#include <unistd.h>
#include <stdio.h>

int main()
{
    const char* target_path = "/home/lg/day28/symlink.c";
    const char* link_path = "/home/lg/day28/symlink.txt";
    
    int result = symlink(target_path, link_path);
    
    if (result == 0) {
        printf("Symbolic link created successfully.\n");
    } else {
        perror("Error creating symbolic link");
    }
    
    return 0;
}
