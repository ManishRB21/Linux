#include <unistd.h>
#include <stdio.h>

int main()
{
    const char* existing_file = "/home/lg/day28/link.c";

    const char* new_link = "/home/lg/day28/hardlink.txt";
    
    int result = link(existing_file, new_link);
    
    if (result == 0) {
        printf("Hard link created successfully.\n");
    } else {
        perror("Error creating hard link");
    }
    
    return 0;
}
