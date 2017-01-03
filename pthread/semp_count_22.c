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
int sum = 0;
int main(int argc, char const *argv[])
{
        // sem_init_t();
        pthread_t tid1;
        pthread_t tid2;
       

      
        thread_create(&tid1,fun1);
        sleep(2);
        thread_create(&tid2,fun2);

        // sleep(2);
        thread_wait(tid1);
        thread_wait(tid2);


    return 0;
}

static void thread_create(pthread_t *tid,void *(*fun)(void *))
{
       int res = 0;
       res = pthread_create(tid,NULL,fun,NULL);
       if (res == 0)
       printf("successfully create\n");
       

}


static void thread_wait(pthread_t tid)
{
    int res = 0;
    int status = 0;
    res = pthread_join(tid,(void *)&status);
    if (res == 0){
        printf("wait thread %lu successfully\n",pthread_self());
        printf("the return val:%d\n",status );
        
    }
    else
        perror("join thread");
}

void * fun1(void *arg)
{
    printf(" thread 1\n");
    while(1) {
        sum++;
        printf("thread 1 sum 1:%d\n",sum );
        if (sum>10) {
            break;
            /* code */
        }

        sleep(2);
        /* code */
    }
    sum = 0;

       

        /* code */
    
    pthread_exit((void *)0);
}

void * fun2(void *arg)
{
    

    printf("  thread 2\n");
    
    while(1) {
        sum ++;
        printf("thread 2 sum 2:%d\n", sum);
        if (sum>10) {
            break;
            /* code */
        }
        /* code */
        sleep(1);
    }
    sum =0;
        
        
    
    pthread_exit((void *)0);
}
static void sem_init_t(void)
{
       int pshared = 0;
       unsigned int val = 0;
       int ret = 0;

       ret = sem_init(&psem,pshared,val);
       if (ret == 0) {
           printf(" semaphore init success\n");
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