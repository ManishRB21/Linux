#include <stdio.h>
#include <unistd.h>

int main()
{
int fd[2];
char buffer[20];
if (pipe(fd) == -1) {
perror("pipe");
return 1;
}
pid_t pid = fork();
if (pid == -1) {
perror("fork");
return 1;
}
if (pid == 0) {
close(fd[1]);
read(fd[0], buffer, sizeof(buffer));
printf("Child process received: %s\n", buffer);
close(fd[0]);
} else { 
close(fd[0]);
write(fd[1], "Hello, world!", 13);
close(fd[1]);     
}
return 0;
}
