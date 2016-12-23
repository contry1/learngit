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
                int open_mode = O_WRONLY;
                const char *path = "/tmp/fifo_2";
                char buf[max];
                
                
                if (access(path,F_OK)!=-1)
                {

                    printf("is exist\n");
                }
                
                ret  = mkfifo(path,0777);
                
                
                
                if (ret == 0)
                {
                     printf("success create fifo\n");
                /* code */
                }else{
                    perror("fifo");
                }
                
                printf("Process %d opening FIFO \n", getpid());
                fd  =  open(path,open_mode);
                printf("Process %d result %d\n", getpid(), fd);
                sleep(5);
                if (fd!=-1)
                {
                    printf("open fifo ...\n");
                    for (int i = 0; i < max; ++i)
                    {
                        if ( fgets(buf,sizeof(buf),stdin)!=NULL)
                            {
               
                                printf("input :\n");
                            }
                            // input fromstdn
                        nwrite =  write(fd,buf,strlen(buf));
                        if (nwrite == -1)
                         {
                /* code */
                            printf("err write\n");
                         }else
                            printf("%s\n",buf );
                /* code */
                    }
                   
                /* code */
                }else
                    perror("open");

                 close(fd);
                return 0;
                }
