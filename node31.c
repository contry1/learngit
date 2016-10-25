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
 node* insert()
{

	int i;
	pnode tmp,last =NULL;
	//node_create(&tmp);
	tmp=(pnode)calloc(sizeof(node),1);
	last=(pnode)calloc(sizeof(node),1);
	//node_create(&last);
	last = tmp;
	pnode head = NULL;
	scanf("%d",&(tmp->num));
	printf("insert %d\n",tmp->num);
	tmp->next =NULL;
	
	while(tmp->num>0)
	{

		if(!head)
				head = tmp;
		else
			
				last->next = tmp;
		last = tmp;
		//node_create(&tmp);
		tmp=(pnode)calloc(sizeof(node),1);
		scanf("%d",&(tmp->num));
		printf("insert %d\n",tmp->num);
		tmp->next =NULL;
		
		
	}
	return head;
}



void print(pnode *head)
{
	if(*head ==NULL)
		{
			printf("this is null\n");
		}
		while(*head!=NULL)
		{
			printf("***********\t%d ",(*head)->num);
			*head= (*head)->next;
		}
		printf("\n");

}
int main()
{
	pnode t;
	int i;
	node_create(&t);
	
	t= insert(t);
	
	print(&t);
	return 0;

}
