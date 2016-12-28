// setsigflag.c
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
volatile   static sig_atomic_t flag;
static void sig(int signo)
{
    if (signo == SIGINT) 
        printf("interrupt\n"); /* code */ 
    if (signo == SIGQUIT) {
        printf("SIGQUIT\n");
        flag = 1;
        /* code */
    }
}
int main(int argc, char const *argv[])
{
    sigset_t zeromask;
    sigset_t newmask;
    sigset_t oldmask; // signal handler
    int ret = 0;
    if (signal(SIGINT,sig)==SIG_ERR) {
        printf("err int\n"); /* code */ 

    }
    /* code */
    if (signal(SIGQUIT,sig)==SIG_ERR) 
            printf("err quint\n");
            /* code */ 
    sigemptyset(&zeromask);
    sigemptyset(&newmask);
    sigaddset(&newmask,SIGQUIT);

    // NOW block SIGINT
    ret = sigprocmask(SIG_BLOCK,&newmask,&oldmask);
    if (/* condition */ret < 0) {
        perror("block int err");
        /* code */
    }

    while(flag == 0)
        sigsuspend(&zeromask);
    printf("the flag %d\n",flag );
    flag == 0;
    // set the sigint unblock
   
  /*  ret =  sigprocmask(SIG_SETMASK,&oldmask,NULL);
    if (ret <0) {
        printf("err unblock init\n");
       
    }else
        printf("the sigquit not block\n");*/
    return 0;
}