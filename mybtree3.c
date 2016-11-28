#include<stdio.h>
#include<stdlib.h>
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
	int cnt= 0;
	if(bt ==NULL)
	{
		return 0;
	}
	else{
		if((bt->left!=NULL)&&(bt->right!=NULL))
		{
			cnt++;
		}
		leaf(bt->left);
		
		leaf(bt->right);
		
	}
	return cnt;
}

int main()
{
	bitree *t;
	t= createbt(t);
	
	printf("先序遍历\n");
	preorder(t);
	printf("中序遍历\n");
	midorder(t);
	printf("后序遍历\n");
	lastorder(t);
	
	printf("dep=%d\n",dep(t));
	printf("leaf=%d\n",leaf(t));
	
	return 0;
	
}