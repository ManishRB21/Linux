#include<stdio.h>
#include<unistd.h>
int main(){
printf("process 1\n");
execl("/home/lg/Process/a2","a2",0); 
}
