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
    
    ++i;
}

int main(int argc, char const *argv[])
{
    int n;
    char line[MAXLINE];
    if (signal(SIGALRM,sig_alarm)==SIG_ERR)
    {
        printf("signal err\n");
    }
    while(i<=100)
    {
        alarm(3);
        printf("%d\n", i);
    
       // pause();/* comment out the pause(),the outputs is 0 and is all the time and will be si xunhuan*/
        // the signal34.c can be compare signal33.c
    }
    
   
    return 0;
}

