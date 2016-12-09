/*
the example is err,that is represent if we first call the alarm().and the default to end up the func,and it is not relasion the placeof the alarm(),the below you will see it.

A method is  add pause().it will be sleep until the signal will be wake up the next time,and the signal36.c you will see it.

*/
#include<stdio.h>
#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
#include<setjmp.h>
#define MAXLINE 4096

static jmp_buf env;
int  i = 0;

static void sig_alarm(int signo)
{
    
    printf("sig_alarmr\n");
}

int main(int argc, char const *argv[])
{
    int n;
    char line[MAXLINE];
    // the below is err call
#if 0
    alarm(5);
    if (signal(SIGALRM,sig_alarm)==SIG_ERR)
    {
        printf("signal err\n");
    }
#endif

    // the below is also err call
#if 1
   if (signal(SIGALRM,sig_alarm)==SIG_ERR)
    {
        printf("signal err\n");
    }
    alarm(5);
#endif
    return 0;
}

