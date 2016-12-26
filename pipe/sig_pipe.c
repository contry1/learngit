#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

sigset_t newmask,oldmask,zeromask;
static volatile sig_atomic_t flag;
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
    char buf[100]={'\0'};
    int fd[2];
    pipe(fd);
    signal(SIGPIPE,fun);
    pid_t pid;
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
        int nread = read(fd[0],buf,sizeof(buf));
        if (nread == -1) {
            printf("err  read:\n");
            /* code */ 
        }
        tell_father(pid);
        printf("child read:%s\n",buf );
        exit(0);      
    }else{
        // sleep(3);
        printf("the father process.......%d\n",getpid());
        printf("the father process's father process id:%d\n",getppid());
        close(fd[0]);//the sentense to invlole the SIGPIPE take place
        tell_child(pid);
        int  n = write(fd[1],"hshsh",6);
        if (n==-1) {
            printf("err write\n");
        }else
            printf("father write\n");

        wait_child();
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