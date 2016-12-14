// sleep1.c
#include <stdio.h>
#include <setjmp.h>
#include <signal.h>
#include <unistd.h>
static jmp_buf env;
static void sig_alrm(int signo)
{
    longjmp(env,1);
}
unsigned int sleep1(unsigned int sec)
{
    if (signal(SIGALRM,sig_alrm)==SIG_ERR)
    {
        /* code */printf("err signal\n");
        return(sec);
    }
    if (setjmp(env)==0)
    {
        /* code */
        alarm(sec);
        pause();
    }
    printf("the unsleep time:%d\n",alarm(0) );
    return(alarm(0));
}

static void sig_int(int signo)
{
    int i ,j;
    int k;
    printf("\nsig int starting\n");
    for (int i = 0; i < 300000; ++i)
    {
        /* code */for (int j= 0; j < 4000; ++j)
        {
            /* code */k += i*j;
        }
       
    }
     printf("sig int finish\n");
}

int main(int argc, char const *argv[])
{
    unsigned int unslep;
    if (signal(SIGINT,sig_int)==SIG_ERR)
    {
        /* code */printf("err sig int\n");
    }
    unslep = sleep1(25);
    printf("sleep1 return %u\n",unslep );
    return 0;
}