// pipe_ser_cli.c
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>


static void client(int fd1[2],int fd2[2]);
static void server(int fd1[2],int fd2[2]);

char buf[1000];
int main(int argc, char const *argv[])
{
    /* code */
    int fd1[2];
    int fd2[2];
    int ret =0;
    pid_t pid;

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

       // the next is child to read data 

        sleep(6);
        // must let the father to run first
        client(&fd1[2],&fd2[2]);
        sleep(3);
            exit(0);


        /* code */
    }else{
        printf("the father process.......%d\n",getpid());
        printf("the father process's father process id:%d\n",getppid());

        server(&fd1[2],&fd2[2]);

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

static void client(int fd1[2],int fd2[2])
{
        close(fd1[1]);
        int nread = read(fd1[0],buf,sizeof(buf));
        if (nread == -1) {
            perror("read father");
            /* code */
        }else
            printf("the child read fd1:%s\n",buf );

/*        the next is child to write data

*/        
        close(fd2[0]);
        int nwrite = write(fd2[1],buf,strlen(buf)+1);
        if (nwrite == -1) {
            perror("write to father");
            /* code */
        }

}

/**/
static void server(int fd1[2],int fd2[2])
{
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
          p[len] = '\0';
           /* code */
       }
       nwrite = write(fd1[1],buf,len);
       if (nwrite == -1) 
          perror("write to child");
           /* code */
      printf("\n");
     /* /there must tongbu ,we can use signal or pipe or son open
      an  we must declare that let the the father to write ,after that is child to read*/

      sleep(5);
      // the father to read data
      close(fd2[1]);
      int nread = read(fd2[0],buf,strlen(buf));
      if (nread == -1) {
          perror("readchild");
          /* code */
      }else{
          printf("father read from child:%s\n", buf);
      }
}