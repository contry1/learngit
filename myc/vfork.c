// the exp is err ,the vfork should be called in main().
// the end is core dump

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<errno.h>
static void f1()
{
    pid_t pid;
    if((pid=vfork())<0){
        printf("err\n");
    }
}
static void f2(){
    char buf[1000] ;
    int i;
    for (int i = 0; i < sizeof(buf); ++i)
    {
        /* code */buf[i] =0;
    }
}
int main(int argc, char const *argv[])
{
    f1();
    f2();
    _exit(0);
}