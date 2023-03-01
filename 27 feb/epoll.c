#include <stdio.h>
#include<fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/epoll.h>
#define MAX_EVENTS 1

int main(int argc, char *argv[]) {
    int fd, epoll_fd, n, i;
    struct epoll_event ev, events[MAX_EVENTS];
    char buf[1024];


fd = open("file.txt",O_RDONLY);
if (fd == -1) {
perror("open");
exit(1);
}


epoll_fd = epoll_create1(0);
if (epoll_fd == -1) {
perror("epoll_create1");
exit(1);
}


ev.events = EPOLLIN;
ev.data.fd = fd;
if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, fd, &ev) == -1) {
perror("epoll_ctl");
exit(1);
}

while (1) {

n = epoll_wait(epoll_fd, events, MAX_EVENTS, -1);
if (n == -1) {
perror("epoll_wait");
exit(1);
}


for (i = 0; i < n; i++) {
if (events[i].events & EPOLLIN) {

int len = read(fd, buf, sizeof(buf));
if (len == -1) {
perror("read");
exit(1);
} else if (len == 0) {

printf("End of file reached\n");
exit(EXIT_SUCCESS);
 } else {

printf("Data available: %s\n", buf);
}
}
}
}


close(fd);

return 0;
}
