#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/uio.h>
int main(){
int i,fd;
char f1[48], f2[51], f3[49];
struct iovec iov[3];
ssize_t n;
fd = open("test.txt", O_RDONLY);
if(fd==-1){
perror("open");
return 1;
}
iov[0].iov_base=f1;
iov[0].iov_len= sizeof (f1);
iov[1].iov_base =f2;
iov[1].iov_len= sizeof (f2);
iov[2].iov_base = f3;
iov[2].iov_len= sizeof (f3);
n = readv(fd,iov,3);
if(n==-1){
perror("readv");
return 1;
}
for(i=0;i<3;i++){
printf("%d: %s", i, (char *) iov[i].iov_base);
}
if(pclose){
perror("close");
return 1;
}
return 0;

}

