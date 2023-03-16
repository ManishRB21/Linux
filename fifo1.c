#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
int main(){
int fd;
char *myfifo = "/home/lg/ipc/myfifo";
char arr1[90], arr2[80];
mkfifo(myfifo,0666);
while(1){
fd= open(myfifo,O_WRONLY);
fgets(arr2,80,stdin);
write(fd,arr2,strlen(arr2)+1);
close(fd);
fd=open(myfifo,O_RDONLY);
read(fd,arr1,sizeof(arr1));
printf("user2 : %s\n",arr1);
close(fd);
}
return 0;
}
