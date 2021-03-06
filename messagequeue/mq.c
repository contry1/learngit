// name_mqp.c

#include "mq.h"
/*the attr must locate here,because we must init it,if we loacte it in main,it will indicate  we not init
*/
struct mq_attr attr;
int main(int argc, char const *argv[])
{

    int c,flag;
    mqd_t mq;
    unsigned int val;

    flag = O_RDWR|O_CREAT;
    val = 0;

    attr.mq_flags = 0;  
    attr.mq_maxmsg = 10;  
    attr.mq_msgsize = 33;  
    attr.mq_curmsgs = 0;  

    printf("please input file name:\n");
    if (argc != 2) {
        printf("the usage...\n");
        exit(1);
        /* code */
    }
    mq = mq_open(argv[1],flag,0777,&attr);
    if (mq == (mqd_t) -1 )
        perror("open err");
    else
        printf("open name mq successfully\n");


    
    mq_getattr_t(mq,&attr);
    mq_close_t(mq);
    return 0;
}