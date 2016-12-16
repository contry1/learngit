 #include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <pthread.h>
int quit,sum;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t waitloc =PTHREAD_COND_INITIALIZER;

void *thr_fn(void *arg)
{
   int j  = 0;
   printf("thr_fn\n");
   if (j==0){
     /* code */
      printf("the init j success\n");
      while(j<101){
         pthread_mutex_lock(&lock);
          sum += j;
           pthread_mutex_unlock(&lock);
          j++;
      }
        pthread_mutex_lock(&lock);
      printf("the sum:%d\n", sum);
       pthread_mutex_unlock(&lock);
   }
   
   pthread_exit((void *)0);
    
}
int main(int argc, char **argv) {
    int i,err,num =0; 
    pthread_t tid[i];
    pthread_attr_t attr;
    err = pthread_attr_init(&attr);
    if (err)
        return(err);
    err = pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);
    if (err==0){
        for (int i = 0; i < 5; ++i)
        {
           err = pthread_create(&tid[i],&attr,thr_fn,(void *)&num);
            if (err) {
              printf("craete err\n");

              }
        }
    }else
        printf("set pthread detach failed\n");
    
    pthread_attr_destroy(&attr);
    // printf("wait new pthread...\n");
    sleep(1);

    for (int i = 5; i >0; --i)
    {
      /* code */
        printf("wait the thread:%d\n", i);
        err = pthread_join(tid[i],(void *)&err);
        if (!err)
        {
          /* code */
            printf("wait success thread :%d\n",i);
        }
    }
   
    return 0;

}
