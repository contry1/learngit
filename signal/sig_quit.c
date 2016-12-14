#include <stdio.h>
#include <setjmp.h>
#include <signal.h>
#include <unistd.h>
static void sig_quit(int signo)
{
    printf("start sig quit\n");
    if (signal(SIGQUIT,SIG_DFL)==SIG_ERR)
    {
        /* code */
        printf("quit dfl err\n");
    }
}
int main(int argc, char const *argv[])
{
    sigset_t newmask,oldmask,pendmask;
    if (signal(SIGQUIT,sig_quit)==SIG_ERR)
    {
        /* code */printf("signal quit err\n");
    }
    sigemptyset(&newmask);
    sigaddset(&newmask,SIGQUIT);

    sigprocmask(SIG_BLOCK,&newmask,&oldmask);

    sleep(5);
    if (sigpending(&pendmask)<0)
    {
        /* code */
        printf("pending err\n");
    }
   
    if (sigismember(&pendmask,SIGQUIT)<0)
    {
        /* code */
        printf("err\n");
    }
    printf("\npending QUIT ....\n");
    // sigdelmask(&pendmask,SIGQUIT); this is my

    // sigprocmask(SIG_SETMASK,&pendmask,&oldmask); this is my
    sigprocmask(SIG_SETMASK,&oldmask,NULL);
    printf("SIGQUIT UNBLOCK\n");
    sleep(5);
    return 0;
}