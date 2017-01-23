   /*
   * =====================================================================================
   *
   *       Filename:  client.c
   *
   *    Description:  
   *
   *        Version:  1.0
   *        Created:  12/15/2015 07:04:13 PM
   *       Revision:  none
   *       Compiler:  gcc
   *
   *         Author:  lg (), 
   *   Organization:  
   *
   * =====================================================================================
   */
   #include <stdlib.h>
   #include <stdio.h>  
   // #include <mysql/mysql.h>
   #include <stdlib.h>  
   #include <string.h>  
   #include <unistd.h>  
   #include <sys/types.h>    
   #include <sys/socket.h>  
   #include <netinet/in.h>  
   #include <arpa/inet.h>    
   #include <signal.h>
   
   // #include <pthread.h>
   #define  PORT 1234    
   #define  BACKLOG 10 
   #define MAXNITEMS 1024
   
   struct  sockaddr_in server;    
   struct  sockaddr_in client;    
   socklen_t  addrlen;   
   // void *query(void * arg);
   int *create_and_set_socket(int *fd,int *opt);
   static void create_and_set_socket2(int *fd,int *opt);

   void cli_data(int fd,char buf[MAXNITEMS]);
   void send_t(int fd, const void *buf, size_t len, int flags);
   void recv_t(int fd, void *buf, size_t len, int flags);
   void sigint(int signo);
   int sockfd;
   
   int main() {
       // buf2= buf[0];
       int newfd,ret; 
       static int i =0;
       int connectfd;
       int val,num; 
       char buf[MAXNITEMS]={0};
       char sendbuf[MAXNITEMS];
       
       
       int sockfd = 0;
       int opt_r = 0;
      /* if (create_and_set_socket(&sockfd,&opt_r)==NULL) 
            perror("ERRRRR");*/
        create_and_set_socket2(&sockfd,&opt_r);

       
       if (connect(sockfd,(struct sockaddr *) &server, sizeof(server)) < 0) {
       printf("Failed to connect with server\n");
       }else {
       printf("客户端 连接 服务器端口 %d成功...\n",server.sin_port);
       }
       while(1) {
       cli_data(sockfd, buf);
       signal(SIGINT,sigint);
       
       
       
       }
       
       close(sockfd);
       return 0;
       }
       
       int * create_and_set_socket(int *fd,int *opt)
       {
           if((*fd  = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
               perror("Creating  socket failed.");  
               exit(1);     
           } 
           if (opt == NULL) {
               printf("the opt is null\n");
               exit(-1);
               /* code */
           }else{
               setsockopt(*fd,SOL_SOCKET, SO_REUSEADDR, opt, sizeof(*opt)); //could reuse the localaddr 
               memset(&server,0,sizeof(server));  
               server.sin_family=AF_INET;  
               server.sin_port=htons(PORT);    
               server.sin_addr.s_addr= htonl (INADDR_ANY);
           }
           
           return fd;
       
       
       
       }


       static void create_and_set_socket2(int *fd,int *opt)
             {
                 if((*fd  = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
                     perror("Creating  socket failed.");  
                     exit(1);     
                 } 
                 if (opt == NULL) {
                     printf("the opt is null\n");
                     exit(-1);
                     /* code */
                 }else{
                     setsockopt(*fd,SOL_SOCKET, SO_REUSEADDR, opt, sizeof(*opt)); //could reuse the localaddr 
                     memset(&server,0,sizeof(server));  
                     server.sin_family=AF_INET;  
                     server.sin_port=htons(PORT);    
                     server.sin_addr.s_addr= htonl (INADDR_ANY);
                 }
                 
                 
             
             
             
             }
       
       void cli_data(int fd,char buf[MAXNITEMS])
       {
       memset(buf,'\0',MAXNITEMS);
       char *p = NULL;
       int flags=0;
       p = fgets(buf,MAXNITEMS,stdin);
       if (p ==NULL) 
       perror("fgets");
       /* code */
       int len =  strlen(buf);
       printf("输入消息长度，包含'\\n':%d 字节\n",len );
       // /delete the \n
       if (p[--len] == '\n') {
       p[len] = '\0';
       /* code */
       }
       printf("输入有效消息长度:%d 字节\n",len );
       
       
       send_t(fd,buf,len,flags);
       recv_t(fd,buf,MAXNITEMS,flags);
       }
       
       void send_t(int fd, const void *buf, size_t len, int flags)
       {
       // int sockfd, const void *buf, size_t len, int flags
       int ret = send(fd,buf,len,flags);
       if (ret == -1)
       perror("send");
       else
       printf("客户端发送成功\n");
       
       }
       
       void recv_t(int fd, void *buf, size_t len, int flags)
       {
       memset(buf,'\0',MAXNITEMS);
       int nread=recv(fd,buf,len,flags);
       if (nread == -1)
       perror("nread");
       else
       printf("客户端收到消息:%s\n",(char *)buf);
       }
       
       
       void sigint(int signo)
       {
       printf("the client ctrl +c to quit\n");
       close(sockfd);
       
       exit(0);
   }