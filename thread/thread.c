#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

pthread_t tid[2];

void*Function(void *arg)
{
   
    unsigned long i = 0;
    pthread_t id = pthread_self();
    if(pthread_equal(id,tid[0]))
    {
	printf("id of thread1 : %ld\n",id);
        printf("First thread is being processed\n");
    }
    else
    {
	printf("id of thread2 : %ld\n",id);
        printf(" Second thread is being processed \n");
    }

  
 
}

int main(void)

{
    int i = 0;
    int error;
    while(i < 2)
    {
        error = pthread_create(&(tid[i]), NULL, &Function, NULL);
        if (error != 0)
            printf("\n Not been able to create the thread" );
        else
            printf(" Thread has been created successfully\n");
       i++;
    }
 
    return 0;
}
