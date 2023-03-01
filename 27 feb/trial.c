 #include <sys/epoll.h>
 #include <stdio.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <string.h>
 #include <sys/uio.h>
  
  int main() {
    struct epoll_event event ;
    int ret,fd, epfd ;
  
    fd = open("doc", O_RDONLY);
    if( fd < 0 )
      perror("open");
  
    event.data.fd = fd ;
    event.events = EPOLLIN|EPOLLOUT ;
  
    epfd = epoll_create(50);
    printf("%d", epfd );
  
    if( epfd < 0 )
      perror("epoll_create");
  
    ret = epoll_ctl( epfd, EPOLL_CTL_ADD, fd, &event ) ;
    if( ret < 0 )
      perror("epoll_ctl");
  
  }
