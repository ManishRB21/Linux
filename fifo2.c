#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
int main(){
int fd1;
char *myfifo = "/home/lg/ipc/myfifo";
char str1[90], str2[80];
mkfifo(myfifo,0666);
while(1){
fd1= open(myfifo,O_RDONLY);
read(fd1,str1,90);
printf("user1 : %s\n",str1);
close(fd1);
fd1=open(myfifo,O_WRONLY);
fgets(str2,80,stdin);
write(fd1,str2,strlen(str2)+1);
close(fd1);
}
return 0;
}

