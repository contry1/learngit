             // pipe11.c
             #include <stdio.h>
             #include <stdlib.h>
             #include <unistd.h>
             #include <signal.h>
             #include <sys/types.h>
             #include <sys/wait.h>
             #include <fcntl.h>
             #define MAXNITEMS 300
             static void noblock_pipe(int pipefd[2]);
             static void block_pipe_read(int pipefd[2]);
             static void block_pipe_write(int pipefd[2]);
             static void func_pipe(int signo);
             static void block_pipe_write_signal(int pipefd[2]);
             static void _pipe_child_write_father_read(int pipefd[2]);
             static void _pipe_child_write_father_read_std(int pipefd[2]);
             static void _pipe_child_write_father_read_std2(int pipefd[2]);
             static void print_fd(void);
             static void print_std(void);
             int main(int argc, char const *argv[])
             {
             int pipefd[2];
             
             // noblock_pipe(pipefd);
             // block_pipe_read(pipefd);
             // block_pipe_write(pipefd);
             // block_pipe_write_signal(pipefd);
             // _pipe_child_write_father_read(pipefd);
            // _pipe_child_write_father_read_std(pipefd);
            _pipe_child_write_father_read_std2(pipefd);
             // print_fd();
             // print_std();
             return 0;
             }
             
             static void noblock_pipe(int pipefd[2])
             {
             int ret = 0;
             char buf[MAXNITEMS];
             if (pipe(pipefd)==-1)
             {
             /* code */
             perror("pipe");
             exit(-1);
             }
             printf("pipe finish\n");
             
             ret =  write(pipefd[1],"hwerew",7);
             if (ret == -1)
             {
             
             perror("write");
             }
             ret =  read(pipefd[0],buf,ret);
             if (ret == -1)
             {
             /* code */
             perror("read");
             }
             printf("the num of read byte %d\n", ret);
             printf("the read pipe:%s\n",buf );
             }
             
             /*the above is noblock pipe ,that is write and next to read*/
             
             static void block_pipe_read(int pipefd[2])
             {
             int ret = 0;
             char buf[MAXNITEMS];
             if (pipe(pipefd)==-1)
             {
             /* code */
             perror("pipe");
             exit(-1);
             }
             printf("pipe finish\n");
             
             // fisrt to read ,as of the pipe is no data,so the pipe will block
             
             ret =  read(pipefd[0],buf,ret);
             if (ret == -1)
             {
             /* code */
             perror("read");
             }
             printf("the num of read byte %d\n", ret);
             printf("the read pipe:%s\n",buf );
             // because of we bolckly read the pipe ,as of  there is no fork jincheng link with the write pipe ,so the read will be return directly
             ret =  write(pipefd[1],"hwerew",7);
             if (ret == -1)
             {
             
             perror("write");
             }
             // ret =  read(pipefd[0],buf,ret);
             
             printf("the num of read byte again %d\n", ret);
             
             printf("the read pipe again:%s\n",buf );
             // the overcome is null ,only we read pipe again.that is ret=read(pipefd[0],buf,ret) before the prntf
             }
             /*teh next is block pipe*/
             
             // the next is block_pipe_write
             
             static void block_pipe_write(int pipefd[2])
             {
             int ret = 0;
             char buf[MAXNITEMS];
             if (pipe(pipefd)==-1)
             {
             /* code */
             perror("pipe");
             exit(-1);
             }
             printf("pipe finish\n");
             
             close(pipefd[0]);
             // close the read pipe
             
             ret =  write(pipefd[1],"hwerew",7);
             if (ret == -1)
             {
             
             perror("write");
             }
             
             // the will be happen the signal SIGPIPE,and it default to exit.so the printf is no  print
             printf("the num of write byte %d\n", ret);
             
             
             
             }
             
             static void func_pipe(int signo)
             {
             if (signal(SIGPIPE,SIG_DFL)!=SIG_ERR)
             {
             /* code */
             printf("the default handler is to end up\n");
             }
             printf("we change the first sigpipe,and the end up is broken after the first\n");
             }
             
             static void block_pipe_write_signal(int pipefd[2])
             {
             int ret = 0;
             char buf[MAXNITEMS];
             if (pipe(pipefd)==-1)
             {
             /* code */
             perror("pipe");
             exit(-1);
             }
             printf("pipe finish\n");
             // signal(SIGPIPE,func_pipe);
             close(pipefd[0]);
             // close the read pipe
             signal(SIGPIPE,func_pipe);
             ret =  write(pipefd[1],"hwerew",7);
             if (ret == -1)
             {
             
             perror("write");
             }
             
             // the will be happen the signal SIGPIPE,but we catch the siganl so it will output
             printf("the num of write byte %d\n", ret);
             }
             
             // the next is pipe with fork
             static void _pipe_child_write_father_read(int pipefd[2])
             {
             int ret = 0;
             int status = 0;
             char buf[MAXNITEMS];
             pid_t pid;
             if (pipe(pipefd)==-1)
             {
             /* code */
             perror("pipe");
             exit(-1);
             }
             printf("pipe finish\n");
             
             // craete the child 
             if ((pid==fork())<0)
             {
             /* code */
             perror("fork");
             }else if (pid > 0)
             {
             /* code */
             printf("there is father\n");
             ret =  read(pipefd[0],buf,MAXNITEMS);
             if (ret == -1)
             {
             
             perror("write");
             }
             printf("%s\n", buf);
             ret = waitpid(pid,&status,0);
             if (ret < 0)
             {
             printf("err wait\n");
             /* code */
             }
             }else
             {
             // close(pipefd[0]);
             // close the read pipe
             
             ret =  write(pipefd[1],"hwerew",7);
             if (ret == -1)
             {
             
             perror("write");
             }
             
             
             printf("the num of write byte %d\n", ret);
             
             
             }
             
             
             
             
             }
             
             static void _pipe_child_write_father_read_std(int pipefd[2])
             {
             int ret = 0;
             int status = 0;
             char buf[MAXNITEMS];
             pid_t pid;
             if (pipe(pipefd)==-1)
             {
             /* code */
             perror("pipe");
             exit(-1);
             }
             printf("pipe finish\n");
             
             // craete the child 
             if ((pid==fork())<0)
             {
             /* code */
             perror("fork");
             }else if (pid > 0)
             {
             /* code */
                close(pipefd[1]);
                printf("there is father\n");
                 ret =  read(pipefd[0],buf,MAXNITEMS);
                if (ret == -1)
                {
             
                    perror("write");
                }
                printf("%s\n", buf);
                sleep(6);
                ret = waitpid(pid,&status,0);
                if (ret < 0)
                {
                printf("err wait\n");
                /* code */
                }
             }else
             {
             close(pipefd[0]);
             // close the read pipe
             ret =  write(pipefd[1],"hwerew",7);
             if (ret == -1)
             {
             
                perror("write");
             }
             
             
             printf("the num of write byte %d\n", ret);
             
             
             }
             
             
             
             
             }


             // *****************************************************
             static void _pipe_child_write_father_read_std2(int pipefd[2])
             {
             int ret = 0;
             int status = 0;
             char buf[MAXNITEMS];
             pid_t pid;
             if (pipe(pipefd)==-1)
             {
             /* code */
             perror("pipe");
             exit(-1);
             }
             printf("pipe finish\n");
             
             // craete the child 
             if ((pid==fork())<0)
             {
             /* code */
             perror("fork");
             }else if (pid > 0)
             {
             /* code */
                close(pipefd[1]);
                printf("there is father\n");
                 ret =  read(pipefd[0],buf,MAXNITEMS);
                if (ret == -1)
                {
             
                    perror("write");
                }
                printf("%s\n", buf);
                sleep(6);
               
             }else
             {
             close(pipefd[0]);
             // close the read pipe
             ret =  write(pipefd[1],buf,ret);
             if (ret == -1)
             {
             
                perror("write");
             }else{
                write(STDOUT_FILENO,buf,ret);
             }
             
             
             printf("the num of write byte %d\n", ret);
             
             
             }
             
             
             
             
             }
             // ************************************************
             
             static void print_fd(void)
             {
             char line[MAXNITEMS]={'0'};
             
             int fd;
             int n ;
             char buf[MAXNITEMS+1] = {'0'};
             
             fd = creat("./p11.txt",  O_RDWR);
             if (fd == -1)
             {
             /* code */
             perror("creat");
             }
             printf("pleaes input sentence:\n");
             
             
             n=read(fd,line,MAXNITEMS);
             if (n==-1)
             {
             /* code */
             perror("read");
             
             }else if (n==0)
             {
             /* code */
             printf("arrive the end of file\n");
             }else{
             printf("the read num byte%d\n",n );
             printf("the read:%s\n",buf );
             }
             
             // scanf("%s",line);
             n= write(fd,line,MAXNITEMS);
             if (n==-1)
             {
             /* code */
             perror("error write");
             }
             printf("\nthe write num byte:%d\n", n);
             
             close(fd);
             }
             
             static void print_std(void)
             {
             char line[MAXNITEMS]={'0'};
             
             int fd;
             int n ;
             char buf[MAXNITEMS+1] = {'0'};
             printf("pleaes input sentence:\n");
             // scanf("%s",line);
             n=read(STDIN_FILENO,buf,MAXNITEMS);
             if (n==-1)
             {
             /* code */
             perror("read");
             
             }else if(n >0)
             {
             printf("the read num byte:%d\n",n );
             printf("the read:%s\n",buf );
             
             if (write(STDOUT_FILENO,buf,n)!=n)
             {
             /* code */
             perror("error write");
             }
             
             
             
             }
             
             
             
             close(fd);
             }
             
             
             
