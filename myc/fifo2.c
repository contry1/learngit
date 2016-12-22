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
#define fifo_name "/tmp/fifo"
#define max  100

int main(int argc, char const *argv[])
{
      int res;
      int open_mode = O_RDONLY;
      int i =0;
      int ret;
      char buf[max];
      if (argc<2)
      {
            //fprintf(stderr, "%s\n",*argv );
            /* code */
        printf("one..........\n");
      }
    
       if (access(fifo_name,F_OK)==-1)
    {
        /* code */
     
         res = mkfifo(fifo_name,0777);
         if (res)
         {
            perror("mkfifo");
            exit(0);
               /* code */
         }

   }
   printf("process %d open fifo\n",getpid() );
   res = open(fifo_name,open_mode);
   printf("process %d result %d\n",getpid() ,res);
   sleep(5);
   if (res!=-1)
   {
    

      while(++i<max)
      {
         ret=  read(res,buf,max);
         if (ret ==-1)
         {
           /* code */
            perror("read");
         }
         printf("read :%s\n",buf );
        
      }
      
         /* code */
      
   }
   printf("process %d  finish\n",getpid() );
  (void)close(res);
      return 0;
}