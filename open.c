// open.c
#include <stdlib.h>
#include <stdio.h>
 #include <fcntl.h>
int main(int argc, char const *argv[])
{
    const char * path = "/home/ll/fifo";
    int open_mode = O_RDWR|O_CLOEXEC;
    int  fd;
    int ret;
    fd  =  open(path,open_mode);
    if (fd==-1)
    {
        perror("open");
        /* code */
    }else
        printf("open success\n");
    ret = fcntl(fd,F_GETFL,0);

    printf("the status of fileflag:%d\n", ret);
    ret = fcntl(fd,F_GETFD,0);
    printf("the status of filefd:%d\n", ret);
    ret = fcntl(fd,F_GETLK,0);
    printf("the status of filelock:%d\n", ret);
    ret = fcntl(fd,F_SETLK,0);
     printf("the status of filelock:%d\n", ret);
    return 0;
}