#include<stdio.h>
#include<unistd.h>
int main(){
char *args[]={"/home/lg/Process/exec",NULL};
execvp(args[0],args);
printf("Ending....");
return 0;
}
