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
        // pause();
    }
    alarm(sec-2);
    printf("the unsleep time:%d\n",alarm(0) );
    return(alarm(0));
}
int main(int argc, char const *argv[])
{
    sleep1(7);
    return 0;
}