// pipe_ser_cli.c
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>



int main(int argc, char const *argv[])
{
    /* code */
    int fd1[2];
    int fd2[2];
    int ret =0;
    pid_t pid;

    char buf[1000];
    memset(buf,'\0',1000);
    ret = pipe(fd1);
    if (ret == -1) {
        perror("pipe");
        /* code */
    }
    ret = pipe(fd2);
    if (ret == -1) {
          perror("pipe");
          /* code */
    }
    pid = fork();
    if (pid<0) {
        perror("fork");
        /* code */
    }else if (pid == 0) {
        printf("the child process.....%d\n",getpid());
        printf("the child process's father process id:%d\n",getppid());
        close(fd1[1]);

        int nread = read(fd1[0],buf,sizeof(buf));
        if (nread == -1) {
            perror("read");
            /* code */
        }else
            printf("the child read fd1:%s\n",buf );


        exit(0);

        /* code */
    }else{
        printf("the father process.......%d\n",getpid());
        printf("the father process's father process id:%d\n",getppid());
        close(fd1[0]);

        int nwrite;
        char *p =NULL;
        p = fgets(buf,sizeof(buf),stdin);
        if (p == NULL) 
            perror("fgets");
            /* code */
         // delete the \n
         int len = strlen(buf);
         if (p[--len] == '\n') {
            printf("the \\n is buffer\n");
            // len--;
            p[len] = '\0';
             /* code */
         }
         nwrite = write(fd1[1],buf,len);
         if (nwrite == -1) 
            perror("write");
             /* code */

        int status = 0;
        int pid_ret;
        pid_ret = waitpid(pid,&status,0);
        if (pid_ret == 0) {
            printf("status:%d\n",status );
            printf("successfully wait child\n");
            /* code */
        }
         
        
    }
    return 0;
}
