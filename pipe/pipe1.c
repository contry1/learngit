// pipe1.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
static void fun(int signo)
{
	printf("fun pipe\n");
}
int main(int argc, char const *argv[])
{
	int fd[2];
	pipe(fd);
	close(fd[0]);
	signal(SIGPIPE,fun);
	int  n = write(fd[1],"hshsh",6);
	if (n==-1)
	{
		printf("err write\n");
	}else
		printf("succe write\n");
	
	char buf[100]={"0"};
	// int ret = read(fd[0],buf,n);
	// printf("%d\n",ret );
	// printf("%s\n", fd[1]);
	return 0;
}