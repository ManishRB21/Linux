#include<stdio.h>
#include<unistd.h>
int main(){
char *args[]={"/home/lg/Process/exec1",NULL};
execv(args[0],args);
printf("ending...");
return 0;
}
