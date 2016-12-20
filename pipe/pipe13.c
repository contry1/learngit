                // pipe12.c
                #include <stdio.h>
                #include <stdlib.h>
                #include <string.h>
                #include <unistd.h>
                #include <signal.h>
                #include <sys/types.h>
                #include <sys/wait.h>
                #include <fcntl.h>
                #define  max 1000
                int main(int argc, char const *argv[])
                {
                int fd[2];
                pid_t pid;
                int ret;
                char buf[max];
                 char * p = NULL;
                 int len;
                if (pipe(fd)==-1)
                {
                /* code */
                printf("err \n");
                }
                pid = fork();
                if (pid < 0)
                {
                /* code */
                printf("err fork\n");
                }else if (pid == 0)
                {
                /* code */
                printf("the func is child\n");
                close(fd[0]);
                printf("the child input:\n");
                p = fgets(buf,max,stdin);
                if (p==NULL)
                    {
                        /* code */
                        printf("err get from stdin\n");
                    }
                printf("printf:%s\n", buf);
               
                len  =  strlen(buf);
                ret = write(fd[1],buf,len);
                if (ret == -1)
                {
                    /* code */
                    printf("err \n");
                }
                
                
                }
                printf("there is father\n");
                close(fd[1]);
                read(fd[0],buf,ret);
                write(STDOUT_FILENO,buf,ret);
                waitpid(pid,NULL,0);
                return 0;
                }