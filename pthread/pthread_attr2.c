 #include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <pthread.h>
int quit;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t waitloc =PTHREAD_COND_INITIALIZER;

void *thr_fn(void *arg)
{
   int i = *(int *)arg;
   printf("thr_fn\n");
   for (; i >0; --i)
   {
       /* code */
        printf("wait i %d ms\n", i);
   }
   pthread_exit((void *)0);
    
}
int main(int argc, char **argv) {
    int err,num =10; 
    pthread_t tid;
    pthread_attr_t attr;
    err = pthread_attr_init(&attr);
    if (err)
        return(err);
    err = pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
    if (err==0){
        err = pthread_create(&tid,&attr,thr_fn,(void *)&num);
         if (err) {
            printf("craete err\n");

        }/* code */
    }else
        printf("set pthread detach failed\n");
    
    pthread_attr_destroy(&attr);
    // printf("wait new pthread...\n");
    sleep(5);
   
    return 0;

}
