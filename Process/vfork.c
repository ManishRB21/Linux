#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main(){
pid_t pid;
printf("parent\n");
pid =vfork();
if(pid==0){
printf("child\n");
}
return 0;
}
