#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
sigset_t newmask,oldmask,zeromask;
static volatile sig_atomic_t flag;
#define MAXSIZE 300
static void fun(int signo)
{
    printf("fun pipe\n");
}
static void sighandler(int signo)
{
    flag = 1;
}
static void tell_wait(void)
{
    // signal(SIGUSR2,sighandler);
    int ret;
    if (signal(SIGUSR2,sighandler)==SIG_ERR) {
        /* code */
        perror("signal");
    }
    if (signal(SIGUSR1,sighandler)==SIG_ERR) {
            /* code */
            perror("signal");
    }
    sigemptyset(&newmask);
    sigemptyset(&zeromask);

    sigaddset(&newmask,SIGUSR1);
    sigaddset(&newmask,SIGUSR2);

    ret = sigprocmask(SIG_BLOCK,&newmask,&oldmask);
    if (ret == -1) {
        printf("set the usr1 usr2 block failed\n");
        /* code */
    }
 }
static void tell_father(pid_t pid)
{
    kill(pid,SIGUSR2);

}
static void wait_father(void)
{
    printf("waiting father.......\n");
    if (flag == 0) 
        sigsuspend(&zeromask);
    flag = 0;
    if (sigprocmask(SIG_SETMASK,&oldmask,NULL)<0) {
        printf("set SIGUSR2 UNBLOCK failed\n");
        /* code */
    }
}
static void tell_child(pid_t pid)
{
     kill(pid,SIGUSR1);
}
static void wait_child(void)
{
    printf("waiting child.......\n");
    if (flag == 0) 
        sigsuspend(&zeromask);
    flag = 0;
    if (sigprocmask(SIG_SETMASK,&oldmask,0)<0) {
        printf("set SIGUSR1 UNBLOCK failed\n");
        /* code */
    }
    

}
int main(int argc, char const *argv[])
{
    char buf[MAXSIZE]={'\0'};
    char buf_r[MAXSIZE]={'\0'};

    int fd[2];
    pipe(fd);
    signal(SIGPIPE,fun);
    pid_t pid;
    int len = 0;
    int nr = 0;
    int sum = 0;
    int nread,len_r;
    //signal tongbu
    tell_wait();
    //sgnal tongbu
    pid  = fork();
    if (pid <0) {
        perror("error");
        /* code */
    }else if (pid == 0) {
        /* code */
       
        wait_father();
        printf("the child process.....%d\n",getpid());
        printf("the child process's father process id:%d\n",getppid());
        close(fd[1]);

        while((nread = read(fd[0],buf,sizeof(buf)))!=-1){
            tell_father(pid);
            setbuf(stdout,NULL);//set the stdout no buffer
            printf("the child write to stdout:");
            write(STDOUT_FILENO,buf,nread); //the write to stdout is bo bug ,but the printf is bug

            len_r = strlen(buf);
            printf("len_r :%d\n",len_r );

            for (int i = 0; (buf[i]!='\n'); i++) {
                sum +=i;
                printf("sum:%d\n",sum );
                printf("buf[%d]:%c\t",i,buf[i] );
                if (buf[i]=='\0') {
                    break;
                    
                }

            }
            printf("\n");

            // printf("child read:%s\n",buf ); //the sentence is bug ,it  is  of buffer and \n
        }
        exit(0);      
    }else{
        // sleep(3);
        tell_child(pid);
        printf("the father process.......%d\n",getpid());
        printf("the father process's father process id:%d\n",getppid());
        close(fd[0]);//the sentense to invlole the SIGPIPE take place
        char * p  = NULL; /* code */ 
        while((p = fgets(buf,sizeof(buf),stdin))!=NULL){

            len = strlen(buf);
            printf("the length :%d\n",len );
            if (p[len] =='\n') {
                printf("%c\n",p[len -1] );
                len--;
                p[len ] = '\0';
                /* code */
            }
            if (p[len -1] == '\0') {
                printf("fgets  read the null in buffer\n");
                /* code */
            }

            fflush(stdin);
            int  n = write(fd[1],buf,len);
            if (n==-1) {
                if (errno = EINTR) {
                    printf("the failed is SIGINT\n");
                    /* code */
                }
                printf("err write\n");
            }else
                printf("father write to pipe successfully\n");

            wait_child();
        }

        int status;
        // the waitpid 's return val is the son process pid,if it wait to catch the son state successfully
        int ret = waitpid(pid,&status,0);
        if (ret == -1) {
            printf("wait child failed\n");
            /* code */
        }else
            printf("the wait id:%d\n", ret);//the ret == son pid
        
    }

    
  
    return 0;
}