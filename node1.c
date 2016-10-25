#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 10 //待排序的为10个数字
typedef struct node{
	int num;
	struct node *next;
	
}node,*pnode;

void node_create(pnode *new)
{
	
	 *new=(pnode)calloc(sizeof(node),1);
	 if(NULL==*new)
	 	{
	 		printf("error\n");
	 		free(*new);
	 	}
	 	
		
}
 void insert(pnode *head)
{

	int n,i =5;
	pnode tmp,last =NULL;
	node_create(&tmp);
	scanf("%d",&(tmp->num));
	tmp->next =NULL;
	*head =NULL;
	node_create(&last);
	last =tmp;
	while(--i)
	{
		
		
		if(!(*head))
				*head = tmp;
		else
			{
				last->next = tmp;
				last = tmp;
			}
		node_create(&tmp);
		scanf("%d",&(tmp->num));
		tmp->next =NULL;
		
	}
	
}



void print(pnode head)
{
	if(head ==NULL)
		{
			printf("this is null\n");
		}
		while(head)
		{
			printf("%d ",head->num);
			head= head->next;
		}
		printf("\n");

}
int main()
{
	pnode t;
	int i;
	node_create(&t);
	
	insert(&t);
	printf("\n");
	print(t);
	return 0;

}
