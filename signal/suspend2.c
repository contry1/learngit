#include	<signal.h>
 #include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>

volatile sig_atomic_t	quitflag;	/* set nonzero by signal handler */

int
main(void)
{
	void		sig_int(int);
	sigset_t	newmask, oldmask, zeromask;

	if (signal(SIGINT, sig_int) == SIG_ERR)
		printf("signal(SIGINT) error");
	if (signal(SIGQUIT, sig_int) == SIG_ERR)
		printf("signal(SIGQUIT) error");

	sigemptyset(&zeromask);

	sigemptyset(&newmask);
	sigaddset(&newmask, SIGQUIT);
					/* block SIGQUIT and save current signal mask */
	if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
		printf("SIG_BLOCK error");

	while (quitflag == 0)
		sigsuspend(&zeromask);

	/* SIGQUIT has been caught and is now blocked; do whatever */
	quitflag = 0;
					/* reset signal mask which unblocks SIGQUIT */
	if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
		printf("SIG_SETMASK error");

	exit(0);
}

void
sig_int(int signo)	/* one signal handler for SIGINT and SIGQUIT */
{
	if (signo == SIGINT)
		printf("\ninterrupt\n");
	else if (signo == SIGQUIT)
		quitflag = 1;	/* set flag for main loop */
	return;
}
