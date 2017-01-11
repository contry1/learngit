          /* For O_* constants */
#include "shm.h"
#include <sys/types.h>
#include <sys/wait.h>
int main(int argc, char const *argv[])
{
    int shm;
   
 struct  shm_s * p =NULL;

 // init the struct 
 p = (struct  shm_s *)malloc(sizeof(struct shm_s));
 if (p ==NULL) {
    perror("malloc");
     /* code */
 }

 

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