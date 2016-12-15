#include <stdio.h>
#include <setjmp.h>
#include <signal.h>
#include <unistd.h>

static void sig(int signo)
{
    printf("sig int start\n");
}
int main(int argc, char const *argv[])
{

    // pause();
    if (signal(SIGINT,sig)==SIG_ERR)
    {
        /* code */
        printf("err\n");
    }
  pause();
    printf("sig success\n");
    return 0;
}