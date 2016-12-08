
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
struct foo
{
    int a,b,c,d;
    
};

 struct foo foo = {1,2,3,4};/*quanju*/

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
    
    printfoo("thread1:\n",&foo);
    pthread_exit((void *)&foo);    
}

void * fn2(void * arg)
{
    
    printf("thread2:%lu\n",(unsigned long)pthread_self());
    pthread_exit((void *)0);    
}


int main(int argc, char const *argv[])
{
    /* code */
    int err = 0;
    pthread_t tid1,tid2;
   
    struct foo *fp;
    
    err = pthread_create(&tid1,NULL,fn1,NULL);
    if (err!=0)
    {
        perror("not create thread1");        /* code */
    }
    err = pthread_join(tid1,(void *)&fp);
    if (err!=0)
    {
        perror("not join thread1");        /* code */
    }

    sleep(1);
    printf("parent starting second\n");

    err = pthread_create(&tid2,NULL,fn2,NULL);
    if (err!=0)
    {
        perror("not create thread2");        /* code */
    }
    sleep(1);
    printfoo("parent:\n",fp);
    return 0;
}
