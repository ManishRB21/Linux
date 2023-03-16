#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>

struct message {
   long msg_type;
   char msg_text[100];
};

int main() {
   key_t key;
   int msgid;
   struct message msg;
   
   key = ftok("queue.txt", 'b');
   msgid = msgget(key, 0666 | IPC_CREAT);
   
   msg.msg_type = 1;
   strcpy(msg.msg_text, "Hello, this is a message!");
   msgsnd(msgid, &msg, sizeof(msg), 0);
   
   msgrcv(msgid, &msg, sizeof(msg), 1, 0);
   printf("Received message: %s\n", msg.msg_text);
   
   msgctl(msgid, IPC_RMID, NULL);
   
   return 0;
}
