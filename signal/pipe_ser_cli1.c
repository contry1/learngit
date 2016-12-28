// pipe_ser_cli.c
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

volatile   static sig_atomic_t flag;
sigset_t zeromask;
sigset_t newmask;
sigset_t oldmask; // signal handler

static void sig(int signo)
{
    flag = 1;
}

static void tell_wait(void)
{
        int ret = 0;
        if (signal(SIGUSR2,sig)==SIG_ERR) 
            printf("err USR2\n"); /* code */ 
        /* code */
        if (signal(SIGUSR1,sig)==SIG_ERR) 
                printf("err USR1\n");

        sigemptyset(&zeromask);
        sigemptyset(&newmask);
        sigaddset(&newmask,SIGUSR1);
        sigaddset(&newmask,SIGUSR2);

        ret = sigprocmask(SIG_BLOCK,&newmask,&oldmask);
        if (ret < 0) 
            perror("block int err");
            /* code */
        

}

static void tell_father(pid_t pid)
{
    printf("tell father................\n");
    kill(pid,SIGUSR2);
}

static void wait_father(void)
{
    printf("wait father.................\n");
    int ret;
    if (flag == 0) 
        sigsuspend(&zeromask);
        /* code */
    
    flag = 0;

    ret = sigprocmask(SIG_SETMASK,&oldmask,NULL);
    if (ret < 0) 
        perror("block int err"); /* code */
    // printf("the father is no block\n");

}

static void tell_child(pid_t pid)
{
    printf("tell child...............\n");
    kill(pid,SIGUSR1);
}

static void wait_child(void)
{
    printf("wait child...............\n");
    int ret;
    if (flag == 0) 
        sigsuspend(&zeromask);
        /* code */
    
    flag = 0;

    ret = sigprocmask(SIG_SETMASK,&oldmask,NULL);
    if (ret < 0) 
        perror("block int err"); /* code */
    
    // printf("the child is no block\n");

}

int main(int argc, char const *argv[])
{
    /* code */
    int fd1[2];
    int fd2[2];
    int ret =0;
    pid_t pid;

    char buf[1000];
    memset(buf,'\0',1000);
    tell_wait();
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
        wait_father();
        printf("the child process.....%d\n",getpid());
        printf("the child process's father process id:%d\n",getppid());
        close(fd1[1]);

        int nread = read(fd1[0],buf,sizeof(buf));
        if (nread == -1) {
            perror("read");
            /* code */
        }else
            printf("the child read fd1:%s\n",buf );

        tell_father(pid);

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
            p[len] = '\0';
             /* code */
         }
         nwrite = write(fd1[1],buf,len);
         if (nwrite == -1) 
            perror("write");
             /* code */

        tell_child(pid);
        wait_child();


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
