#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
int pipefd[2];
char *pin;
char buffer[5];

if(pipe(pipefd)==-1){
perror("pipe");
exit(1);
}

pid_t pid = fork();
if(pid==0){
pin="1234\0";
close(pipefd[0]);
write(pipefd[1],pin,5);

printf("generating pin in child,sending to parent...\n");
sleep(2);
exit(1);
}

if(pid>0){
wait(NULL);
close(pipefd[1]);
read(pipefd[0],buffer,5);
close(pipefd[0]);
printf("parent pin is '%s'\n",buffer);
}
return 0;
}
