#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/resource.h>
int main(){
uid_t uid;
gid_t gid;

printf("start\n");
sleep(2);
printf("UID : %d\n", getuid());
printf("GID : %d\n",getgid());
printf("set new UID, GID\n");
scanf("%d",&uid);
scanf("%d",&gid);
sleep(2);
setuid(uid);
printf("uid: %d\n", uid);
setgid(gid);
printf("gid: %d\n", gid);



return 0;
}
