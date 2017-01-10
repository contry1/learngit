#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <fcntl.h>           /* For O_* constants */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

struct shm_s{
    int cont;
    char buf[100];
};
int main(int argc, char const *argv[])
{
    int shm;
    int flag =  O_RDWR|O_CREAT;
    mode_t mode = 0777;
    printf("please input file name:\n");
   if (argc != 2) {
       printf("the usage...\n");
       exit(1);
       /* code */
   }

  shm = shm_open(argv[1],flag,mode);
  if (shm ==  -1 )
        perror("open err");
  else
        printf("open name shm successfully\n");


 
 size_t length = sizeof(struct shm_s);
 int prot  = PROT_READ |PROT_WRITE; 
 int flags = MAP_SHARED;
 off_t offset = 0;

 struct  shm_s * p =NULL;

 // init the struct 
 p = (struct  shm_s *)malloc(sizeof(struct shm_s));
 if (p ==NULL) {
    perror("malloc");
     /* code */
 }

 ftruncate(shm, length);


 p = mmap(NULL,length,prot,flags,shm,offset);
 if (p == MAP_FAILED) {
    printf("the val is (void *) -1\n");
    perror("mmap");
     /* code */
 }else
    printf("mmap successfully,the p address %p\n",p);

  printf("the cont %d,the string %s\n",p->cont,p->buf );
  strcpy(p->buf,"hello");
  printf("the cont %d,the string %s\n",p->cont,p->buf );

  // free(p);
    return 0;
}