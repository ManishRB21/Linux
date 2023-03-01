#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <sys/uio.h>
int main(){
struct iovec iov[3];
ssize_t n;
int fd, i;
 char *buf[] ={
"My name is manish ranjan behera.\n"
}; 

 fd = open ("alpha.txt", O_WRONLY | O_CREAT | O_TRUNC); 
if(fd==-1){
 perror ("open");
  return 1;
}
for (i=0;i<3;i++) {
iov[i].iov_base = buf[i];
iov[i].iov_len = strlen(buf[i]) + 1;
}
n = writev (fd,iov,3);
 if (n==-1) {
perror("writev");
 return 1;
}
 printf ("%ld bytes written\n", n);
if (pclose){ 
 perror ("close");
 return 1;
}
return 0;
}
