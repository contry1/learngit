// name_mqp.c
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <mqueue.h>
int main(int argc, char const *argv[])
{

    int c,flag;
    mqd_t mq;
    unsigned int val;
    struct mq_attr *atrr =NULL;
    flag = O_RDWR|O_CREAT;
    val = 0;

    printf("please input file name:\n");
    if (argc != 2) {
        printf("the usage...\n");
        exit(1);
        /* code */
    }
    mq = mq_open(argv[1],flag,0777,NULL);
    if (mq == (mqd_t) -1 )
        perror("open err");
    else
        printf("open name mq successfully\n");

    mq_close(mq);
    return 0;
}