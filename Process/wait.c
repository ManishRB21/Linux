#include<stdio.h>
#include<sys/wait.h>

#include<unistd.h>
int main(){
pid_t p;
printf("before fork\n");
p=fork();
if(p==0){
printf("child ID %d\n",getpid());
printf("parent ID %d\n", getppid());
}
else{
wait(NULL);
printf("child ID %d\n",p);
printf("parent ID %d\n",getpid());
}
printf("common\n");
}
