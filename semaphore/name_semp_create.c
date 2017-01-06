
#include "name_semp.h"

int main(int argc, char const *argv[])
{

    int c,flag;
    sem_t *sem =NULL;
    unsigned int val;
    flag = O_RDWR|O_CREAT;
    val = 0;

    printf("please input file name:");
    if (argc != 2) {
        printf("the usage...\n");
        exit(1);
        /* code */
    }
    sem = sem_creat_t(argv[1],flag,0777,val);
    sem_close(sem);
    return 0;
}