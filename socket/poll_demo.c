   
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
    #include <poll.h>

    #include <netdb.h>
    #define  PORT 1234    
    #define  BACKLOG 10 
    #define MAXNITEMS 1024
    typedef void *(* pfunc)(void *);

    struct  sockaddr_in server;    
    struct  sockaddr_in client;    
    socklen_t  addrlen;   

    void create_socket_and_bind(int fd);
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

        // struct hostent *gethostbyname(const char *name);

        struct serfd *sf = NULL;
        sf = realloc(sf,sizeof(struct serfd));
        struct serfd sfd = {

        .listenfd = 3,
        .connectfd =4,
        .buf[MAXNITEMS-50]=0,

        };
        sf = &sfd;

        create_socket_and_bind(sf->listenfd);
        listen_t(sf->listenfd); /* code */ 
        int *p =NULL;
        int nread = 0;
        int flag = 0;
        
        int cnt = 0;
        int sockfd = 0;

        struct pollfd client_fd[BACKLOG];
        client_fd[0].fd = sf->listenfd;
        client_fd[0].events = POLLIN;

        for (i = 1; i < BACKLOG; ++i) {
            client_fd[i].fd  = -1;
            /* code */
        }
        while(1) {
            int retval = poll(client_fd,cnt+1,2000);
            if (retval == 0) {
                printf("indicates that the call timed out 2s and no file descriptors were ready\n");
                continue;
            } else if (retval == -1){
                goto _err;
            } else if (retval > 0){
                
                    if (client_fd[0].revents&POLLIN) {
                           printf("有新的客户端连接请求\n");
                           p = accept_t(sf->listenfd,&(sf->connectfd));
                           printf("the sf->connectfd :%d\n", *p);
                           printf("\nconnection from cient's ip is%s,port is %d\n",inet_ntoa(client.sin_addr),htons(client.sin_port));
                           for (i = 1; i<BACKLOG ; ++i)
                            if (client_fd[i].fd<0) {
                                client_fd[i].fd = *p;
                                break;
                            }
                           client_fd[i].events =  POLLIN;
                           if (i>cnt)
                                cnt = i;
                          
                           printf("adding client on fd %d\n", *p);   
                           
                        }
                        

                        for (i = 1; i<=cnt ; ++i){
                            sockfd = client_fd[i].fd;
                            if (sockfd < 0)
                                continue;
                            if (client_fd[i].revents&(POLLIN)){
                                  printf("\n服务器端处理数据。。。。。。。。\n");
                                  p = recv_t(sockfd,sf->buf,MAXNITEMS,0,&nread);
                                  if (*p > 0 && p){
                                      printf("服务器端收到字节 :%d byte\n", *p);
                                      send_t(sockfd,sf->buf,strlen(sf->buf),0);
                                  } 
                                  else{
                                      printf("客户端断开\n");
                                      close(sockfd);
                                      break;
                                  }
                                
                            }
                            
                        }
                        
                        
                    }
                    
                   
                
            signal(SIGINT,sigint);
            sleep(1);
               

            }

       _err:
            switch(errno){
                case  EFAULT:
                printf("The array given as argument was not contained in the calling program's address space\n");
                case EINTR:
                printf("A signal was caught\n");
                break;
                case EINVAL:
                printf("nfds is negative or the value contained within timeout is invalid. \n");
                break;
                
                case ENOMEM:
                printf("unable to allocate memory for internal tables\n");
                break;
                default:
                printf("undef err\n");
                break;
            }

        return 0;

    }


    void create_socket_and_bind(int fd)
    {
       if((fd  = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
       perror("Creating  socket failed.");  
       exit(1);     
       } 
       
       int opt =SO_REUSEADDR;  
       setsockopt(fd,SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));  
       memset(&server,0,sizeof(server));  
       server.sin_family=AF_INET;  
       server.sin_port=htons(PORT);    
       server.sin_addr.s_addr= htonl (INADDR_ANY);   
       
       if(bind(fd, (struct sockaddr *)&server, sizeof(server)) ==   -1) {
       perror("Binderror.");   
       exit(1);     
       }

    }

    void listen_t(int fd)
    {
    if(listen(fd,BACKLOG)== -1) {    /*     calls   listen() */
    perror("listen error\n");   

    }
    }

    int * accept_t(int fd,int *fd_dst)
    {
    addrlen =sizeof(client);
    if((*fd_dst = accept(fd,(struct sockaddr*)&client,&addrlen))<=0) {
    perror("accept");

    }
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

    if (*nread == -1)
    perror("nread");
    else
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
