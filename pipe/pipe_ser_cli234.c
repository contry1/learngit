// pipe_ser_cli.c
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>

static void pipe_t (int fd[2]);
static void client(int fd1[2],int fd2[2]);
static void server(int fd1[2],int fd2[2]);


static int fd1[2];
static int fd2[2];
#define MAXNITEMS 1000
int main(int argc, char const *argv[])
{
    /* code */
    int ret =0;
    pid_t pid;

    char buf[MAXNITEMS];
    memset(buf,'\0',MAXNITEMS);
    pipe_t (fd1);
    pipe_t (fd2);
 
    pid = fork();
    if (pid<0) {
        perror("fork");
        /* code */
    }else if (pid == 0) {

       sleep(2);
        printf("the child process.....%d\n",getpid());
        printf("the child process's father process id:%d\n",getppid());

       // the next is child to read data 

        
        
        client(&fd1[2],&fd2[2]);


        sleep(7);
        exit(0);


        /* code */
    }else{
       
        printf("the father process.......%d\n",getpid());
        printf("the father process's father process id:%d\n",getppid());

        server(&fd1[2],&fd2[2]);

        // let the client to write
        sleep(2);
       


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
    if (ret == -1) 
        perror("pipe_t ");
        /* code */
    
}




static void client(int fd1[2],int fd2[2])
{
       
/*        the next is child to write data 
*/        
        // close(fd2[0]);
        char buf[MAXNITEMS];
        memset(buf,'\0',MAXNITEMS);

        // dup2(fd1[0],0);
        int nread = read(fd1[0],buf,sizeof(buf));
        if (nread == -1) 
            perror("child......... read");
        printf("the child read fd1:%s\n",buf );

        
        // dup2(fd2[1],1);
        if (fd2[1] == fd1[1]) {
            printf("the pieeeeeee\n");
            /* code */
        }
        int nwrite = write(fd2[1],buf,nread);
        if (nwrite == -1) 
            perror("child write"); /* code */ 
        else
          printf("\nchild write successfully\n");
        exit(0);

}

/**/


static void server(int fd1[2],int fd2[2])
{


      close(fd1[0]);
      int nwrite;
      char *p =NULL;
      char buf[MAXNITEMS];
      memset(buf,'\0',MAXNITEMS);

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
      // printf("\n"); 
      
      
      //dup2(fd2[0],0);
      sleep(2);
      memset(buf,'\0',MAXNITEMS);
      fflush(stdin);
      int nread = read(fd2[1],buf,sizeof(buf));
      if (nread == -1) 
          perror("father read");
          /* code */
      else
          printf("father read from child:%s\n", buf);
          //write(STDOUT_FILENO,buf,nread);
      
    
}