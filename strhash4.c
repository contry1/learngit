/*2016/3/30 15:41:21*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../mqtt/mosq/src/uthash.h"

struct stu{
	char * clientid;
	char *topic;
	UT_hash_handle hh;

}stus;

struct stu * usr;

struct stu * find(char * clientid)
{
	struct stu* s;
	HASH_FIND(hh,usr,&clientid,sizeof(clientid),s);
	if(s)
		{
			return s;

		}



}

void add(char * clientid,char *topic)
{
	struct stu* s;
	HASH_FIND(hh,usr,&clientid,sizeof(clientid),s);
	if(NULL==s)
		{
			s = (struct stu*)malloc(sizeof(struct stu));
			if(s)
				{
					
					//s->clientid = clientid;//the assignment is likely to happen Segmentation faults,so it need to fix
					s->clientid = (char *)malloc(sizeof(6));
					if(s->clientid)
						{
							s->clientid = clientid;
						}
					HASH_ADD(hh,usr,clientid,sizeof(clientid),s);
					s->topic = (char *)malloc(sizeof(10));
					if(s->topic)
						{
							strcpy(s->topic, topic);
						}
					
				}



		}




}


void delete(char * clientid)
{
	struct stu * s = NULL;
	HASH_FIND(hh,usr,&clientid,sizeof(s->clientid),s);
	if(s)
	{
		HASH_DEL(usr,s);
		free(s);
	}
}
int main()
{
	UT_hash_handle hh;
	struct stu* s;
	struct stu* out,*tmp;
	char * clientid[5] = {"wo","ac","go"};
	char * topic[5] = {"lei","sun","dun"};
	int i = 0 ;

	for(i=0;i<3;i++)
	{
		add(clientid[i],topic[i]);
	}

	s = find("wo");
	if(s)
	{

		printf("the topic is %s\n",s->topic);
	}

	HASH_ITER(hh,usr,out,tmp)
		{
			printf("the id is %s and the topic is %s\n",out->clientid,out->topic);
		}

	printf("**********************************************\n");
	delete("wo");

	HASH_ITER(hh,usr,out,tmp)
	{
			printf("the id is %s and the topic is %s\n",out->clientid,out->topic);
	}
	

	return 0;
}
