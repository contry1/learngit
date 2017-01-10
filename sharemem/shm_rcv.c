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
    int flag =  O_RDWR;
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
 int prot  = PROT_READ ; 
 int flags = MAP_SHARED;
 off_t offset;

 struct  shm_s * p =NULL;
 ftruncate(shm, length);
 p = mmap(NULL,length,prot,flags,shm,0);
 if (p == MAP_FAILED) {
    printf("the val is (void *) -1\n");
    perror("mmap");
     /* code */
 }else
    printf("mmap successfully\n");

  printf("%d\n",p->cont );
  // shm_unlink(argv[1]);
    return 0;
}