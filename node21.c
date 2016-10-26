#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 10 //待排序的为10个数字
typedef struct node{
	int num;
	struct node *next;
	
}node,*pnode;

void node_init(pnode *new)
{
	
		
		*new =(pnode)calloc(sizeof(node),1);
	 	//(*new)->num = 0;
	 	//(*new)->next =	NULL;
		if(!(*new))
		{
			free(*new);
			
		}
}
 node* insert(pnode head)
{

	int n,i =0;
	pnode new ,current=NULL;
	node_init(&new);
	node_init(&current);
	scanf("%d",&(new->num));
	new->next =NULL;
	head = NULL;
	current = new;
		
		
	while(5-i>0&&i++)
	{
		if(!head)
				head = new;
		else
				current->next = new;
			
			
		current = new;
		node_init(&new);
		scanf("%d",&(new->num));
		new->next =NULL;
	}
	
	return head;
}

void printList(pnode pHead)
{
    if(NULL == pHead)   //链表为空
    {
        printf("Print000000000\n");
    }
    else
    {
        while(NULL != pHead)
        {
            printf("%d ",pHead->num);
            pHead = pHead->next;
        }
        printf("\n");
    }
}
int main()
{
	pnode t;
	
	
	//printList(t);
	t =insert(t);
	printList(t);
	
	
	return 0;

}
