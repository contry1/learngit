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
*         Author:  YOUR NAME (), 
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
void accept_t(int fd,int *fd_dst);

void ser_data(int fd,char buf[]);
void recv_t(int fd, void *buf, size_t len, int flags,int *nread);
void send_t(int fd, const void *buf, size_t len, int flags);

void sigint(int signo);

int main() {
  // buf2= buf[0];
  int newfd,listenfd, ret,ret3,retval1,i=0; 
  int connectfd;
  int val,num; 
  int retval=0;
  char buf[MAXNITEMS];
  char sendbuf[100]="welcome to my server\n";

  pthread_t thread_id;

  if((listenfd  = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    perror("Creating  socket failed.");  
    exit(1);     
  } 

  int opt =SO_REUSEADDR;  
  setsockopt(listenfd,SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));  
  memset(&server,0,sizeof(server));  
  server.sin_family=AF_INET;  
  server.sin_port=htons(PORT);    
  server.sin_addr.s_addr= htonl (INADDR_ANY);    
  if(bind(listenfd, (struct sockaddr *)&server, sizeof(server)) ==   -1) {
    perror("Binderror.");   
    exit(1);     
  }  

  if(listen(listenfd,BACKLOG)== -1) {    /*     calls   listen() */
    perror("listen error\n");   
    exit(1);
  }  

    accept_t(listenfd,&connectfd);

    printf("\nconnection from cient's ip is%s,port is %d\n",inet_ntoa(client.sin_addr),htons(client.sin_port));
    ret = send(connectfd,sendbuf,strlen(sendbuf),0);
    if (ret == -1)
    perror("send");
    while(1) {

       signal(SIGINT,sigint);
       ser_data(connectfd,buf);
    }
  

  return 0;

}

void accept_t(int fd,int *fd_dst)
{
    addrlen =sizeof(client);
    if((*fd_dst = accept(fd,(struct sockaddr*)&client,&addrlen))<=0) {
      perror("accept");
      
    }

}

void ser_data(int fd,char buf[MAXNITEMS])
{
    // deal to the client quit  fisrt and sigint
       int flags =   0;
       printf("waiting recv data......\n"); 
       
       int nread = 0;
       recv_t(fd,buf,MAXNITEMS,flags,&nread);

       // set the stout buffer
       setbuf(stdout,NULL);//there is a bug .that is the client 1th is not write to stdout
       size_t re = fwrite(buf,nread,1,stdout);
       if (re == 0) 
           perror("fwrite");
       /* code */
       else{
           putchar('\n');
           // /send to same data to client
           send_t(fd,buf,strlen(buf),0);
           
   
        }
    
}


void recv_t(int fd, void *buf, size_t len, int flags,int *nread)
{
    memset(buf,'\0',MAXNITEMS);
    *nread=recv(fd,buf,len,flags);
    if (*nread == -1)
        perror("nread");
    else
        printf("the server recv:%s\n",(char *)buf);
}


void send_t(int fd, const void *buf, size_t len, int flags)
{
    // int sockfd, const void *buf, size_t len, int flags
   int ret = send(fd,buf,len,flags);
   if (ret == -1)
    perror("send");
   else
    printf("send success\n");

}
void sigint(int signo)
{
    printf("the client ctrl +c to quit\n");
    exit(0);
}
