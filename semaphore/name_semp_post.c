
#include "name_semp.h"

int main(int argc, char const *argv[])
{

    int c,flag;
    sem_t *sem =NULL;
    unsigned int val;
    flag = O_RDWR;
    // val = 0;

    printf("please input file name:");
    if (argc != 2) {
        printf("the usage...\n");
        exit(1);
        /* code */
    }
    
    sem = sem_open_t(argv[1],flag);
    sem_getvalue_t(sem,&val);
    sem_post_t(sem);
    sem_getvalue_t(sem,&val);
    return 0;
}