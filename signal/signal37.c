#include<stdio.h>
#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
#include<errno.h>


void pr_mask(const char *str)
{
    sigset_t sigset;
    int errno_save;
    errno_save = errno;
    if (sigprocmask(0,NULL,&sigset)<0)
    {
        /* code */printf("promask error\n");
    }else{
        printf("%s\n",str );
        if (sigismember(&sigset,SIGINT))
        {
            /* code */printf("SIGINT\n");
        }
        if (sigismember(&sigset,SIGQUIT))
        {
            /* code */printf("SIGQUIT\n");
        }
        if (sigismember(&sigset,SIGUSR1))
        {
            /* code */printf("SIGUSR1\n");
        }
        if (sigismember(&sigset,SIGALRM))
        {
            /* code */printf("SIGALRM\n");
        }
        printf("\n");
    }
    errno = errno_save;
}
static void my(int signo)
{
    const char * str = "hello";
    if(signo == SIGALRM){
        printf("RECE ALRM\n");
    }
    
    pr_mask(str);
    
    pause();
       

    
   

}

int main(int argc, char const *argv[])
{
    
    if (signal(SIGALRM,my)==SIG_ERR)
    {
        /* code */printf("signal err\n");
    }
    
    alarm(2);
    pause();
    
    return 0;
}