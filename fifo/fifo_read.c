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
                #define  path  "/tmp/fifo_2"
                int main(int argc, char const *argv[])
                {
                /* code */
                int ret;
                int fd;
                int nread;
                int  i;
                int open_mode = O_RDONLY;
               
                char buf[max];
                
                if (access(path,F_OK)==0)
                {
                /* code */
                    printf("THE fifo IS EXIST\n");
                }

                ret  = mkfifo(path,0777);
                if (ret == 0)
                {
                     printf("success create fifo\n");
                /* code */
                }else
                     perror("fifo");
                
                
                
                printf("Process %d opening FIFO \n", getpid());
                fd  =  open(path,open_mode);
                printf("Process %d result %d\n", getpid(), fd);
                sleep(5);
                if (fd!=-1)
                {
                    printf("open fifo ...\n");
                   while(i<max){
                        nread =  read(fd,buf,max);
                        if (nread == -1)
                        {
                /* code */
                        printf("err read\n");
                        }else
                            // printf("%s\n",buf );
                            fflush(stdout);
                            write(STDOUT_FILENO,buf,nread);
                        i += nread;
                    }
                
                /* code */
                }

                close(fd);
                return 0;
                }
