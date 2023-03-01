#include <stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
pid_t p;
printf("before fork\n");
p=fork();
if (p==0){
printf("I'm child having ID %d\n",getpid());
printf("Parent ID is %d\n",getppid());
}
else{
printf("My child ID is %d\n",p);
printf("I'm parent having ID %d\n",getpid());
}
printf("common\n");
}
