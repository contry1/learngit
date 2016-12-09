#include<stdio.h>
#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
#include<errno.h>


static void sig_quit(int signo)
{
    printf("catch sig_quit\n");
    if (signal(SIGQUIT,SIG_DFL)==SIG_ERR)
    {
        printf("can not reset sig_quit\n");
    }
}

int main(int argc, char const *argv[])
{
    sigset_t newmask,oldmask,pendmask;
    if (signal(SIGQUIT,sig_quit)==SIG_ERR)
    {
        printf("signal err\n");
    }
    // block quit
    sigemptyset(&newmask);
    sigaddset(&newmask,SIGQUIT);
    if (sigprocmask(SIG_BLOCK,&newmask,&oldmask)<0)
    {
        /* code */printf("SIG_BLOCK err\n");
    }

    sleep(5);

    if (sigpending(&pendmask)<0)
    {
        /* code */printf("sigpend err\n");
    }
    if (sigismember(&pendmask,SIGQUIT))
    {
        /* code */printf("\nsigquit pending\n");
    }


    if (sigprocmask(SIG_SETMASK,&oldmask,NULL)<0)
    {
        /* code */printf("SIG_SETMASK err\n");
    }
    printf("sigquit unblock\n");

    sleep(5);
    return 0;
}