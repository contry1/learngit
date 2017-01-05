// semp_double.c
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
int sum = 0;
sem_t psem1;
sem_t psem2;
typedef  void *(fp)(void *);
static void thread_create(pthread_t *tid,fp * fun);
static void thread_wait(pthread_t *tid);
void * thread1(void *arg);
void * thread2(void *arg);
static void sem_clean(sem_t sem);

// break semp_double_stand.c:134 thread 1

int main(int argc, char const *argv[])
{
    pthread_t tid1;
    pthread_t tid2;

    // init the semaphore
    unsigned int val = 0;
    sem_init(&psem1,sum,val);
    sem_init(&psem2,sum,val);

    thread_create(&tid1,thread1);
    thread_create(&tid2,thread2);

    thread_wait(&tid1);
    thread_wait(&tid2);
    
    sem_clean(psem1);
    sem_clean(psem2);


    return 0;
}


static void thread_create(pthread_t *tid,fp *fun)
{
       int res = 0;
       res = pthread_create(tid,NULL,fun,NULL);
       if (res == 0)
       printf("successfully create\n");
       
       sleep(1);

}

void * thread1(void *arg)
{
    // int i = 0;
    static int cnt1 =0;
    sem_wait(&psem1);
    for (int i = 0; i < 100; ++i) {
        sum -= i;
        // fputs("sum",stdout);
        printf("thread1'sum:%d\t",sum );
        printf("count 1:%d\n", ++cnt1);
        /* code */
        sleep(1);
        if (sum < 100) {
            printf("the sum < 100,notice the thread2\n");
            sem_post(&psem2);
            printf("block the thread 1\n");
            if (cnt1<99)
                sem_wait(&psem1);
            else
                printf("the thread1 finish.....\n");
            
            /* code */
        }
    }
    printf("the thread 1 already finish,notice the thread 2 start run\n");
    // sem_post(&psem2);
    pthread_exit((void *)0);
}





void * thread2(void *arg)
{
    // int i = 0;

    static int cnt2 = 0;

    for (int i = 0; i < 100; ++i) {
        sum += i;
        printf("thread2'sum:%d\t",sum );
        /* code */
        printf("count 2:%d\n", ++cnt2);

        sleep(1);
        if (sum >100) {
            printf("sum >100,notice the thread 1\n");
            sem_post(&psem1);
            printf("block the thread 2\n");
            sem_wait(&psem2);
            /* code */
        }
    }

    printf("the thread 2 already finish,notice the thread 1 start run\n");
    sem_post(&psem1);
    pthread_exit((void *)0);
}


/*tatic void thread_wait(pthread_t *tid)
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
    sleep(1);
}
*/

static void thread_wait(pthread_t *tid)
{
    int res = 0;
    int status = 0;
    res = pthread_join(*tid,NULL);
    if (res == 0){
        printf("wait thread %lu successfully\n",*tid);
       
        
    }
    else
        perror("join thread");
    sleep(1);
}


static void sem_clean(sem_t sem)
{
    
        int ret = 0;
        ret = sem_getvalue(&sem,&ret);
        if (ret == 0) {
            printf("no wait semaphore,we can destroy\n");
            sem_destroy(&sem);
            /* code */
        }
}