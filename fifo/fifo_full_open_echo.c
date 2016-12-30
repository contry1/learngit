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
      
      #define max 1000
      static void mk_fifo(const char *path);
      static void mkfifo_t(pid_t pid);
      static int *open_fifo(const char *path,int flag);
      
      int main(int argc, char const *argv[])
      {
          /* code */
          pid_t pid;
          mkfifo_t(pid);
          return 0;
      } 
      
      
      static void mk_fifo(const char *path)
      {
          int ret = 0;
          ret = mkfifo(path,0777);
          if (ret == -1) {
          perror("mkfifo");
          /* code */
          }else
            printf("mk fifo success\n");
      
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
          int n,nread,nwrite;
          int * ret_r = NULL;
          int * ret_w = NULL;
          int * ref = NULL;
          int *ref_r = NULL;

          char buf[max];
          memset(buf,'\0',max);
          char  * fp = NULL;
          int status ;
          int nwait ;
          mk_fifo(FIFO);
          mk_fifo(FIFO_t);
          
          // open son process and father process
          pid = fork();
          if (pid<0) 
            perror("fork");
          else if (pid ==0) {

              sleep(4);
              printf("child process start......\n");
              ret_r = open_fifo(FIFO,O_RDONLY);
              nread = read(*ret_r,buf,sizeof(buf));
              if (nread == -1) 
                    perror("child read");
              printf("the child read:%s\n",buf );
              sleep(3);

              // /the next is  to write
              ret_w = open_fifo(FIFO_t,O_WRONLY);
              nwrite = write(*ret_w,buf,nread);
              if (nwrite == -1)
                perror("child write");
              sleep(2);

              exit(0);
          }
          // the next is father
          printf("the father process start.....\n");
          fp = fgets(buf,sizeof(buf),stdin);
          if (fp == NULL) 
                printf("fgets errno\n");
          n = strlen(buf);
          printf("strlen of read buf: %d\n",n );
          if (fp[--n] == '\n') {
                printf("the end file flag is '\\n'.\n");
                fp[n] = '\0';
          }
          /* code */
          for (int i = 0; i < n; ++i) 
                printf("%c\n",fp[i]);
          
          ref = open_fifo(FIFO,O_WRONLY);
          nwrite = write(*ref,buf,strlen(buf));
          if (nwrite == -1) {
                if (errno == EINTR) 
                    printf("the error is happened by signal int\n");
          /* code */
                perror("father write");
          }
               
      
          


          // read from the child
          // first to memset the buf
          ref_r = open_fifo(FIFO_t,O_RDONLY);
          memset(buf,'\0',max);
          sleep(2);
          nread = read(*ref_r,buf,sizeof(buf));
          if (nread == -1)
                perror("father read");
          printf("the father read:%s\n",buf );


         
          // putchar('\n');
          nwait = waitpid(pid,&status,0);
          if (nwait == -1) 
                perror("waitpid");
          /* code */
          else
                printf("the waitpid id :%d\n",status );
          
          
      
}