#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<string.h>
#include<pwd.h>
typedef void sigfunc(int);
sigfunc *signal(int,sigfunc*);

/*the example is happen the seg fault,because we call the not safe func(getpwnam)*/
 
 static void sig_alarm(int signo)
{
	struct passwd *ptr;
	printf("signal handler\n");
	if ((ptr = getpwnam("root"))==NULL)
	{
		printf(" root err\n");
		/* code */
	}
	alarm(10);
	
}

// static void sig_usr(int);

int main()
{
	struct passwd *p;
	signal(SIGALRM,sig_alarm);
	alarm(10);
	while(1)
	{
		if ((p = getpwnam("sar"))==NULL)
		{
		printf(" sar err\n");
		/* code */
		}
		if (strcmp(p->pw_name,"sar")!=0)
		{
			/* code */
			printf("return value pw_name:%s\n",p->pw_name );
		}
	}
	return 0;
}

