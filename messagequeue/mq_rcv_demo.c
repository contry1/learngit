
#include "mq.h"
/*the attr must locate here,because we must init it,if we loacte it in main,it will indicate  we not init
*/
// extern  MAXNITEMS  
struct mq_attr attr;
int main(int argc, char const *argv[])
{

    int c,flag;
    mqd_t mq;
    unsigned int val;

    flag = O_RDONLY;
    val = 0;

    printf("please input file name:\n");
    if (argc != 2) {
        printf("the usage...\n");
        exit(1);
        /* code */
    }
    mq = mq_open(argv[1],flag);
    if (mq == (mqd_t) -1 )
        perror("open err");
    else
        printf("open name mq successfully\n");


    
    char buf[MAXNITEMS];
    while(strlen(buf) < MAXNITEMS){

        memset(buf,'\0',MAXNITEMS);
        mq_receive_t(mq,buf,MAXNITEMS,&val);
        printf("the recv buf:%s || the proir :%d\n",buf,val );
    }
   

    // mq_close_t(mq);
    return 0;
}