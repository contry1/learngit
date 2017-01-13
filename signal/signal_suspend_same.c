// 
// signal_suspend.c
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
void sigint(int signo);

int  main(int argc, char const *argv[])
{
	
	sigset_t newmask,oldmask,waitmask,quitmask;
	sigemptyset(&newmask);
	sigemptyset(&waitmask);
	sigaddset(&newmask,SIGINT);
	sigaddset(&waitmask,SIGQUIT);
	sigprocmask(SIG_BLOCK,&newmask,&oldmask);

	printf("the next is croitc blode code..........\n");
	printf("the above is croitc blode code..........\n");
	pr_mask("the next is region: ");

	if (signal(SIGINT,sigint)==SIG_ERR) {
	        /* code */
	        printf("err sig\n");
	}
	sleep(3);
	//sigsuspend(&waitmask);
    // the belo is same with sigsuspend
            sigprocmask(SIG_SETMASK,&waitmask,&quitmask);
            sleep(3);
            // pause();
            sigprocmask(SIG_SETMASK,&newmask,NULL);

            // sigprocmask(SIG_SETMASK,&newmask,&oldmask);
            // sigprocmask(SIG_UNBLOCK,&waitmask,NULL);

    // the belo is same with sigsuspend

            

	printf("after the sigsuspend...\n");
	pr_mask("after the sigsuspend is:");

	sigprocmask(SIG_SETMASK,&oldmask,NULL);
	printf("EXIT");
	pr_mask("not sigint block:");

	return 0;
}

void sigint(int signo)
{
	printf("sigint..........\n");
	pr_mask("sigint handle:");
}
