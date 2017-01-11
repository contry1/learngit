          /* For O_* constants */
#include "shm.h"
#include <sys/types.h>
#include <sys/wait.h>
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
 int flags = MAP_PRIVATE;
 off_t offset = 0;

 struct  shm_s * p =NULL;

 // init the struct 
 p = (struct  shm_s *)malloc(sizeof(struct shm_s));
 if (p ==NULL) {
    perror("malloc");
     /* code */
 }
// /the ftruncate is important ,no it ,and we must happen the sigbus signal
 int ret = ftruncate(shm, length);
 if (ret == -1)
    perror("ftruncate");
 

 p = mmap(NULL,length,prot,flags,shm,offset);
 if (p == MAP_FAILED) {
    printf("the val is (void *) -1\n");
    perror("mmap");
     /* code */
 }else
    printf("mmap successfully,the p address %p\n",p);


  // make fork
  p->cont = 0;
  pid_t pid;
  pid = fork();
  if (pid < 0)
    perror("fork");
  else if(pid == 0){
    for (int i = 0; i < 10; ++i) {
        printf("the child .......\n");
        p->cont++;
        strcpy(p->buf,"hello child");
        printf("the cont %d,the string %s\n",p->cont,p->buf );
        sleep(1);
        /* code */
    }

  }
  
  for (int i = 0; i < 10; ++i) {

      printf("the father .......\n"); 
      p->cont++;
      strcpy(p->buf,"hello father");
      printf("the cont %d,the string %s\n",p->cont,p->buf );
      // sleep(1);


  }
  waitpid(pid,NULL,0);
  return 0;
}