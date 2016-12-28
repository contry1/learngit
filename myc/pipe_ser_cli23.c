// pipe_ser_cli.c
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>

static void pipe_t (int fd[2]);
static void client_r(int fd1[2],int fd2[2]);
static void server_r(int fd1[2],int fd2[2]);
static void client_w(int fd1[2],int fd2[2]);
static void server_w(int fd1[2],int fd2[2]);

char buf[1000];
static int fd1[2];
static int fd2[2];
int main(int argc, char const *argv[])
{
    /* code */
    int ret =0;
    pid_t pid;

    memset(buf,'\0',1000);
    pipe_t (fd1);
    pipe_t (fd2);
 
    pid = fork();
    if (pid<0) {
        perror("fork");
        /* code */
    }else if (pid == 0) {

        // sleep(7);
        printf("the child process.....%d\n",getpid());
        printf("the child process's father process id:%d\n",getppid());

       // the next is child to read data 

        
        client_r(&fd1[2],&fd2[2]);
        client_w(&fd1[2],&fd2[2]);
        sleep(7);
        exit(0);


        /* code */
    }else{
        sleep(10);
        printf("the father process.......%d\n",getpid());
        printf("the father process's father process id:%d\n",getppid());

        server_w(&fd1[2],&fd2[2]);

        // let the client to write
        sleep(18);
        server_r(&fd1[2],&fd2[2]);


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


static void pipe_t (int fd[2])
{
    int ret = 0;
    ret = pipe(fd);
    if (ret == -1) {
        perror("pipe_t ");
        /* code */
    }
}


static void client_r(int fd1[2],int fd2[2])
{
        close(fd1[1]);
        int nread = read(fd1[0],buf,sizeof(buf));
        if (nread == -1) {
            perror("child read");
            /* code */
        }else
            printf("the child read fd1:%s\n",buf );



}

static void client_w(int fd1[2],int fd2[2])
{
       
/*        the next is child to write data 
*/        
        // close(fd2[0]);
        if (buf ==NULL) {
            printf("the buf is null\n");
            /* code */
        }else{
            printf("buf:::::%s\n",buf );
            int nwrite = write(fd2[1],buf,sizeof(buf));
            if (nwrite == -1) {
                perror("child write");
                /* code */
            }
        }
        printf("\n");

}

/**/
static void server_r(int fd1[2],int fd2[2])
{
      
      // the father to read data
      // sleep(18);
      // close(fd2[1]);
      int nread = read(fd2[0],buf,strlen(buf));
      if (nread == -1) {
          perror("father read");
          /* code */
      }else{
          printf("father read from child:%s\n", buf);
      }
}

static void server_w(int fd1[2],int fd2[2])
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
          perror("write");
           /* code */
      printf("\n");
    
}