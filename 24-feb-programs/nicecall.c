#include <stdio.h>
#include <sys/resource.h>
#include <unistd.h>
int main(int argc, char *argv[]) {
    pid_t pid;
    int priority, ret;
  if (argc != 3) {
 printf("Usage: %s <pid> <priority>\n", argv[0]);
return 1;
}
  pid = atoi(argv[1]);
    priority = atoi(argv[2]);
ret = getpriority(PRIO_PROCESS, pid);
  if (ret == -1) {
        perror("getpriority");
 return 1;
}
    printf("Current priority of process %d: %d\n", pid, ret);
  ret = setpriority(PRIO_PROCESS, pid, priority);
  if (ret == -1) {
        perror("setpriority");
  return 1;
}
  printf("New priority of process %d: %d\n", pid, priority);
    return 0;
}
