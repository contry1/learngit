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
#define  FIFO_t "./_m_fifo"

#define max 100

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

 
 static void mkfifo_t(pid_t pid)
 {
    int n,ret,ref,nread,nwrite;
    char buf[max];
    memset(buf,'\0',max);
    char  * fp = NULL;
    int status ;
    int nwait ;
    int nr;
   
    
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
        sleep(4);
        printf("child process read start......\n");
        ret = open(FIFO,O_RDONLY);
        if (ret == -1) 
            perror("child open read"); /* code */ 
        nread = read(ret,buf,sizeof(buf));
        if (nread == -1) 
            perror("child read");
        printf("the child read:%s\n",buf );
       

        sleep(3);
        // /the child to write
        printf("child process write start......\n");
        ret = open(FIFO_t,O_WRONLY);
        if (ret == -1) 
            perror("child open write"); /* code */ 
        nr = write(ret,buf,nread);
        if (nr == -1) 
            perror(" child write");

        
      
        exit(0);
    }
    // the next is father
    printf("the father process start.....\n");
    ref = open(FIFO,O_WRONLY);
    if (ref == -1) 
        perror("father open write"); /* code */
    
    fp = fgets(buf,sizeof(buf),stdin);
    if (fp == NULL) 
        printf("fgets errno\n"); /* code */ 
    n = strlen(buf);
    printf("strlen of read buf: %d\n",n );
    if (fp[--n] == '\n') {
        printf("the end file flag is '\\n'.\n");
        fp[n] = '\0';
    }
    for (int i = 0; i < n; ++i) 
        printf("%c\n",fp[i]);
        /* code */ 
    nwrite = write(ref,buf,strlen(buf));
    if (nwrite == -1) {
        if (errno == EINTR)
            printf("the error is happened by signal int\n");
            /* code */        
        perror("father write");
        /* code */
    }

   
    int ref_t = 0;
    ref_t = open(FIFO_t,O_RDONLY);
    if (ref_t == -1) 
            perror("father open read"); /* code */
    memset(buf,'\0',max);
    nread = read(ref_t,buf,sizeof(buf)); 
    if (nread == -1)
        perror("father read");
    printf("the father successfully:%s\n", buf);
   
   
    // putchar('\n');
    nwait = waitpid(pid,&status,0);
    if (nwait == -1) {
        perror("waitpid");
        /* code */
    }else{
        printf("the waitpid id :%d\n",status );
    }


 }