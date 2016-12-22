// popen2.c
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 10
int main(int argc, char const *argv[])
{
	
	char buf[max];
	pid_t ret;
	int nread,n,nwrite;
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
			//close(STDOUT_FILENO);
			//dup(pipe_fd[1]);
			sleep(5);
			close(pipe_fd[0]);
			// close(pipe_fd[1]);
			putchar('\n');
			fflush(stdout);
			printf("output:\n");
			 nwrite =write(STDOUT_FILENO,buf,nread);
			 if (nwrite == -1)
			 {
			 	/* code */
			 	printf("err write,and the exact data %s\n",buf );
			 }
			sleep(3);

			/* code */
		}else{
			printf("the father process\n");
			close(pipe_fd[1]);
			if (pipe_fd[0]!=STDIN_FILENO)
			{
				printf("dup the pipe fd to stdin fd\n");
				n=dup2(pipe_fd[0],STDIN_FILENO);
				if (n == -1)
				{
					perror("dup2");
					/* code */
				}
				/* code */
			}
			nread = read(pipe_fd[0],buf,sizeof(buf));
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