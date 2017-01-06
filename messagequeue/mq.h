// name_mqp.c
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <mqueue.h>
static void mq_close_t(mqd_t mq);

static void mq_unlink_t(const char * name);
static void mq_getattr_t(mqd_t mqdes, struct mq_attr *attr);
static int mq_setattr_t(mqd_t mqdes, const struct mq_attr *newattr,\
                        struct mq_attr *oldattr);
int mq_send_t(mqd_t mqdes, const char *msg_ptr, size_t msg_len, unsigned int msg_prio);
ssize_t mq_receive_t(mqd_t mqdes, char *msg_ptr, size_t msg_len, unsigned int *msg_prio);




static void mq_close_t(mqd_t mq)
{
    int ret;
    ret = mq_close(mq);
    if (ret == -1)
        perror("close");
    else
        printf("successfully close\n");
    
}
static void mq_unlink_t(const char * name)
{
    int ret;
    ret = mq_unlink(name);
    if (ret == -1)
        perror("unlink");
    else
        printf("successfully unlink from kernel\n");
    
}

static void mq_getattr_t(mqd_t mqdes, struct mq_attr *attr)
{
    int ret = 0;
    if (attr == NULL) {
        printf("the mq attr is null\n");
        exit(-1);
        /* code */
    }
    ret = mq_getattr(mqdes, attr);
    if (ret == 0) {
        printf("successfully get attr of mq\n");
        printf("max messages:%ld || max size:%ld || current messages no:%ld\n",\
            attr->mq_maxmsg,attr->mq_msgsize,attr->mq_curmsgs);
        /* code */
    }else
        perror("getattr");



}

static int mq_setattr_t(mqd_t mqdes, const struct mq_attr *newattr,struct mq_attr *oldattr)
{
    int ret = 0;
    ret = mq_setattr(mqdes, newattr,oldattr);
    if (ret == 0) {
        printf("successfully set attr of mq\n");
        /* code */
    }else
        perror("setattr");

}


int mq_send_t(mqd_t mqdes, const char *msg_ptr, size_t msg_len, unsigned int msg_prio)
{
    int ret = 0;
    ret = mq_send(mqdes,msg_ptr,msg_len,msg_prio);
    if (ret  == 0) {
        printf("successfully send msg:%s\n",msg_ptr);
        /* code */
    }else
        perror("mq_send");
    return 0;
}

ssize_t mq_receive_t(mqd_t mqdes, char *msg_ptr, size_t msg_len, unsigned int *msg_prio)
{
    int ret = 0;
    ret = mq_receive(mqdes,msg_ptr,msg_len,msg_prio);
        if (ret  >=0) {
            printf("successfully mq_receive msg:%s\n",msg_ptr);
            /* code */
        }else
            perror("mq_receive");
            fprintf(stderr,"errno\n");
            printf("the errno:%s\n",strerror(errno));

            if (errno ==  EMSGSIZE) {
                printf("the  msg_len was less than the mq_msgsize attribute of the message queue\n");
                /* code */
            }
    return 0;

}
