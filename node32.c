#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 10 //�������Ϊ10������
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
 node* insert(pnode head)
{

	int i;
	pnode tmp,last =NULL;
	node_create(&tmp);
	
	node_create(&last);
	last = tmp;
	head = NULL;//��һ�����Ҫ�����ľ����һ�䣬������ӡ���ֻ��һ��0���޷��õ���ȷ�Ĵ𰸡���ʱ��headĬ�ϲ���null����Ϊmain����������ˡ������Ȱѱ�///ͷ��ͷ����Ϳա�
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
		node_create(&tmp);
		
		scanf("%d",&(tmp->num));
		printf("insert %d\n",tmp->num);
		tmp->next =NULL;
		
		
	}
	return head;
}



void print(pnode *head)
{
	int i =0;
	if(*head ==NULL)
		{
			printf("this is null\n");
		}
		while(*head!=NULL)
		{
			printf("***the %d num is equal %d ",i++,(*head)->num);
			printf("\n");
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
