#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<errno.h>
typedef void sigfunc(int);
sigfunc *signal(int,sigfunc*);


 
 

static void sig_usr(int);

int main()
{
	if(signal(SIGUSR1,sig_usr)==SIG_ERR)
		printf("cant catch sigusr1\n");
	if(signal(SIGUSR2,sig_usr)==SIG_ERR)
		printf("cant catch sigusr2\n");
		
	while(1){
		pause();
	}
	return 0;
}

static void sig_usr(int signo)
{
	if(signo==SIGUSR1)
		{
			printf("rece sigusr1\n");
		}else if(signo==SIGUSR2){
			
				printf("rece sigusr2\n");
		}else
				printf("rece sinal %d\n",signo);
}