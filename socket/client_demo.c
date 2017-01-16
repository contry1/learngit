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
// #include <pthread.h>
#define  PORT 1234    
#define  BACKLOG 10 
#define MAXNITEMS 1024

struct  sockaddr_in server;    
struct  sockaddr_in client;    
socklen_t  addrlen;   
// void *query(void * arg);
void cli_data(int fd,char buf[MAXNITEMS]);
void send_t(int fd, const void *buf, size_t len, int flags);
void recv_t(int fd, void *buf, size_t len, int flags);


int main() {
  // buf2= buf[0];
  int newfd,sockfd, ret,i=0; 
  int connectfd;
  int val,num; 
  char buf[MAXNITEMS]={0};
  char sendbuf[MAXNITEMS];
  pthread_t thread_id;

  if((sockfd  = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    perror("Creating  socket failed.");  
    exit(1);     
  } 

  int opt =SO_REUSEADDR;  
  setsockopt(sockfd,SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));  
  memset(&server,0,sizeof(server));  
  server.sin_family=AF_INET;  
  server.sin_port=htons(PORT);    
  server.sin_addr.s_addr= htonl (INADDR_ANY);
  if (connect(sockfd,(struct sockaddr *) &server, sizeof(server)) < 0) {
    printf("Failed to connect with server\n");
  }else
    printf("the client connect...\n");

    ret=recv(sockfd,buf,sizeof(buf),0);
    if (ret >0)
        printf("the client recv:%s\n",buf );

   
    while(1) {
        cli_data(sockfd, buf);

        
    }
    return 0;
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
    printf("the input data len:%d\n",len );
    // /delete the \n
    if (p[--len] == '\n') {
        p[len] = '\0';
        /* code */
    }
   
    send_t(fd,buf,len,flags);
    // recev the data from server
    recv_t(fd,buf,MAXNITEMS,flags);
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

void recv_t(int fd, void *buf, size_t len, int flags)
{
    memset(buf,'\0',MAXNITEMS);
    int nread=recv(fd,buf,len,flags);
    if (nread == -1)
        perror("nread");
    else
        printf("the client recv:%s\n",(char *)buf);
}