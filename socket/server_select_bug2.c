/*
* =====================================================================================
*
*       Filename:  server.c
*
*    Description: THE demo is bug,that is can create the many client  to connnect the server,but the server only communicat with client once. 
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
 #include <sys/select.h>
#include <errno.h>

#include <netdb.h>
#define  PORT 1234    
#define  BACKLOG 10 
#define MAXNITEMS 1024
typedef void *(* pfunc)(void *);

struct  sockaddr_in server;    
struct  sockaddr_in client;    
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
 
  // struct hostent *gethostbyname(const char *name);
  
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
 
 fd_set rset,allset;
 FD_ZERO(&allset);
    while(1) {
       
         FD_SET(sf->listenfd,&allset);
         int maxfd = sf->connectfd > sf->listenfd ? sf->connectfd :sf->listenfd;
         int retval =  select(maxfd+1,&allset,NULL,NULL,NULL);
         if (retval == -1){
            switch(errno){
                case EBADF:
                    printf("An invalid file descriptor was given in one of the sets.  (Perhaps a file descriptor that was already closed, or one on which an error has occurred.)\n");
                    break;
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
        }
        else if (retval){
                /* code */
                retval = FD_ISSET(sf->listenfd, &allset); // printf("FD_ISSET sf->listenfd retval:%d\n",retval);
                if (retval ==1) { // listenfd is exist ,the retval == 1
                    printf("有新的客户端连接请求\n");
                    p = accept_t(sf->listenfd,&(sf->connectfd));
                    printf("the sf->listenfd :%d\n", *p);
                    printf("\nconnection from cient's ip is%s,port is %d\n",inet_ntoa(client.sin_addr),htons(client.sin_port));
                    // add the connectfd
                    if (*p >0&&p) {
                        FD_SET(sf->connectfd,&allset);
                        printf("adding client on fd %d\n", sf->connectfd);   
                        /* code */
                    }
                }


                // deal to the connectfd ,that is client data
                ret = FD_ISSET(sf->connectfd, &allset); // printf("FD_ISSET sf->connectfd retval:%d\n",ret);
                if(ret ==1) {
                    printf("the sf->connectfd:%d\n", *p);
                    printf("\n服务器端处理数据。。。。。。。。\n");
                    p = recv_t(sf->connectfd,sf->buf,MAXNITEMS,0,&nread);
                    if (*p > 0 && p) 
                        printf("服务器端收到字节 :%d byte\n", *p);
                        // send_t(sf->connectfd,sf->buf,strlen(sf->buf),0); 
                    else{
                        printf("客户端断开\n");
                        break;
                    }
                }else if (ret == 0) {
                    FD_CLR(sf->connectfd, &allset);
                    close(sf->connectfd);
                    printf("客户端断开\n");
                    /* code */
                } 
           


        }
        signal(SIGINT,sigint);
        sleep(1);
  
  }
  
  return 0;

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
