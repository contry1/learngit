// sleep1.c
#include <stdio.h>
#include <setjmp.h>
#include <signal.h>
#include <unistd.h>
static jmp_buf env;
static void sig_alrm(int signo)
{
    // longjmp(env,1);
}
void ismember(sigset_t *set)
{
    sigset_t newmask,oldmask,suspmask;
    if (sigismember(&newmask,SIGALRM))
    {
        /* code */
        printf("sig_alrm is exiat in newmask\n");
    }
    if (sigismember(&oldmask,SIGALRM))
    {
        /* code */
        printf("sig_alrm is exiat in oldmask\n");
    }
    if (sigismember(&suspmask,SIGALRM))
    {
        /* code */
        printf("sig_alrm is exiat in suspmask\n");
    }
}
unsigned int sleep(unsigned int sec)
{
    struct sigaction newact,oldact;
    sigset_t newmask,oldmask,suspmask;
    unsigned int unslep;

    newact.sa_handler = sig_alrm;
    sigemptyset(&(newact.sa_mask));
    newact.sa_flags = 0;
    sigaction(SIGALRM,&newact,&oldact);

    ismember(&oldmask);
    ismember(&newmask);

    printf("**************\n");

    sigemptyset(&newmask);
    sigaddset(&newmask,SIGALRM);

   

    sigprocmask(SIG_BLOCK,&newmask,&oldmask);
    
    ismember(&oldmask);
    ismember(&newmask);

    alarm(sec);
    suspmask =oldmask;
    ismember(&suspmask);

    sigdelset(&suspmask,SIGALRM);
    // ismember(&suspmask);
    sigsuspend(&suspmask);
    // ismember(&suspmask);
    unslep = alarm(0);

    sigaction(SIGALRM,&oldact,NULL);

    sigprocmask(SIG_SETMASK,&oldmask,NULL);
    return(unslep);
}



int main(int argc, char const *argv[])
{
    
    unsigned int unslept = sleep(15);
    printf("sleep1 return %u\n",unslept );
    return 0;
}