// semp.c
#include <stdio.h>
#include <semaphore.h>
#include <errno.h>
#include <pthread.h>
#include <unistd.h>

static void thread_create(pthread_t *tid,void *(*fun)(void *));
static void thread_wait(pthread_t *tid);

static void sem_init_t(sem_t * psem);
void * fun1(void *arg);
void * fun2(void *arg);

sem_t psem;
sem_t psem2;

int sum = 0;
int main(int argc, char const *argv[])
{
        sem_init_t(&psem);
        sem_init_t(&psem2);


        pthread_t tid1;
        pthread_t tid2;
      
        thread_create(&tid1,fun1);
        thread_create(&tid2,fun2);

        thread_wait(&tid1);
        sleep(5);
        thread_wait(&tid2);


    return 0;
}

static void thread_create(pthread_t *tid,void *(*fun)(void *))
{
       int res = 0;
       res = pthread_create(tid,NULL,fun,NULL);
       if (res == 0)
       printf("successfully create");
       
       sleep(1);

}


static void thread_wait(pthread_t *tid)
{
    int res = 0;
    int status = 0;
    res = pthread_join(*tid,(void *)&status);
    if (res == 0){
        printf("wait thread %lu successfully\n",*tid);
        printf("the return val:%d\n",status );
        
    }
    else
        perror("join thread");
}

void * fun1(void *arg)
{
    printf(" thread 1\n");
    int i = 0;
    sem_wait(&psem2);
    // wait the thread2 finish
    for (; ; ) {
        sum +=i;
        i++;
        printf("thread 1 sum:%d\n",sum );
        if (sum >100) {
            printf("......notice thread 2......\n");
            sem_post(&psem);

/*            block the thread1,wait the thread 2 fimnish
*/            
            sem_wait(&psem2);


        }
        // sem_post(&psem2);

        sleep(1);

        /* code */
    }
    pthread_exit((void *)0);
}

void * fun2(void *arg)
{
    int   i  =0;
    int ret = 0;
    printf("  thread 2\n");
    while(1) {
        printf("thread 2 sum:%d\n", sum);
        i++;
        sum -=i;
        if (sum <0){
            ret = sem_post(&psem2);
            if (ret == 0) 
                printf("......notice thread 1......\n");
                /* code */
            else
                perror("psem2");
            sem_wait(&psem);
            
        }

        sleep(2);
            
    }
    sem_post(&psem2);
    pthread_exit((void *)0);
}
static void sem_init_t(sem_t * psem)
{
       
       unsigned int val = 0;
       int ret = 0;
       ret = sem_init(psem,sum,val);
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