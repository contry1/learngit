// semp.c
#include <stdio.h>
#include <semaphore.h>
#include <errno.h>
#include <pthread.h>
#include <unistd.h>

static void sem_init_t(void);
void * fun1(void *arg);
void * fun2(void *arg);

sem_t psem;
int main(int argc, char const *argv[])
{
        sem_init_t();
        pthread_t tid1;
        pthread_t tid2;

        int res = 0;
        res = pthread_create(&tid1,NULL,fun1,NULL);
        if (res == 0)
            printf("successfully pthread1\n");
        
        sleep(7);
        res = pthread_create(&tid2,NULL,fun2,NULL);
        if (res == 0)
            printf("successfully pthread2\n");
        res = pthread_join(tid1,NULL);
        if (res == 0)
            printf("wait thread1 successfully\n");
        else
            perror("join thread1");
        
        res = pthread_join(tid2,NULL);
        if (res == 0)
            printf("wait thread2 successfully\n");
        else
            perror("join thread2");
        
        

    return 0;
}

void * fun1(void *arg)
{
    printf("fun1 thread\n");
    sem_post(&psem);
    pthread_exit((void *)0);
}

void * fun2(void *arg)
{
    printf("fun2 thread\n");
    sem_wait(&psem);
    pthread_exit((void *)0);
}
static void sem_init_t(void)
{
       int pshared = 0;
       unsigned int val = 0;
       int ret = 0;

       ret = sem_init(&psem,pshared,val);
       if (ret == 0) {
           printf("make it semp\n");
           /* code */
       }else{

           perror("semp");
           if (errno == EINVAL) 
               printf("einval\n");
           if (errno == ENOSYS)
               printf("ENOSYS\n");
           else
               printf("undef err\n");
           
       }
}