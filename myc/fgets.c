// fget.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// /the next is select func_pipe
#include <unistd.h>
#include <sys/select.h>

#define MAXNITEMS 400
char buf[MAXNITEMS];
static char * input(char *nread);
static void print(char *nread);
static void select_t(void);
static void select_read(void);
static void select_write_read(void);
 int main(int argc, char const *argv[])
{
	char * nread =NULL;
	char * p =NULL;
	memset(buf,('\0'),MAXNITEMS);

	int len ;
	// int i =0;
	len = strlen(buf);
	printf("len 1 is:%d\n",len );
	p = input(nread);
	print(p);


	// select_t();

 	select_read();
	select_write_read();

	return 0;
}
static char * input(char *nread)
{
	int len2;
	int count= 0;
	while((nread = fgets(buf,sizeof(buf),stdin))){
		printf("%s\n",buf );
		len2 = strlen(buf);
		printf("%d\n",len2 );
		printf("the count:%d\n",++count);

		// to deal with the '\n
		if (nread[len2-1]=='\n') {
			printf("we rm the \\n.\n");
			nread[len2-1] = '\0';
			/* code */
		}
		// count++;
		if (count>4) {
			break;
			/* code */
		}
	}
	return nread;

}
static void print(char nread[])
{
	int i =0;
	if (nread ==NULL) {
		printf("THE ERR\n");
		return;
		/* code */
	}else{
		// printf("nrrrrrr:%c\n",nread[0] );
		// printf("n/rrrrrr1:%c\n",(nread[1]) );
		// printf("nrrrrrr:2%c\n",nread[2] );
		// printf("nrrrrrr:3%c\n",nread[3] );
		// printf("nrrrrrr:4%c\n",nread[4] );
		// printf("nrrrrrr:5%c\n",nread[5] );
		while((nread[i]) != '\0'){
			printf("%c\t",nread[i] );
			i++;
		}
		
	}
	printf("\n");

}

// /the next is simple the select exp
// the exp have a small bug ,that is not init the value of fd and some param
static void select_t(void)
{
	int fd;
	
	fd_set allfd;
	fd_set readfd;
	FD_ZERO(&allfd);
	FD_SET(fd,&readfd);



	// printf
	int ret = select(fd+1,&readfd,NULL,NULL,NULL);
	if (ret == -1) {
		perror("select");
		/* code */
	}
	int res = FD_ISSET(fd,&readfd);
	if (res) {
		printf("now is readable\n");
		/* code */
	}else
		printf("the fd is no use now\n");



}

static void select_read(void)
{
	int fd = 0;
	int  fd_ret;
	fd_set allfd;
	fd_set readfd;

	
	int nread;

	FD_ZERO(&allfd);
	fd_ret = dup2(fd,0);
	if (fd_ret== -1) {
		perror("dup2");
		/* code */
	}
	printf("fd_ret:%d\n",fd_ret );
	
	FD_SET(fd,&readfd);

	int ret = select(fd+1,&readfd,NULL,NULL,NULL);
	if (ret == -1) {
		perror("select");
		/* code */
	}
	int res = FD_ISSET(fd,&readfd);
	if (res) {
		printf("now is readable\n");
		/* code */
		nread = read(fd,buf,sizeof(buf));
		if (nread == -1) {
			perror("read");
			/* code */
		}else{
			printf("read:%s\n",buf );
		 	write(STDOUT_FILENO,buf,nread);
		}
	}else
		printf("the fd is no use now\n");

		

}

// /the next is select for write exp
// 
static void select_write_read(void)
{
	int fd = 0;
	int  fd_ret;
	fd_set allfd;
	fd_set readfd;
	fd_set writefd;
	int nread;
	int nwrite;

	FD_ZERO(&allfd);
	fd_ret = dup2(fd,0);
	if (fd_ret== -1) {
		perror("dup2");
		/* code */
	}
	printf("fd_ret:%d\n",fd_ret );
	
	FD_SET(fd,&readfd);
	FD_SET(fd,&writefd);


	int ret = select(fd+1,&readfd,&writefd,NULL,NULL);
	if (ret == -1) {
		perror("select");
		/* code */
	}
	int res = FD_ISSET(fd,&readfd);
	if (res) {
		printf("now is readable\n");
		/* code */
		nread = read(fd,buf,sizeof(buf));
		if (nread == -1) {
			perror("read");
			/* code */
		}else{
			printf("read:%s\n",buf );
		 	write(STDOUT_FILENO,buf,nread);
		}
	}else
		printf("the fd is no use read now\n");

	// /the next is writefd to pending ,and exec it is or not ready?
	res = 0;
	res = FD_ISSET(fd,&writefd);
	if (res) {
		printf("now is writeable\n");
		/* code */
		nwrite = write(fd,buf,strlen(buf));
		if (nwrite == -1) {
			perror("nwrite");
			/* code */
		}else{
			printf("write:%s\n",buf );
		 	
		}
	}else
		printf("the fd is no use write now\n");

		

}

