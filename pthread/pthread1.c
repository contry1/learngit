#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
int i = 0;
void * func1(void *arg)
{
    printf("new thread :%d\n",i);
    i++;
    pthread_exit((void *)0);
}
int main(int argc, char const *argv[])
{
    
    int err =0;
    
    pthread_t tid1,tid2;
    err = pthread_create(&tid1,NULL,func1,NULL);
    if (err!=0)
    {
        perror("not create thread1");        /* code */
    }
    sleep(1);
    printf("main thread:%d\n", i);
    err = pthread_join(tid1,NULL);
    if (err!=0)
    {
        perror("not join thread1");        /* code */
    }
    return 0;
}