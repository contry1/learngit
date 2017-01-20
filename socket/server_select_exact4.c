
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
    #include <sys/select.h>
    #include <errno.h>

    #include <netdb.h>
    #define  PORT 1234    
    #define  BACKLOG 10 
    #define MAXNITEMS 1024
    typedef void *(* pfunc)(void *);

    struct  sockaddr_in server;    
    struct  sockaddr_in client_addr;    
    socklen_t  addrlen;   


    void listen_t(int fd);
    int * accept_t(int fd,int *fd_dst);


    void ser_data(int fd,char buf[]);
    int * recv_t(int fd, void *buf, size_t len, int flags,int *nread);
    void send_t(int fd, const void *buf, size_t len, int flags);

    void sigint(int signo);
    struct serfd {
    int listenfd;
    int connectfd;
    char buf[MAXNITEMS];
    pthread_mutex_t lock;

    };


    int main() {

    int i = 0;
    int ret = 0;
    struct serfd *sf = NULL;
    sf = realloc(sf,sizeof(struct serfd));
    struct serfd sfd = {

        .listenfd = 3,
        .connectfd =4,
        .buf[MAXNITEMS-50]=0,

    };
    sf = &sfd;
    if((sf->listenfd  = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Creating  socket failed.");  
        exit(1);     
    } 

    int opt =SO_REUSEADDR;  
    setsockopt(sf->listenfd,SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));  
    memset(&server,0,sizeof(server));  
    server.sin_family=AF_INET;  
    server.sin_port=htons(PORT);    
    server.sin_addr.s_addr= htonl (INADDR_ANY);   

    if(bind(sf->listenfd, (struct sockaddr *)&server, sizeof(server)) ==   -1) {
        perror("Binderror.");   
        exit(1);     
    }

    listen_t(sf->listenfd); /* code */ 
    int *p =NULL;
    int nread = 0;
    int flag = 0;
    int client[BACKLOG];
    for (int i = 0; i < BACKLOG; ++i) 
        client[i] = -1;
    int sockfd;
    int cnt = -1;//ready max index
   


    fd_set rset,allset;
    FD_ZERO(&allset);
    FD_SET(sf->listenfd,&allset);
    while(1) {
      /* Block until input arrives on one or more active sockets. */
      rset = allset;
      select (BACKLOG+1, &rset, NULL, NULL, NULL); 
      
      /* Service all the sockets with input pending. */
      for (i = 0; i < BACKLOG; ++i)
          if (FD_ISSET (i, &rset)) {
              if (i == sf->listenfd) {
                  /* Connection request on original socket. */
                  int *new;
                  
                  new = accept_t (sf->listenfd, &(sf->connectfd));
                  if (*new < 0) {
                      perror ("accept");
                      exit (EXIT_FAILURE);
                  }
                  fprintf (stderr, "Server: connect from host %s, port %hd.\n", inet_ntoa (client_addr.sin_addr), ntohs (client_addr.sin_port));
                  FD_SET (*new, &allset);
              }

            else
            {
              /* Data arriving on an already-connected socket. */
               p = recv_t(i,sf->buf,MAXNITEMS,0,&nread);
               if (*p > 0) {
                   printf("服务器端收到字节 :%d byte\n", *p);
                   send_t(i,sf->buf,strlen(sf->buf),0);
                   putchar('\n');
               }else{
                   printf("客户端断开\n");
                   close(i);
                   FD_CLR (i, &allset);//the above 123 124 is very import,if not ,it will print 客户端断开 all the time
                   break;
               }
          }

/*


        rset = allset;
        int maxfd = sf->connectfd > sf->listenfd ? sf->connectfd :sf->listenfd;
        int retval =  select(maxfd+1,&rset,NULL,NULL,NULL);
        for (i = 0; i < BACKLOG; i++)
               if(FD_ISSET(i, &rset)){
                    if (i == sf->listenfd) {
                   
                       printf("有新的客户端连接请求\n");
                       p = accept_t(sf->listenfd,&(sf->connectfd));
                       printf("the sf->connectfd :%d\n", *p);
                       printf("new connection client[%d] %s:%d\n", cnt,inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
                      
                       
                       FD_SET(sf->connectfd,&allset);
                       if (sf->connectfd > maxfd)
                       maxfd = sf->connectfd;
                       
                       
                      
                        } 
                         else{
                           p = recv_t(sockfd,sf->buf,MAXNITEMS,0,&nread);
                           if (*p > 0) {
                           printf("服务器端收到字节 :%d byte\n", *p);
                           send_t(sockfd,sf->buf,strlen(sf->buf),0);
                           putchar('\n');
                           }else{
                               printf("客户端断开\n");
                               break;
                           }
                          
                           

                        }



                    }
                       
                       */     
        
        
            
      }     
    }
      
    return 0;

}
    void listen_t(int fd)
    {
        if(listen(fd,BACKLOG)== -1)
        perror("listen error\n");   

       
    }

    int * accept_t(int fd,int *fd_dst)
    {
        addrlen =sizeof(client_addr);
        if((*fd_dst = accept(fd,(struct sockaddr*)&client_addr,&addrlen))<=0) 
            perror("accept");
        return fd_dst;

    }

    void ser_data(int fd,char buf[MAXNITEMS])
    {
        // deal to the client quit  fisrt and sigint
        int flags =   0;
        printf("等待接收消息......\n");
        int nread = 0;
        int * p =NULL;
        while((p = recv_t(fd,buf,MAXNITEMS,flags,&nread) )!=NULL){
            if (*p > 0) {
                printf("服务器端收到字节 :%d byte\n", *p);
                // /send to same data to client
                send_t(fd,buf,strlen(buf),0);
                putchar('\n');
                /* code */
            }else{
                printf("客户端断开\n");
                break;
            }
        }

    }


    int * recv_t(int fd, void *buf, size_t len, int flags,int *nread)
    {
        memset(buf,'\0',MAXNITEMS);
        *nread=recv(fd,buf,len,flags);
        if (*nread == -1){
            perror("nread");
            // exit(-1);
        }
        if(*nread >0)
            printf("服务器端收到消息:%s\n",(char *)buf);
        return nread;
    }


    void send_t(int fd, const void *buf, size_t len, int flags)
    {

        int ret = send(fd,buf,len,flags);
        if (ret == -1)
            perror("send");
        else
            printf("服务器端发送成功\n");

    }

    void sigint(int signo)
    {
        printf("the client ctrl +c to quit\n");
        exit(0);
    }