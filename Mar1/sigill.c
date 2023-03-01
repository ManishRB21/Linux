#include <stdio.h>
#include <signal.h>

void sigill_handler(int sig) {
printf("Illegal instruction signal received\n");

}

int main() {

signal(SIGILL, sigill_handler);



asm("ud2");
printf("program continues...");
return 0;
}
