// buf_atr.c
#include <ctype.h>
#include <stdio.h>
             #include <stdlib.h>
             #include <string.h>

             #include <unistd.h>
             #include <signal.h>
             #include <sys/types.h>
             #include <sys/wait.h>
             #include <fcntl.h>
#define MAXNITEMS 100

static void dup_common(int ret,int nwrite,char buf[]);
static void dup_common1(int ret,int nwrite,char buf[]);

static void dup_nobuf_write(int ret,int nwrite,char buf[]);
static void dup_nobuf_read(int ret,int nwrite,char buf[]);


int main(int argc, char const *argv[])
{
    /* code */
    int ret;
    int nwrite;
    char buf[MAXNITEMS];
    dup_common(ret,nwrite,buf);
    // dup_common1(ret,nwrite,buf);
    // dup_nobuf_write(ret,nwrite,buf);
    // dup_nobuf_read(ret,nwrite,buf);
    return 0;
}

static void dup_common(int ret,int nwrite,char buf[])
{
     while((ret=  read(STDIN_FILENO,buf,MAXNITEMS))>0)
    {
        nwrite =  write(STDOUT_FILENO,buf,ret);
        if (nwrite<0)
        {
            /* code */
            perror("write");
        }
    }
}


static void dup_common1(int ret,int nwrite,char buf[])
{
     while((ret=  read(STDIN_FILENO,buf,strlen(buf)))>0)
    {
        nwrite =  write(STDOUT_FILENO,buf,ret);
        if (nwrite<0)
        {
            /* code */
            perror("write");
        }
    }
}


static void dup_nobuf_write(int ret,int nwrite,char buf[])
{
     while((ret=  read(STDIN_FILENO,buf,MAXNITEMS))>0)
    {
        
        setbuf(stdout,NULL);
                // setbuf(stdout,_IONBF);

        printf("set stdout no buf\n");
        nwrite =  write(STDOUT_FILENO,buf,ret);
        if (nwrite<0)
        {
            /* code */
            perror("write");
        }
    }
}

static void dup_nobuf_read(int ret,int nwrite,char buf[])
{
     setbuf(stdin,NULL);
     while((ret=  read(STDIN_FILENO,buf,MAXNITEMS))>0)
    {
        
       
                // setbuf(stdout,_IONBF);

        printf("set stdout no buf\n");
        nwrite =  write(STDOUT_FILENO,buf,ret);
        if (nwrite<0)
        {
            /* code */
            perror("write");
        }
    }
}


