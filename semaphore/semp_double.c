// semp_double.c
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

int sum = 0;
sem_t psem1;
sem_t psem2;

void * thread1(void *arg)
{
    // int i = 0;
    static int cnt1 =0;
    sem_wait(&psem1);
    for (int i = 0; i < 100; ++i) {
        sum -= i;
        // fputs("sum",stdout);
        printf("thread1 %d\n",sum );
        printf("count 1:%d\n", ++cnt1);
        /* code */
        sleep(1);
        if (sum < 100) {
            sem_post(&psem2);
            sem_wait(&psem1);
            /* code */
        }
    }
    sem_post(&psem2);
    pthread_exit((void *)0);
}

void * thread2(void *arg)
{
    // int i = 0;

    static int cnt2 = 0;

    for (int i = 0; i < 100; ++i) {
        sum += i;
        printf("thread2 %d\n",sum );
        /* code */
        printf("count 2:%d\n", ++cnt2);

        sleep(1);
        if (sum >500) {
            printf("notice the thread 2 already change,the thread 1 start run\n");
            sem_post(&psem1);
            printf("block the thread 2\n");
            sem_wait(&psem2);
            /* code */
        }
    }

    printf("notice the thread 2 already finish,the thread 1 start run\n");
    sem_post(&psem1);
    pthread_exit((void *)0);
}

int main(int argc, char const *argv[])
{
    pthread_t tid1;
    pthread_t tid2;

    // init the semaphore
    unsigned int val = 0;
    sem_init(&psem1,sum,val);
    sem_init(&psem2,sum,val);

    int ret = 0;
    ret = pthread_create(&tid1,NULL,thread1,NULL);
    if (ret == -1)
        perror("thread 1");

    // sleep(1);

    ret = pthread_create(&tid2,NULL,thread2,NULL);
        if (ret == -1)
            perror("thread2");

    ret = pthread_join(tid1,NULL);
    if (ret == -1)
        perror("thread 1 WAIT");


    ret = pthread_join(tid2,NULL);
        if (ret == -1)
            perror("thread 2 WAIT");

    return 0;
}


