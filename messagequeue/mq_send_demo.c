
#include "mq.h"
/*the attr must locate here,because we must init it,if we loacte it in main,it will indicate  we not init
*/
struct mq_attr attr;

int main(int argc, char const *argv[])
{

    int c,flag;
    mqd_t mq;
    unsigned int val;
    char buf[MAXNITEMS];

    flag = O_WRONLY;
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


    
    // input from   stddin
    char * p =NULL;
   
    
    // delet  the \n
    while( (p =fgets(buf,sizeof(buf),stdin))){

       int len = strlen(buf);
       if (p[--len] == '\n') {
         printf("the \\n is buffer\n");
         p[len] = '\0';
          /* code */
       }
        mq_send_t(mq,buf,len,10);

    }
    // mq_close_t(mq);
    return 0;
}