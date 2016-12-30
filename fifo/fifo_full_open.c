            // sig_fifo.c
            #include <stdio.h>//
            #include <stdlib.h>//
            #include <sys/types.h>
            #include <sys/stat.h>
            #include <sys/wait.h>
            #include <errno.h>
            #include <string.h>//
            #include <fcntl.h>
            #include <unistd.h>
            #include <signal.h>
            
            #define  FIFO "./m_fifo"
            #define  FIFO_t "./_m_fifo"
            
            #define MAX 100
            static int * open_fifo(const char *path,int flag);
            
            static void mkfifo_t(pid_t pid);
            int main(int argc, char const *argv[])
            {
            /* code */
                pid_t pid;
                mkfifo_t(pid);
                return 0;
            } 
            
            static int * open_fifo(const char *path,int flag)
            {
                int * ret = NULL;
                ret =(int *)malloc(sizeof(int));
                *ret = open(path,flag);
                if (*ret == -1) 
                    perror("open");
                else
                    printf("open success\n");
                
                return  ret;
            
            }
            
            static void mkfifo_t(pid_t pid)
            {
                int n,ret,ref,nread,nwrite;
                char buf[MAX];
                memset(buf,'\0',MAX);
                char  * fp = NULL;
                int status ;
                int nwait ;
                int *ret_r =NULL;
                int *ret_w =NULL;
                int *ref_r = NULL;
                int *ref_w = NULL;
                int nr;
                
                
                ret = mkfifo(FIFO,0777);
                if (ret == -1) 
                    perror("mkfifo");
                // open son process and father process
                pid = fork();
                if (pid<0) 
                    printf("child process creat failed\n");
                else if (pid ==0) {
                    sleep(4);
                    printf("child process read start......\n");
                
                // child read from fifo that from father
                    ret_r = open_fifo(FIFO,O_RDONLY);
                    nread = read(*ret_r,buf,sizeof(buf));
                    if (nread == -1) 
                        perror("child read");
                    printf("the child read:%s\n",buf );

                    // /the child to write to father
                    printf("child process write start......\n");
                    ret_w = open_fifo(FIFO_t,O_WRONLY);
                    nr = write(*ret_w,"hello",6);
                    if (nr == -1) 
                        perror(" child write");

                    exit(0);
                }
                // the next is father
                printf("the father process start.....\n");
                fp = fgets(buf,sizeof(buf),stdin);
                if (fp == NULL) 
                    printf("fgets errno\n"); /* code */ 
                n = strlen(buf);
                printf("strlen of read buf: %d\n",n );
                if (fp[--n] == '\n') {
                    printf("the end file flag is '\\n'.\n");
                    fp[n] = '\0';
                }
                for (int i = 0; i < n; ++i) 
                    printf("%c\n",fp[i]);
                /* code */ 
                
/*                the father to write to child*/
                ref_r = open_fifo(FIFO,O_WRONLY);
                nwrite = write(*ref_r,buf,strlen(buf));
                if (nwrite == -1) {
                    if (errno == EINTR)
                        printf("the error is happened by signal int\n");
                    /* code */        
                    perror("father write");
                /* code */
                }
                
                /*                the father to read from child*/ 
                ref_w = open_fifo(FIFO_t,O_RDONLY);
                memset(buf,'\0',MAX);
                nread = read(*ref_w,buf,sizeof(buf)); 
                if (nread == -1)
                    perror("father read");
                printf("the father successfully:%s\n", buf);
                
                
                // putchar('\n');
                nwait = waitpid(pid,&status,0);
                if (nwait == -1) 
                    perror("waitpid");
                /* code */
                else
                    printf("the waitpid id :%d\n",status );
                
                
            
            }