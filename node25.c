#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 10 //�������Ϊ10������
typedef struct node{
	int num;
	struct node *next;
	
}node,*pnode;

void node_init(pnode *new)
{
	
		
		*new =(pnode)calloc(sizeof(node),1);
	 
		if(!(*new))
		{
			free(*new);
			
		}
}
 node* insert_end(pnode head)
{

	int n,i =0;
	pnode new ,current=NULL;
	node_init(&new);
	node_init(&current);
	scanf("%d",&(new->num));
	new->next =NULL;
	
	head = NULL;
	current = new;
	while(5-i>0&&++i)//the node21.c is i++,so the flag is false ,it will be failure.
	{
		if(!head)
				head = new;
		else
				current->next = new;
		current = new;
		//37-41 is wei cha fa code,it is like queue,who first input,and it will fisrt output.
		node_init(&new);
		scanf("%d",&(new->num));
		new->next =NULL;
	}
	
	return head;
}
/* above is wei cha fa*/





 node* insert_before(pnode head)
{

	int n,i =0;
	pnode new ,current=NULL;
	node_init(&new);
	node_init(&current);
	scanf("%d",&(new->num));
	new->next =NULL;
	
	head = NULL;
	current = new;
	while(5-i>0&&++i)//the node21.c is i++,so the flag is false ,it will be failure.
	{
		
		
		new->next = head;
		head =new;
		//72-73 tou cha fa,like stack,the order of output is opposite with input.
		node_init(&new);
		scanf("%d",&(new->num));
		new->next =NULL;
	}
	
	return head;
}






 node* delete(pnode tmp)
{


	pnode tmp_before,head,tmp_free =NULL;
	
	tmp_before =NULL;
	node_init(&tmp_before);
	node_init(&head);
	//node_init(&tmp);
	tmp_before = head;
	if(!head)
		printf("this is null head\n");
		
	while(tmp_before&&(tmp_before->next))
	{
		
		
		if(tmp_before->next ==tmp)
			{
				
					break;
			
			}	
			tmp_before=tmp_before->next;
	
	}
	tmp_free = tmp;
	tmp_before->next = tmp->next;
	free(tmp_free);
	
	return head;
			
			
	
}


#if 1
 node* delete_num(pnode head ,int val)
{
	pnode tmp_before,tmp_free=NULL;
	
	tmp_before =NULL;
	node_init(&tmp_before);
	node_init(&tmp_free);
	if(!head)
		printf("head is null\n");
	tmp_before = head;
	/*
	while(tmp_before&&(tmp_before->next))
	{
		tmp_before=tmp_before->next;
		
		if(tmp_before->next->num ==val)
					break;
	}
	*/
	while(tmp_before&&tmp_before->next)
	{
		
		
		tmp_free = tmp_before;
		tmp_free = tmp_free->next;
		if(!tmp_free)
				printf("hello\n");
		if(tmp_free->num ==val)
			{
				
				tmp_before->next = head->next;
				free(tmp_free);
				break;
			}
			tmp_before=tmp_before->next;
	}
	
	
	
	return head;
			
			
	

			
	
}
#endif


pnode delete_val(pnode head,int val)
{
	pnode delete=NULL;
	pnode delete_before =NULL;
	node_init(&delete);
	node_init(&delete_before);
	
	if(!head)
		printf("haead node is null \n");
		
	delete =  head;
	if(delete==NULL||delete->next==NULL)
		{
			printf("the delete enode is null\n");
					return NULL;
		}
	
	while((delete->num != val)&&delete->next!=NULL)
	{
		delete_before = delete;
		delete= delete->next;
		if(delete->num != val&&delete->next==NULL)
			{
				printf("there is  no find the val of node to delete\n");
				break;
			}
		if(delete->num==val)
			{
					delete_before->next =  delete->next;
					free(delete);
					break;
			}
	
	}
	/*this time the delete_before is recording the node where berore delete node.*/

	return head;


}
void printList(pnode pHead)
{
		
    if(NULL == pHead)   
    {
        printf("\n");
    }
    else
    {
        while(NULL != pHead&&pHead->next!=NULL)
        {
        	  
        		if(pHead->num !=0)
        			{
        						
        							printf("%d\t",pHead->num);
        							pHead = pHead->next;
        				
        			}
        					
        			else
        			{
        				printf("the node val is 0,so ignore\n");
        				pHead = pHead->next;
        				continue;
        			}
       		  
      			 
           
           
           
        }
        printf("\n");
    }
}
int main()
{
	pnode t;
	
	int i =0;
	//printList(t);
	t =insert_end(t);
	printList(t);
	
	//t =insert_before(t);
	//printList(t);
	
	printf("fdgggggggggggg1\n");
	t =delete(t);
	printList(t);
	
	
	printf("fdgggggggggggg2\n");
	t =delete_num(t,4);
	if(t->num==0)
			t= t->next;	
	printList(t);
	
	
	printf("fdgggggggggggg3\n");
	
		
	
	t =delete_val(t,5);
	printList(t);
	return 0;

}