#include<stdio.h>
#include<unistd.h>
int main(int argc, char *argv[]){
char * const envp[] = {"AA=11", "BB=22", NULL};
printf("Entering main ...\n");
int ret;
ret =execle("./hello", "hello", NULL, envp);
 if(ret == -1){
 perror("execl error");
}
printf("Exiting main ...\n");
return 0;
}
