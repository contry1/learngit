 #include <stdio.h>
                 #include <stdlib.h>
                 #include <string.h>
                 #include <unistd.h>
                 #include <signal.h>
                 #include <sys/types.h>
                 #include <sys/wait.h>
                 #include <fcntl.h>
#define max 10
int main(int argc, char const *argv[])
{
    int ret =0;
    int n =0;
    char line[max];
    memset(line,'\0',max);
    #if 0
    ret = read(STDIN_FILENO,line,max);
    if (ret<0)
    {
        /* code */
        perror("read");
    }
    n = write(STDOUT_FILENO,line,ret);
    if (n == -1)
    {
        /* code */
        perror("write");
    }

#endif
    #if 0
    while((ret = read(STDIN_FILENO,line,max))>0){

        printf("\nread num:%d\n",ret );
        n = write(STDOUT_FILENO,line,ret);
        if (n !=ret)
         {
        /* code */
         perror("write");
        }

        printf("\nwrite%s\n",line );


    }
#endif
    
    ret = read(STDIN_FILENO,line,max);
    if (ret < max&&ret>0)
    {
        /* code */
        printf("%d\n", ret );
    }
    ret = read(STDIN_FILENO,line,max);
    printf("%d\n", ret);
    return 0;
}