#include<stdio.h>

#include<stdlib.h>


void onexit(){
printf("called before termination");

}

int main(){
int counter=1;
int status;
status= atexit(onexit);
if(status!=0){
printf("registration failed");
exit(1);
}

for(int i=counter;i<=10;i++){
printf("%d\n",counter);
counter++;
}
return 0;





}


