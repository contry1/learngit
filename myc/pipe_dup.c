// popen2.c
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 1000
int main(int argc, char const *argv[])
{
	
	char buf[max];
	pid_t ret;
	int nread;
	memset(buf,'\0',sizeof(buf));
	int pipe_fd[2];
	char line[20] ="hello tom";
	if (pipe(pipe_fd)==0)
	{
		printf("success pipe\n");
		ret = fork();
		if (ret < 0)
		{
			perror("fork");
			/* code */
		}
		else if (ret == 0)
		{
			close(0);
			dup(pipe_fd[0]);
			close(pipe_fd[0]);
			close(pipe_fd[1]);
			execlp("od","od","-c",(char *)0);

			/* code */
		}else{
			printf("the father process\n");
			close(pipe_fd[0]);
			nread = write(pipe_fd[1],line,sizeof(line));
			if (nread == -1)
			{
				perror("error");
				/* code */
			}

			waitpid(ret,NULL,0);

		}
		/* code */
	}
	return 0;
}