             // fifo.c
             #include <stdio.h>
             #include <stdlib.h>
             #include <string.h>
             #include <unistd.h>
             #include <signal.h>
             #include <sys/types.h>
             #include <sys/wait.h>
 #include <sys/types.h>
       #include <sys/stat.h>
             #include <fcntl.h>
#define max 100
int main(int argc, char const *argv[])
{
    /* code */
    int ret;
    int fd;
    int nread;
    int open_mode = O_RDONLY;
    const char *path = "/home/ll/fifo";
    char buf[max];

    if (access(path,F_OK)==0)
    {
        /* code */
        printf("THE fifo IS EXIST\n");
    }else{
         ret  = mkfifo(path,S_IRWXO);
         if (ret == 0)
        {
         printf("success create fifo\n");
        /* code */
        }else
            perror("fifo");

    }
   
    printf("Process %d opening FIFO O_RDONLY\n", getpid());
    fd  =  open(path,open_mode,S_IRWXO);
    printf("Process %d result %d\n", getpid(), fd);
    if (fd!=-1)
    {
        printf("open fifo ...\n");
        for (int i = 0; i < max; ++i)
        {
            nread =  read(fd,buf,max);
            if (nread == -1)
            {
                /* code */
                printf("err read\n");
            }else
                printf("%s\n",buf );
            /* code */
        }
        close(fd);
        /* code */
    }
    return 0;
}
