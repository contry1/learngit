#include <stdio.h>
#include <setjmp.h>
#include <signal.h>
#include <unistd.h>

static void pr_mask(const char *str)
{
    sigset_t sigset;
    // int errno_save;
    // errno_save = errno;
    if (sigprocmask(0,NULL,&sigset)<0)
    {
        /* code */printf("promask error\n");
    }else{
        printf("%s",str );
        if (sigismember(&sigset,SIGINT))
        {
            /* code */printf("SIGINT");
        }
        if (sigismember(&sigset,SIGQUIT))
        {
            /* code */printf("SIGQUIT");
        }
        if (sigismember(&sigset,SIGUSR1))
        {
            /* code */printf("SIGUSR1");
        }
        if (sigismember(&sigset,SIGALRM))
        {
            /* code */printf("SIGALRM");
        }
        printf("\n");
    }
    // errno = errno_save;
}


static void sig_int(int signo)
{

    
    
        /* code */
        printf("\nsignal sigint statrt\n");
        pr_mask("the sigint: ");
    
}
int main(int argc, char const *argv[])
{
    sigset_t newmask,oldmask,waitmask;
    sigemptyset(&waitmask);
    sigaddset(&waitmask,SIGUSR1);

    sigemptyset(&newmask);
    sigaddset(&newmask,SIGINT);

    sigprocmask(SIG_BLOCK,&newmask,&oldmask);
   
    // signal()
     if (sigsuspend(&waitmask)!=-1)
    {
        /* code */printf("susupend err\n");
    }
    // printf("sigsuspend usr1\n");
    pr_mask("after sigsuspend: ");

     // THE BLEW IS CRICITLE RIGION
    
    if (signal(SIGINT,sig_int)==SIG_ERR)
    {
        /* code */
        printf("err sig\n");
    }
    sleep(3);
   

   
    sigprocmask(SIG_SETMASK,&oldmask,NULL);
    pr_mask("not sigint block:");
    // printf("SIG INT NOT SIG_BLOCK\n");
    sleep(5);
    return 0;
}