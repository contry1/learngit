// semp.c
#include <stdio.h>
#include <semaphore.h>
#include <errno.h>
#include <pthread.h>
#include <unistd.h>

static void thread_create(pthread_t *tid,void *(*fun)(void *));
static void thread_wait(pthread_t tid);

static void sem_init_t(void);
void * fun1(void *arg);
void * fun2(void *arg);

sem_t psem;
int main(int argc, char const *argv[])
{
        sem_init_t();
        pthread_t tid1;
        pthread_t tid2;
        int res;

      
        thread_create(&tid1,fun1);
        thread_create(&tid2,fun2);

       
      

        thread_wait(tid1);
        thread_wait(tid2);


        
        
        

    return 0;
}

static void thread_create(pthread_t *tid,void *(*fun)(void *))
{
       int res = 0;
       res = pthread_create(tid,NULL,fun,NULL);
       if (res == 0)
       printf("successfully pthread\n");
       
       sleep(7);

}


static void thread_wait(pthread_t tid)
{
    int res = 0;
    int status = 0;
    res = pthread_join(tid,(void *)&status);
    if (res == 0){
        printf("wait thread successfully\n");
        printf("the return val:%d\n",status );
        
    }
    else
        perror("join thread");
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