// pipe12.c
 #include <stdio.h>
             #include <stdlib.h>
             #include <unistd.h>
             #include <signal.h>
             #include <sys/types.h>
             #include <sys/wait.h>
             #include <fcntl.h>
int main(int argc, char const *argv[])
{
    int fd[2];
    pid_t pid;
    int ret;
    char buf[100];
    if (pipe(fd)==-1)
    {
        /* code */
        printf("err \n");
    }
    pid = fork();
    if (pid < 0)
    {
        /* code */
        printf("err fork\n");
    }else if (pid > 0)
    {
        /* code */
        close(fd[0]);
        ret = write(fd[1],"hhhh\n",5);

    }else{
        close(fd[1]);
        read(fd[0],buf,ret);
        write(STDOUT_FILENO,buf,ret);
    }

    return 0;
}