#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 10 //待排序的为10个数字
typedef struct bucket_t{
	char * num;
	//struct bucket_t *next;
	
}bucket,*pbucket;

void bucket_init(bucket  ** p)
{   
		
		 * p = (bucket *)malloc(sizeof(bucket));
		if(NULL==p)
				return;
		//memset(p,0,sizeof(bucket));
		
}


int main(void)
{
		int n,i;
		bucket *p =NULL;
    bucket_init(&p);	
    p->num =(char *)malloc(10);
    if(p->num)
    	strcpy(p->num,"go");
    
    printf("%s\n",p->num);
    free(p->num);
    free(p);
    getchar();
	  return 0;
}
