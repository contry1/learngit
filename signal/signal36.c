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
#if 1
    alarm(5);
    if (signal(SIGALRM,sig_alarm)==SIG_ERR)
    {
        printf("signal err\n");
    }
    pause();
#endif

    // the below is also exactly call
#if 0
   if (signal(SIGALRM,sig_alarm)==SIG_ERR)
    {
        printf("signal err\n");
    }
    alarm(5);
    pause();
#endif
    return 0;
}

