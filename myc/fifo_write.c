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
                int nwrite;
                int open_mode = O_RDWR|O_CREAT|O_NONBLOCK;
                const char *path = "/home/ll/fifo";
                char buf[max];
                
                
                if (access(path,F_OK)==-1)
                
                ret  = mkfifo(path,S_IRWXO);
                
                // ret  = mkfifo(path,S_IRWXO);
                // ret  = mkfifo(path,0777);
                
                if (ret == 0)
                {
                     printf("success create fifo\n");
                /* code */
                }else{
                    perror("fifo");
                }
                
                printf("Process %d opening FIFO O_RDWR\n", getpid());
                fd  =  open(path,open_mode,777);
                printf("Process %d result %d\n", getpid(), fd);
                
                if (fd!=-1)
                {
                printf("open fifo ...\n");
                for (int i = 0; i < max; ++i)
                {
                nwrite =  write(fd,buf,strlen(buf));
                if (nwrite == -1)
                {
                /* code */
                printf("err write\n");
                }else
                printf("%s\n",buf );
                /* code */
                }
                close(fd);
                /* code */
                }else
                perror("open");
                return 0;
                }
