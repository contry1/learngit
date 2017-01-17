 #include <stdlib.h>
 #include <stdio.h>  
 // #include <mysql/mysql.h>
 #include <stdlib.h>  
 #include <string.h>  
 #include <unistd.h>  
 #include <sys/types.h>
 #include <pthread.h>
 
 typedef void *(* pfunc)(void *);
 void create_thread(pthread_t *pid,void *arg,pfunc pf);
 void * main_func(void *arg);
  void * second_func(void *arg);

 void wait_pthread(pthread_t *pid );


 struct line {
    int len;
    int tail;
     
 };
 
 int main() {
 
    struct line sfd = {
        .len = 1,
        .tail = 4,
    };
    struct line *sf = &sfd;
    // sf =  realloc(sf,sizeof(struct line));

     pthread_t thread_id[10];
     int i = 0;
     create_thread(&thread_id[0],(void *)sf,main_func);
     sleep(1);
     create_thread(&thread_id[1],(void *)sf,second_func);

     sleep(3);
     wait_pthread(&thread_id[0]);
     wait_pthread(&thread_id[1]);
    /*int err = pthread_join(thread_id[0],(void *)&err);
    if (!err) {

    printf("wait success thread :%ld\n",pthread_self());
    }else
    perror("err");
    
     err = pthread_join(thread_id[1],(void *)&err);
    if (!err) {
    printf("wait success thread :%ld\n",pthread_self());
    }else
    perror("err");*/
     return 0;
 
 }
 void create_thread(pthread_t *pid,void *arg,pfunc pf)
 {
     int i = 0;
     int err = pthread_create(pid,NULL,pf,arg);
     if (err!=0) {
     perror("not create thread1");        /* code */
     }else{
     printf("new thread :%ld\n",pthread_self());/*there is new thread,not main thread*/
     
     }
 
 }
 void * main_func(void *arg)
 {
     struct line *ll =NULL;
     ll = (struct line *)arg;
     
     printf("main_func\n");
     printf("struct line len:%d|tail:%d\n",ll->len,ll->tail );
     pthread_exit((void *)0);
 }
 

 void * second_func(void *arg)
  {
      struct line *ll =NULL;
      ll = (struct line *)arg;
      
      printf("second_func\n");
      printf("struct line len:%d|tail:%d\n",ll->len,ll->tail );
      pthread_exit((void *)0);
  }
 void wait_pthread(pthread_t *pid )
 {
     int err = pthread_join(*pid,(void *)&err);
     if (!err) {
     /* code */
     printf("wait success thread :%ld\n",pthread_self());
     }else
     perror("err");
 
 
 }