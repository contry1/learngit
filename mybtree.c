#include<stdio.h>
#include<stdlib.h>
typedef struct  bitnode{
	int key;
	struct bitnode *left;
	struct bitnode *right;
}bitree,*bitlink;

int createbt(bitree **bt)
{
	int n;
	scanf("%d",&n);
	if(n<=1)
	{
		*bt = NULL;
		return -1;
	}else{
		*bt = (bitree *)calloc(sizeof(bitree),1);
		(*bt)->key = n;
		printf("左节点\n");
		createbt(&((*bt)->left));
		printf("右节点\n");
		createbt(&((*bt)->right));
	}
	return 0;
}

void preorder(bitree *bt)
{
	if(bt ==NULL)
	{
		return;
	}
	printf("%d\n",bt->key);
	preorder(bt->left);
	preorder(bt->right);
}

void midorder(bitree *bt)
{
	if(bt ==NULL)
	{
		return;
	}
	midorder(bt->left);
	printf("%d\n",bt->key);
	
	midorder(bt->right);
}

void lastorder(bitree *bt)
{
	if(bt ==NULL)
	{
		return;
	}
	
	lastorder(bt->left);
	lastorder(bt->right);
	printf("%d\n",bt->key);
}


int dep(bitree *bt)
{
	int depth =0;
	if(bt ==NULL)
	{
		return 0;
	}
	int leftdep = dep(bt->left);
	int rightdep = dep(bt->right);
	depth = leftdep>= rightdep?leftdep+1:rightdep+1;
	return depth;
	
}

int leaf(bitree *bt)
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
	}
	return cnt;
}

int main()
{
	bitree *t;
	createbt(&t);
	
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