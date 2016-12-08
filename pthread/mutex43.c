#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
struct foo
{
    int a,b,c,d;
    pthread_mutex_t lock;
    
};

 struct foo foo = {1,2,3,4};/*quanju*/
int i =0;
// pthread_mutex_t  *lock;
void printfoo(const char *s,const struct foo *fp)
{
    printf("%s\n",s );
    printf("struct at 0x%lx\n",(unsigned long)fp );
    printf("foo.a=%d\n", fp->a);
    printf("foo.b=%d\n", fp->b);
    printf("foo.c=%d\n", fp->c);
    printf("foo.d=%d\n", fp->d);
}

void * fn1(void * arg)
{
   pthread_mutex_lock(&foo.lock);
    printfoo("thread1:\n",&foo);
    printf("thread1:%d\n", i);
    i++;
    pthread_mutex_unlock(&foo.lock);  
     pthread_exit((void *)&foo); 
}

void * fn2(void * arg)
{
    
    printf("thread2:%lu\n",(unsigned long)pthread_self());
    printfoo("thread2:\n",&foo);
    printf("thread2:%d\n", i);
    i++;
     pthread_exit((void *)0);    
}


int main(int argc, char const *argv[])
{
    /* code */
    int err = 0;
    pthread_t tid1,tid2;
    void * ret =NULL;
    struct foo *fp;
    fp =( struct foo *)calloc(sizeof(struct foo),1);
    // add mutex
     err = pthread_mutex_init(&fp->lock,NULL);
     if(err){
        free(fp);
     }

    err = pthread_create(&tid1,NULL,fn1,NULL);
    if (err!=0)
    {
        perror("not create thread1");        /* code */
    }else{
        printf("thread1:%d\n", i);
    }

    //get the thread1 exit status
    err = pthread_join(tid1,&ret);
    if (err!=0)
    {
        perror("not join thread1");        /* code */
    }else{
        printf("the thread1 return code ；%d\n", err);
    }

    sleep(1);
    printf("parent starting second thread2\n");

    err = pthread_create(&tid2,NULL,fn2,NULL);
    if (err!=0)
    {
        perror("not create thread2");        /* code */
    }else{
        printf("thread2:%d\n", i);
    }

     printf("main 1 thread:%d\n", i);
    err = pthread_join(tid2,(void *)&fp);
    if (err!=0)
    {
        perror("not join thread2");        /* code */
    }else{
        printf("the thread2 return code ；%d\n", err);
    }
     printf("main 2 thread:%d\n", i);
    sleep(1);
    // printfoo("parent:\n",fp);
     printf("main 3  thread:%d\n", i);
    
    return 0;
}
