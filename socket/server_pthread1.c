/*
* =====================================================================================
*
*       Filename:  server.c
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
#include <pthread.h>
#define  PORT 1234    
#define  BACKLOG 10 
#define MAXNITEMS 1024
typedef void *(* pfunc)(void *);

struct  sockaddr_in server;    
struct  sockaddr_in client;    
socklen_t  addrlen;   
// void *query(void * arg);
void listen_t(int fd);

int * accept_t(int fd,int *fd_dst);
// void create_thread(pthread_t pid,void *arg);
void create_thread(pthread_t *pid,void *arg,pfunc pf);
void wait_pthread(pthread_t pid ,int err);

void * main_func(void *arg);
void * do_ser_func(void *arg);

void * acpt_func(void *arg);

void ser_data(int fd,char buf[]);
void recv_t(int fd, void *buf, size_t len, int flags,int *nread);
void send_t(int fd, const void *buf, size_t len, int flags);

void sigint(int signo);
struct serfd {
  int listenfd;
  int connectfd;
  char buf[MAXNITEMS];

};

int main() {

  int i = 0;
  int ret = 0;
  pthread_t thread_id[10];
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
  // listen_t(sf->listenfd);
 
  // accept_t(sf->listenfd,&(sf->connectfd)); 
    listen_t(sf->listenfd); /* code */ 
  while(1) {
    // create_thread(&thread_id[i++],(void *)sf,main_func);
    int *p =NULL;
    p =   accept_t(sf->listenfd,&(sf->connectfd));
    if(*p >0) {
        printf("有新的客户端连接请求\n");
        printf("the sfd connectfd:%d\n", *p);
        printf("\nconnection from cient's ip is%s,port is %d\n",inet_ntoa(client.sin_addr),htons(client.sin_port));
        create_thread(&thread_id[i++],(void *)sf,do_ser_func);
        /* code */
        signal(SIGINT,sigint);
        sleep(1);
    }

  }
  int err =0;
  wait_pthread(thread_id[i],err);
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

void wait_pthread(pthread_t pid,int err )
{
  int errno = pthread_join(pid,(void *)&err);
  if (!errno) {
  
  printf("wait success thread :%ld\n",pthread_self());
  }else
  perror("err");


}

void * main_func(void *arg)
{

  struct serfd *sfd =NULL;
  sfd  = (struct serfd *)(arg);
  printf("server listenfd:%d server connectfd:%d\n",sfd->listenfd,sfd->connectfd );

  listen_t(sfd->listenfd);
  pthread_exit((void *)0);
}

void * do_ser_func(void *arg)
{

  struct serfd *sfd =NULL;
  sfd  = (struct serfd *)(arg);
  printf("server listenfd:%d server connectfd:%d\n",sfd->listenfd,sfd->connectfd );
  ser_data(sfd->connectfd,sfd->buf);

  pthread_exit((void *)0);
}


void * acpt_func(void *arg)
{

  struct serfd *sfd =NULL;
  sfd  = (struct serfd *)(arg);
  printf("server listenfd:%d server connectfd:%d\n",sfd->listenfd,sfd->connectfd );
  accept_t(sfd->listenfd,&(sfd->connectfd));
  pthread_exit((void *)0);
}

void ser_data(int fd,char buf[MAXNITEMS])
{
  // deal to the client quit  fisrt and sigint
  int flags =   0;
  printf("waiting recv data......\n");
  int nread = 0;
  int * p =NULL;
  recv_t(fd,buf,MAXNITEMS,flags,&nread);
  putchar('\n');
  // /send to same data to client
  send_t(fd,buf,strlen(buf),0);
  

}


void recv_t(int fd, void *buf, size_t len, int flags,int *nread)
{
  memset(buf,'\0',MAXNITEMS);
  *nread=recv(fd,buf,len,flags);

  if (*nread == -1)
    perror("nread");
  else
    printf("服务器端收到消息:%s\n",(char *)buf);
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
