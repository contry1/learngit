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
// #include <pthread.h>
#define  PORT 1234    
#define  BACKLOG 10 
#define MAXNITEMS 1024


struct  sockaddr_in server;    
struct  sockaddr_in client;    
socklen_t  addrlen;   
// void *query(void * arg);

int main() {
  // buf2= buf[0];
  int newfd,listenfd, ret,nread,ret3,retval1,i=0; 
  int connectfd;
  int val,num; 
  int retval=0;
  char buf[MAXNITEMS];
  char sendbuf[100]="welcome to my server\n";

  int flags =   0;
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

    addrlen =sizeof(client);
    if((connectfd = accept(listenfd,(struct sockaddr*)&client,&addrlen))<=0) {
      perror("accept");
      // continue;
    }
    printf("\nconnection from cient's ip is%s,port is %d\n",inet_ntoa(client.sin_addr),htons(client.sin_port));
    ret = send(connectfd,sendbuf,strlen(sendbuf),0);
    if (ret == -1)
      perror("send");
  while(1) {
    printf("waiting recv data......\n"); 
    memset(buf,'\0',MAXNITEMS);
    nread=recv(connectfd,buf,MAXNITEMS,flags);
    if (nread == -1)
      perror("nread");
    // setbuf(stdout,NULL);
    //write(STDOUT_FILENO,buf,nread);
    // fwrite(buf,nread,1,stdout);
    putchar('\n');
    // sleep(1);
    printf("the buf recv:%s\n",buf );
  }
  
    
  

  return 0;

}

