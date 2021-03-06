// semp.c
#include <stdio.h>
#include <semaphore.h>
#include <errno.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>
static void thread_create(pthread_t *tid,void *(*fun)(void *));
static void thread_wait(pthread_t tid);
static void maketimeout(struct timespec *tsp,long min);


void * fun1(void *arg);
void * fun2(void *arg);

pthread_mutex_t lock;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
struct timespec tsp;
int sum = 0;
int main(int argc, char const *argv[])
{
        pthread_mutex_init(&lock,NULL);
        pthread_t tid1;
        pthread_t tid2;
       

      
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
            
            // break;
            pthread_cond_signal(&cond);
        
        }
        pthread_mutex_unlock(&lock);
        // there sleep time also will  interact the thread 2 output
        sleep(1);

        /* code */
    }
    pthread_exit((void *)0);
}

static void maketimeout(struct timespec *tsp,long min)
{
    struct timeval now;
    
    gettimeofday(&now, NULL);//AVOID the now time
    tsp->tv_sec = now.tv_sec;
    tsp->tv_nsec = now.tv_usec * 1000;

    // add the offset min time
    tsp->tv_sec += min * 60;
    
}
void * fun2(void *arg)
{
    int   i  =0;
    printf("  thread 2\n");
    pthread_mutex_lock(&lock);
    maketimeout(&tsp,1);
    // pthread_cond_wait(&cond,&lock);
    pthread_cond_timedwait(&cond,&lock,&tsp);

    while(sum >0)
    {
        sum -=i;
        i++;
        printf("thread 2 sum:%d\n", sum);
    }
    pthread_mutex_unlock(&lock);
    sleep(3);

    pthread_exit((void *)0);
}
