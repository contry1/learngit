// semp.c
#include <stdio.h>
#include <semaphore.h>
#include <errno.h>
#include <pthread.h>
#include <unistd.h>

static void thread_create(pthread_t *tid,void *(*fun)(void *));
static void thread_wait(pthread_t tid);


void * fun1(void *arg);
void * fun2(void *arg);

pthread_mutex_t lock;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
// this is static init the pthread_cond_t,we also actively to init it by pthread_cond_init()
int sum = 0;
int main(int argc, char const *argv[])
{
        int ret = 0;
        pthread_mutex_init(&lock,NULL);
        pthread_t tid1;
        pthread_t tid2;
       

      
        thread_create(&tid1,fun1);
        thread_create(&tid2,fun2);

       
      

        thread_wait(tid1);
        thread_wait(tid2);
        ret = pthread_cond_destroy(&cond);
        if (ret == 0) 
            printf("pthread_cond_destroy success\n");
            /* code */
        else
            perror("pthread_cond_destroy");

    return 0;
}

static void thread_create(pthread_t *tid,void *(*fun)(void *))
{
       int res = 0;
       res = pthread_create(tid,NULL,fun,NULL);
       if (res == 0)
       printf("successfully create");
       // there sleep is must exist,or not the second thread will be  not running
       sleep(1);

}


static void thread_wait(pthread_t tid)
{
    int res = 0;
    int status = 0;
    res = pthread_join(tid,(void *)&status);
    if (res == 0){
        printf("wait thread %lu successfully\n",tid);
        printf("the return val:%d\n",status );
        
    }
    else
        perror("join thread");
}

void * fun1(void *arg)
{
    printf(" thread 1\n");
    int i = 0;
    for (; ; ) {
        pthread_mutex_lock(&lock);
        sum +=i;
        pthread_mutex_unlock(&lock);
        i++;

        pthread_mutex_lock(&lock);
        printf("thread 1 sum:%d\n",sum );
        if (sum >100) {
            
            pthread_cond_signal(&cond);
            
        
        }
        pthread_mutex_unlock(&lock);
        // there sleep time also will  interact the thread 2 output
        sleep(1);

        /* code */
    }
    pthread_exit((void *)0);
}

void * fun2(void *arg)
{
    int   i  =0;
    printf("  thread 2\n");
   pthread_mutex_lock(&lock);

    pthread_cond_wait(&cond,&lock);
    while(sum >0)
    {
        printf("thread 2 sum:%d\n", sum);
        sum -=i;
        i++;
    }
    pthread_mutex_unlock(&lock);
    sleep(3);

    pthread_exit((void *)0);
}
