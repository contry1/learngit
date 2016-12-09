/*the signal33.c can be compare with signal34.c
 the func is come true to printf 1 to 100,and the signal33.c is exactly
 but signal34.c is error*/

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
    // alarm(0);
       pause();/* code */
    }
    
   
    return 0;
}

