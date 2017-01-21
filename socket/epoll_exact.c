   
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
    #include <sys/epoll.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <netdb.h>
    #define  PORT 1234    
    #define  BACKLOG 10 
    #define MAXNITEMS 1024
    #define MAX_EVENTS 10
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
    static int  setnonblocking(int fd);
    void epoll_ctl_t(int fd,int epollfd,struct epoll_event ev);

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

        

        struct epoll_event ev, events[MAX_EVENTS];
        int nfds, epollfd;


        epollfd = epoll_create(10);
        // epollfd = epoll_create1(0);
        if (epollfd == -1) {
            perror("epoll_create");
            exit(EXIT_FAILURE);
        }

        epoll_ctl_t(sf->listenfd,epollfd,ev);

       
        while(1) {
            int nfds = epoll_wait(epollfd, events, MAX_EVENTS, -1);
                if (nfds == -1) {
                    perror("epoll_pwait");
                    exit(EXIT_FAILURE);
                }


                for (i= 0; i < nfds; ++i) {
                    if (events[i].data.fd == sf->listenfd) {
                        p = accept_t(sf->listenfd,&(sf->connectfd));
                       printf("the sf->connectfd :%d\n", *p);
                       printf("\nconnection from cient's ip is%s,port is %d\n",inet_ntoa(client.sin_addr),htons(client.sin_port));
                       
                        ret = setnonblocking(*p);
                        if (ret == -1) {
                            perror("set no block");
                            continue;
                            /* code */
                        }
                        
                        epoll_ctl_t(*p,epollfd,ev);

                      
                    }else if(events[i].events&EPOLLIN ){
                        // do_use_fd(events[n].data.fd);
                          sockfd = events[i].data.fd;

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
          
                
            signal(SIGINT,sigint);
            sleep(1);
               

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

static int setnonblocking(int fd)
{
    int flag = fcntl(fd,F_GETFL,0);
    if (flag == -1) {
        printf("fcntl getfl err\n");
        return -1;
        /* code */
    }
    flag |= O_NONBLOCK;
    flag = fcntl(fd,F_SETFL,flag);
    if (flag == -1) {
        printf("fcntl setfl err\n");
        return -1;
        /* code */
    }

    return 0;
}


void epoll_ctl_t(int fd,int epollfd,struct epoll_event ev)
{
    ev.events = EPOLLIN| EPOLLET;
    ev.data.fd = fd;
    if (epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &ev) == -1) {
        perror("epoll_ctl: fd");
        exit(EXIT_FAILURE);
    }
}