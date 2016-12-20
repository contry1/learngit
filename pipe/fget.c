// fget.c
                #include <stdio.h>
                #include <stdlib.h>
                #include <string.h>
                #include <unistd.h>
                #include <signal.h>
                #include <sys/types.h>
                #include <sys/wait.h>
                #include <fcntl.h>
                #define  nax 1000

static void fgets_io(void);
static void fork_io(pid_t pid);
int main(int argc, char const *argv[])
{
   pid_t pid;
   // fgets_io();
   fork_io(pid);
    
    return 0;
}

static void fgets_io(void)
{
     char buf[nax];
     char * p = NULL;
    int ret;
    int len;
    int fd[2];
     p = fgets(buf,nax,stdin);
    if (p==NULL)
    {
        /* code */
        printf("err get from stdin\n");
    }
    printf("printf:%s\n", buf);

    if (pipe(fd)==-1)
    {
        /* code */
        printf("err pipe\n");
    }
    len  =  strlen(buf);
    ret = write(fd[1],buf,len);
    if (ret == -1)
    {
        /* code */
        printf("err \n");
    }
    // next to read
    ret =  read(fd[0],buf,ret);
    printf("%d\n", ret);
    // at last to rewrite the temnial
    write(STDOUT_FILENO,buf,ret);

}
static void  fork_io(pid_t pid)
{
  
   int n,ret;
   char buf[nax];
   memset(buf,0,nax);
    pid  =  fork();
   if (pid < 0)
   {
       /* code */
        printf("err fork\n");
   }else if (pid==0)
   {
       /* code */
        printf("there is child...\n");
        while((n=read(STDIN_FILENO,buf,nax))>0){
            printf("the input is %s\n",buf );
           

        }
   }
   // the below is  father
                printf("there is father\n");

                ret= strlen(buf);
                printf("the next is father output:");
                n= write(STDOUT_FILENO,buf,ret);
                if (n==-1)
                {
                /* code */
                printf("err write\n");
                // continue;
                }
                 printf("the output is %s\n",buf );
           
                waitpid(pid,NULL,0);

}