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

/* the static  func is quanju,this is make num of leaf is sum of this time and before time */
int _leaf(bitree * bt)
{
	
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

/* ************************************************************************* */
/* the above is 递归方式，下面是非递归 */
/* ************************************************************************* */
/* 非递归先序遍历 */
/* 思想：1.现将根节点入站，top++,再出战 
		 2.再讲根节点的右节点入站，做节点入站，如果左右节点存在的话，当然如果木有左右节点，直接pop根节点即可
		 3.这样的流程，入站是跟右左，出战跟左右，因为第一个跟节点，入站就出战了。所以如此
		 4.按照固定思维，先序的入站顺序是右左根，考虑到实际可行度，实际为根右左。*/
void _preorder(bitree * bt)
{
	bitree * root =NULL;
	
	bitree *stack[20] ={0};
	int top = -1;
	
	if(bt){
		top++;
		stack[top] = bt;
		while(top>-1)
		{
		
			root = stack[top];
			printf("非递归先序遍历%d\t\n",root->key);
			top--;
		
			if(root->right){
				top++;
				stack[top] = root->right;
			
			
			}if(root->left){
				top++;
				stack[top] = root->left;
			
			}
		
		}
	}
}


/* 非递归中序遍历 左根友 */
/* 思想：1.现将根节点入站，top++,再将根节点的所有做节点入站，直到该节点木有做节点，停止入站
		 2.打印栈顶元素，top--。
		 2.再讲根节点的右节点入站，循环1.
		 3.这样的流程，入站是跟左右，出战左跟右，因为第一个，第二个节点，入站就出战了。所以如此
		 4.按照固定思维，中序的入站顺序是右根左，考虑到实际可行度，实际为根左右。*/
		 
		 
/* 首先根节点入栈，判断根节点的左孩子是否为空，若不为空，则入栈，并不断移动node指针指向左孩子，直到左孩子节点为空。 */
    /* 然后弹出栈顶元素并访问该元素。判断弹出元素的右孩子是否为空，若不为空，则把右孩子入栈，并把node指针指向右孩子。重复以上操作。 */
		 
void _midorder(bitree * bt)
{
	bitree * root =NULL;
	bitree * node =NULL;
	bitree *stack[20] ={0};
	int top = -1;
	
	
	if(bt){
		top++;
		root = bt;
		stack[top]= bt;
		
		/* push all left node */
		while( top>-1||root->left ){
			while(root->left){
				top++;
				stack[top]=root->left;
				root = root->left;
			}
			/* pop the top atom */
			if(top>-1)
			{
				node = stack[top];
				top--;
				printf("非递归中序遍历%d\t\n",node->key);
				root->left = node->right;//this is important,之前段错误。是root= node_>right；
				
				
			}
			/* push the right node */
			
			
		}
		
		}
	
}
/* 后续遍历非递归方式 */
/* 在节点的结构体中加入一个参数isVisited,表示某个节点是否被访问过。
 
 首先根节点入栈，然后判断左孩子是否为空，若不为空，则左孩子入栈，并移动node到左孩子，直到左孩子为空。
 然后判断栈顶元素，如果栈顶元素没有右孩子或者右孩子已经被访问过，那么就访问该栈顶元素，并出栈；如果栈顶元素有右孩子并且右孩子没有被访问过，那么把右孩子入栈，把node指针指向右孩子。
 若栈不为空，则重复以上操作。
 */
void _lastorder(bitree * bt)
{
	bitree * current =NULL;
	bitree * isnode =NULL;
	bitree *stack[20] ={0};
	int top = -1;
	top++;
	stack[top] = bt;
	current = bt;
	while(top>-1)
	{
		while(current->left)
		{
			top++;
			stack[top] = current->left;
			current = current->left;
		}
		current = stack[top];
		if(current->right==isnode||current->right==NULL)
		{
			printf("非递归后序遍历%d\t\n",current->key);
			isnode = current;
			top--;
			current->left= NULL;
		}else{
			current->left = current->right;
		}
	}
	
#if 0
	if(bt){
		top++;
		stack[top] = bt;//gen node push
		root = bt;
		while(top>-1||root)
			{
				while(root)
				{
					top++;
					stack[top]=root->left;
					root = root->left;
				}
				root = stack[top] ;
				if(root->right == NULL)
				{
					
					printf("非递归后序遍历%d\t\n",root->key);
					top--;
					root =NULL;
					
					
				}else{
					root=root->right;
					
				}
			}
			
		
		}

		 
		
	
		bitree *preVisited = NULL ;  //已经访问过的节点
		bitree *current    = bt ;  //当前节点
		//树非空
		while(top != -1 || current )
		{
		//根节点和它的左子树的所有左孩子节点入栈
			while(current)
			{
				top++ ; 
				stack[top] = current ; 
				current = current->left ; 
			}

		//获取栈顶节点
		current = stack[top] ;

		//处理该节点的右孩子节点，右孩子节点要么是已经访问了的，要么不存在
		if(current->right == preVisited || current->right == NULL)
		{
			printf("非递归后序遍历%d\t\n",current->key) ;
			preVisited = current ; 
			top-- ; 
			current = NULL ;
		}
		else//有右孩子
		{
			//右孩子入栈
			current = current->right ; 
		}
	}

#endif		
	
}




void _lastorder2(bitree * bt)
{
	//bitree * current =NULL;
	bitree * isnode =NULL;
	bitree *stack[20] ={0};
	int top = -1;
	
	bitree *preVisited = NULL ;  //已经访问过的节点
	bitree *current    = bt ;  //当前节点
		//树非空
		while(top != -1 || current )
		{
		//根节点和它的左子树的所有左孩子节点入栈
			while(current)
			{
				top++ ; 
				stack[top] = current ; 
				current = current->left ; 
			}

		//获取栈顶节点
		current = stack[top] ;

		//处理该节点的右孩子节点，右孩子节点要么是已经访问了的，要么不存在
		if(current->right == preVisited || current->right == NULL)
		{
			printf("非递归后序遍历%d\t\n",current->key) ;
			preVisited = current ; 
			top-- ; 
			current = NULL ;
		}
		else//有右孩子
		{
			//右孩子入栈
			current = current->right ; 
		}
	}
	
}

int main()
{
	bitree *t;
	int n,m;
	t= createbt(t);
	
	
	
	
	printf("先序遍历");
	preorder(t);
	printf("\n");
	
	//_lastorder(t);
	
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
	//t =_insertbt(t,m);
	
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
	
	//_preorder(t);
	printf("\n");
	//_midorder(t);
	printf("\n");
	_lastorder(t);
	
	printf("\n");
	//_lastorder2(t);
	return 0;
	
}