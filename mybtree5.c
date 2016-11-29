#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct  bitnode{
	 int key;
	struct bitnode *left;
	struct bitnode *right;
}bitree;

bitree * createbt(bitree * bt)
{
	int n;
	scanf("%d",&n);
	if(n<=1)
	{
		bt = NULL;
		//return ;
	}else{
		bt = (bitree *)calloc(sizeof(bitree),1);
		if(!bt)
		{
			perror("error\n");
			return;
		}else{
		bt->key = n;
		printf("%d的左节点\t",n);
		
		bt->left = createbt(bt->left);//遗忘等号前面，结果就是出现错误，遍历只会出现根节点，原因在于根节点和后面的节点联系断了，木有bt->left与后项进行连接。
		printf("%d的右节点\t",n);
		bt->right = createbt(bt->right);//遗忘等号前面
		}
	}
	return bt;
}

void preorder(bitree * bt)
{
	if(bt){
	printf("%d\t",bt->key);
	preorder(bt->left);
	preorder(bt->right);
	}
}

void midorder(bitree * bt)
{
	if(bt ==NULL)
	{
		return;
	}else{
	midorder(bt->left);
	printf("%d\t",bt->key);
	midorder(bt->right);
	}
}

void lastorder(bitree * bt)
{
	if(bt ==NULL)
	{
		return;
	}
	else{
	lastorder(bt->left);
	lastorder(bt->right);
	printf("%d\t",bt->key);
	}
}


int dep(bitree * bt)
{
	int depth =0;
	if(bt ==NULL)
	{
		return 0;
	}else{
	int leftdep = dep(bt->left);
	int rightdep = dep(bt->right);
	depth = leftdep>= rightdep?leftdep+1:rightdep+1;
	}
	return depth;
	
}

int leaf(bitree * bt)
{
	int left,right,cnt = 0 ;
	if(bt)
	{
		if((bt->left==NULL)&&(bt->right==NULL))
		{
			cnt++;
		}
		left = leaf(bt->left);
			cnt+=left;
		right = leaf(bt->right);
			cnt+=right;
		
	}
	return cnt;
}


int _leaf(bitree * bt)
{
	int flag = 0;
	if(!flag){
		static int cnt = 0;
		if(bt)
		{
			if((bt->left==NULL)&&(bt->right==NULL))
			{
				cnt++;
			}
			_leaf(bt->left);
			_leaf(bt->right);
			
		}
		return cnt;
		
	}
	flag = 1;
	
}



/* 这里的二叉树查找，有些问题，可以看出是针对的有序二叉树的查找，即做节点小于根节点小于右节点
而我们的二叉树是无序的，所以就会有些查找失败（创建的时候木有限定），具体的根节点必须小于右节点，大于做节点
才能查找成功。 具体的3，2，成功查找；2,3只能查找第一个，画图即可知道。*/
void bitsearch(bitree * bt,int x)
{
	if(bt)
	{
		
	
		if(x < bt->key)
		{
			bitsearch(bt->left,x);
		}else if(x > bt->key)
			bitsearch(bt->right,x);
		else{
			
			printf("already find it\n");
			return ;
		}
	}
}

/* wu xu cha zhao */
void btsearch(bitree * bt,const int x)
{
	if(bt)
	{
		
	
		if(x == bt->key)
		{
			printf("already find it\n");
			return;
			
		}else if(x != bt->key){
			btsearch(bt->left,x);
			btsearch(bt->right,x);
			
			
		}if(!(bt->right)&&!(bt->left)){
				printf("no find it\n");
				return ;
			}
			
		
		
	}
}

/* insert bt node */
void insertbt(bitree **bt,int n)
{
	
	bitree * b = NULL;
	if(!(b = (bitree *)calloc(sizeof(bitree),1)))
		perror("error calloc\n");
	else{
		b->key = n;
		b->left = NULL;
		b->right = NULL;
		if(*bt ==NULL)
		{
			*bt = b;
		
			}else{
				if(((*bt)->left==NULL)&&(n<=(*bt)->key))
				{
					(*bt)->left = b;
					return;
				}if(((*bt)->right==NULL)&&(n<=(*bt)->key))
				{
					(*bt)->right = b;
					return;
				}
				else if((n<=(*bt)->key)){
					insertbt(&((*bt)->left),n);
					printf("插入%d做节点\n",(*bt)->key);
				}
				else 	{
					insertbt(&((*bt)->right),n);
					printf("插入%d右节点\n",(*bt)->key);
				}
		
			}
		}

	
}


bitree * _insertbt(bitree *bt,int n)
{
	
	bitree * b = NULL;
	if(!(b = (bitree *)calloc(sizeof(bitree),1)))
		perror("error calloc\n");
	else{
		b->key = n;
		b->left = NULL;
		b->right = NULL;
		if(bt ==NULL)
		{
			bt = b;
			}else{
				
				if((n<= bt->key)){
					bt->left =	_insertbt((bt->left),n);
					printf("插入%d做节点\n",bt->key);
				}
				else 	{
					bt->right =	_insertbt((bt->right),n);
					printf("插入%d右节点\n",bt->key);
		
				}
		
			}
		}
	return bt;
	
}




int main()
{
	bitree *t;
	int n,m;
	t= createbt(t);
	
	
	
	
	printf("先序遍历");
	preorder(t);
	printf("\n");
	
	
	
	printf("中序遍历");
	midorder(t);
	printf("\n");
	
	scanf("%d",&n);
	btsearch(t,n);
	getchar();
	
	printf("后序遍历");
	lastorder(t);
	printf("\n");
	
	printf("the tree dep=%d",dep(t));
	printf("\n");
	printf("the tree leaf=%d",leaf(t));
	
	printf("\n");
	printf("the tree _leaf=%d",_leaf(t));
	printf("\n");
	
	scanf("%d",&m);
	insertbt(&t,m);
	
	//t =_insertbt(&t,m);
	
	
	printf("先序遍历");
	preorder(t);
	printf("\n");
	
	printf("中序遍历");
	midorder(t);
	printf("\n");
	
	printf("后序遍历");
	lastorder(t);
	printf("\n");
	
	printf("the tree dep=%d",dep(t));
	printf("\n");
	printf("the tree leaf=%d",leaf(t));
	
	printf("\n");
	printf("the tree _leaf=%d",_leaf(t));
	printf("\n");
	
	scanf("%d",&m);
	//insertbt(&t,m);
	t =_insertbt(t,m);
	
	printf("先序遍历");
	preorder(t);
	printf("\n");
	
	printf("中序遍历");
	midorder(t);
	printf("\n");
	
	printf("后序遍历");
	lastorder(t);
	printf("\n");
	
	printf("the tree dep=%d",dep(t));
	printf("\n");
	printf("the tree leaf=%d",leaf(t));
	
	printf("\n");
	printf("the tree _leaf=%d",_leaf(t));
	printf("\n");
	return 0;
	
}