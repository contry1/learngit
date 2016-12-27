// sig_fifo.c
#include <stdio.h>//
#include <stdlib.h>//
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>//
 #include <fcntl.h>
#include <unistd.h>
#include <signal.h>

#define  FIFO "./m_fifo"
#define max 100
static void sigpipe(int signo);
 static void mkfifo_t(pid_t pid);
int main(int argc, char const *argv[])
 {
     /* code */
    pid_t pid;
    // int status= 0;
    // int nwait;
    mkfifo_t(pid);
     return 0;
 } 

 static void sigpipe(int signo)
 {
    printf("signal happen\n");
    printf("signo:%d\n", signo);
 }
 static void mkfifo_t(pid_t pid)
 {
    int n,ret,ref,nread,nwrite;
    char buf[max];
    char  * fp = NULL;
    int status ;
    int nwait ;
    if ( signal(SIGPIPE,sigpipe)== SIG_ERR) {
        printf("sigpipe error\n");
        /* code */
    }
    ret = mkfifo(FIFO,0777);
    if (ret == -1) {
        perror("mkfifo");
        /* code */
    }
     // open son process and father process
    pid = fork();
    if (pid<0) {
        printf("child process creat failed\n");
    }else if (pid ==0) {
        sleep(7);
        printf("child process start......\n");
        ret = open(FIFO,O_RDONLY);
        if (ret == -1) {
            perror("open");
            /* code */
        }
        nread = read(ret,buf,sizeof(buf));
        if (nread == -1) {
            perror("read");
            /* code */
        }
        printf("the child read:%s\n",buf );
       

        
        sleep(2);
        close(ret);//close fifo read line
        // wait again the father to write
       
        sleep(3);
      
        exit(0);
    }
    // the next is father
    printf("the father process start.....\n");
    // ref = open(FIFO,O_WRONLY|O_NONBLOCK);
    ref = open(FIFO,O_WRONLY);

    if (ref == -1) {
        perror("open");
        /* code */
    }
    int flag =  fcntl(ref,F_GETFL);
    flag |= O_NONBLOCK;
    fcntl(ref,F_SETFL,flag);
    fp = fgets(buf,sizeof(buf),stdin);
    if (fp == NULL) {
        printf("fgets errno\n");
        /* code */
    }

    // the next sentence is deal with the fgets's the '\n' question
    n = strlen(buf);
    printf("strlen of read buf: %d\n",n );
    if (fp[--n] == '\n') {
        printf("the end file flag is '\\n'.\n");
        fp[n] = '\0';
    }
    
 /* code */
    for (int i = 0; i < n; ++i) {
        printf("%c\n",fp[i]);
        /* code */
    }
    
    nwrite = write(ref,buf,strlen(buf));
    if (nwrite == -1) {
        if (errno == EINTR) {
            // continue;
            printf("the error is happened by signal int\n");
            /* code */
        }
        perror("write");
        /* code */
    }

    //write again
    sleep(3);
    printf("we sleep 3 s\n");
    close(ref);
   
   
    
    nwrite = write(ref,buf,strlen(buf));
    if (nwrite == -1) {
        if (errno == EINTR) {
            // continue;
            printf("the error2 is happened by signal int\n");
            /* code */
        }
        perror("write2");
        /* code */
    }
    /* code */

   
    // putchar('\n');
    nwait = waitpid(pid,&status,0);
    if (nwait == -1) {
        perror("waitpid");
        /* code */
    }else{
        printf("the waitpid id :%d\n",status );
    }


 }