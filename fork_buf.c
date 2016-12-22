#include <stdio.h>
                     #include <stdlib.h>
                     #include <string.h>
                     #include <unistd.h>
                     #include <signal.h>
                     #include <sys/types.h>
                     #include <sys/wait.h>
                     #include <fcntl.h>
 
int main(int argc, char const *argv[])
{
    pid_t pid;
    char buf[100] ;
    memset(buf,'\0',100);

    int n,ret;
    printf("hehherew\n");
    printf("hehherew");
    if ((pid = fork())<0)
    {
        /* code */
        perror("error");
    }
    else if (pid == 0)
    {
        /* code */
        
       
        printf("out from child\n");
       
        
    }else{
       
        
         printf("out from father\n");
       
           
         waitpid(pid,&ret,0);
    }
       
    
    return 0;
}