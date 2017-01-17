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
#include <pthread.h>
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

void create_thread(pthread_t *pid,void *arg,pfunc pf);


void * do_ser_func(void *arg);


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
  pthread_t thread_id[10];
 
  // struct hostent *gethostbyname(const char *name);
  
  struct serfd *sf = NULL;
  sf = realloc(sf,sizeof(struct serfd));
  struct serfd sfd = {

     .listenfd = 3,
     .connectfd =4,
     .buf[MAXNITEMS-50]=0,

  };
  sf = &sfd;

 // /init the lock
  if ((ret = pthread_mutex_init(&sf->lock,NULL))== -1)
      perror("init lock");

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
    while(1) {
       
        p = accept_t(sf->listenfd,&(sf->connectfd));
        

        printf("有新的客户端连接请求\n");
        printf("the sfd connectfd:%d\n", *p);
        printf("\nconnection from cient's ip is%s,port is %d\n",inet_ntoa(client.sin_addr),htons(client.sin_port));
        pthread_mutex_trylock(&sf->lock);
        create_thread(&thread_id[i++],(void *)sf,do_ser_func);
        pthread_mutex_unlock(&sf->lock); 
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

void create_thread(pthread_t *pid,void *arg,pfunc pf)
{
 
  int err = pthread_create(pid,NULL,pf,arg);
  if (err!=0) {
    perror("not create thread1");        /* code */
  }else{
    printf("new thread :%ld\n",pthread_self());/*there is new thread,not main thread*/
  }

}

void * do_ser_func(void *arg)
{

  pthread_detach(pthread_self());
  struct serfd *sfd =NULL;
  sfd  = (struct serfd *)(arg);
  // pthread_mutex_lock(&sfd->lock);
  printf("server listenfd:%d server connectfd:%d\n",sfd->listenfd,sfd->connectfd );
  ser_data(sfd->connectfd,sfd->buf);
  // pthread_mutex_unlock(&sfd->lock);
  
  close(sfd->connectfd);
  pthread_exit((void *)0);
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
