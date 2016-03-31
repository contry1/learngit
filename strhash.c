#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "../mqtt/mosq/src/uthash.h"

struct stu
{
    char *id;
	char name[10];
	UT_hash_handle hh;
}stus;

struct stu *usr = NULL;
//hash find
struct stu *find_stu (char *id)
{
	UT_hash_handle hh;
	struct stu*s;
	HASH_FIND(hh,usr, &id,sizeof(s->id), s );
	return s;
}
//hash add
void add_user(char* id, char *value_buf)
{
	UT_hash_handle hh;
    struct stu *s;
    HASH_FIND(hh,usr, &id, sizeof(s->id),s);  /* 插入前先查看key值是否已经在hash表g_users里面了 */
    if (s==NULL)
	{
      s = (struct stu*)malloc(sizeof(struct stu));
      s->id = id;
      HASH_ADD(hh,usr, id,sizeof(s->id), s );  /* 这里必须明确告诉插入函数，自己定义的hash结构体中键变量的名字 */
    }
    strcpy(s-> name, value_buf);
}
//test demo
int main()
{
	UT_hash_handle hh;
	struct stu* ret=NULL;
	struct stu* tmp,*s;
	//count the item of hashtable
	unsigned int num = 0;
	num = HASH_COUNT(usr);
	printf("there is %u items\n",num);

	ret = find_stu("dfg");
	if(ret)
	{
		printf("dfg is exist\n");
	}
	else
		printf("there is no id = dfg \n");


	add_user("gg", "line");
	ret = find_stu("gg");
	if(!ret)
	{
		printf("there is no id = gg\n");
	}
	else
		printf("there is exist id= %s\t",ret->id);
		printf("the name is %s\n",ret->name);

	num = HASH_COUNT(usr);
	printf("the num is %u\n",num);

	HASH_ITER(hh,usr,s,tmp)
	{
		printf("id is %s:name %s\n",s->id,s->name);
	}
	return 0;
}
#if 0
int stu_add(int id)
{
	HASH_ADD(hh,usr,id,sizeof(stus->id),stus);
	return 0;
}
int main()
{
	struct stu *out = null;
	stu_add(4);
	HASH_FIND(hh,usr,&(usr->id),sizeof(stus->id),out);
	if(!out)
	{
		printf("dsf\n");
	}
	else
	{
		printf("fmind it\n");
	}
	return 0;
}



struct mosquitto_msg_store_load{
	UT_hash_handle hh;
	dbid_t db_id;
	struct mosquitto_msg_store *store;
};
typedef uint64_t dbid_t;

dbid_t i64temp;
store_id = i64temp;
uint64_t store_id;
struct mosquitto_msg_store_load *load;
struct mosquitto_db{
	...
	struct mosquitto_msg_store_load *msg_store_load;
	...

};

HASH_FIND(hh, db->msg_store_load, &store_id, sizeof(dbid_t), load);//store_id=db_id
#endif
