// name_semp.c
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <semaphore.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
static sem_t * sem_creat_t(const char * name,int flag,mode_t mode,unsigned int value);
static sem_t * sem_open_t(const char * name,int flag);

static void sem_wait_t(sem_t *sem);
static void sem_post_t(sem_t *sem);
static void sem_getvalue_t(sem_t *sem,unsigned int * val);
static void sem_unlink_t(const char * name);




static sem_t * sem_creat_t(const char * name,int flag,mode_t mode,unsigned int value)
{
   sem_t *sem =NULL;
   sem = sem_open(name,flag,mode,value);
   if (sem == SEM_FAILED )
        perror("open create err");
   
   else
        printf("open  create name sem successfully\n");

    return sem;
}

static sem_t * sem_open_t(const char * name,int flag)
{
       sem_t *sem =NULL;
       sem = sem_open(name,flag);
       if (sem == SEM_FAILED )
            perror("open err");
       else
            printf("open name sem successfully\n");

        return sem;
}


static void sem_wait_t(sem_t *sem)
{
    int ret = 0;
    ret = sem_wait(sem);
    if (ret == 0) {/* code */
        printf("wait suceess.....\n");
    }else
        perror("wait");

}


static void sem_post_t(sem_t *sem)
{
    int ret = 0;
    ret = sem_post(sem);
    if (ret == 0) {/* code */
        printf("post suceess.....\n");
    }else
        perror("post");

}

static void sem_getvalue_t(sem_t *sem,unsigned int * val)
{
    int ret = 0;
    if (sem == NULL) {
        printf("name semp is null");
        exit(-1);
        /* code */
    }
    ret = sem_getvalue(sem,val);
        if (ret == 0){
            printf("get the name_sem  val:%d\n",*val );
    }else
        perror("sem_getvalue");
     /* code */ 
}


static void sem_unlink_t(const char * name)
{
    int ret = 0;
    ret = sem_unlink(name);
        if (ret == 0){
            printf("we drop the name semaphore from the kernel\n");
            printf(" ret :%d\n",ret);
    }else
        perror("unlink");
     /* code */ 

}
