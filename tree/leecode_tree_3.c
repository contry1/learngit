
bool is_father(tree *root, tree * son)
{
	if (root == NULL)
	{
		cout << "root->val =7= son\t"<<son->val << endl;
		return 0;
	}
	
	if (root->val == son->val)
	{
		cout << "root->val == son\t" << son->val<< endl;
		return 1;
	}
	cout << "p is ff00:" <<root->val<<son->val<< endl;

	return is_father(root->left,son) || is_father(root->right,son);

}


tree * r1 = NULL;
tree * r2 = NULL;
int flag1;
int flag2;
tree * get(tree * root, tree *p, tree * q)
{

	if (root == NULL )
	{
		cout << "root p is NULL"  << endl;
		return NULL;
	}
	/*if (root->val == p->val || root->val == q->val)
	{
		
		return root;

	}*/

	//if (root->left)
	//{
	//	if (root->left == p|| root->left == q)
	//	{
	//		cout << "root p is " << root->val << endl;
	//		r1 = root;

	//	}
	//}
	//if (root->right)
	//{
	//	if (root->right == q|| root->right == p)
	//	{
	//		cout << "root q is " << root->val << endl;
	//		r2 = root;

	//	}
	//}
	

	
	//r1 =
	//	r2 =
	cout << "root is p is q is:" <<root->val<< p->val << q->val << endl;
	 get(root->left, p, q);
	 get(root->right, p, q);

	 if (root->left == p || (root->left == q))
	 {
		 cout << "find p ,q:" << root->val << endl;
		 if(root->left == p)
			 flag1 = 1;
		 else
			 flag2 = 1;
		 return root;
	
	 }
	 if (flag1 == 1)
	 {
		 if (root->right == q)
		 {
			 flag1 = 2;
			 cout << "find  flag1:" << root->val << endl;
			 r1 = root;
			 return root;
		 }
	 }

	 if (flag2 == 1)
	 {
		 if (root->right == p)
		 {
			 flag2 = 2;
			 cout << "find  flag2:" << root->val << endl;
			 r2 = root;
			 return root;
		 }
	 }
	 if (r1)
	 {
		 cout << "r1  is:" << r1->val << endl;
		 return r1;
	 }
	
	 if (r2)
	 {
		 cout << "r2  is:" << r2->val << endl;
		 return r2;
	 }


	
	
}


tree * father(tree * root, tree *p, tree * q)
{
	if (root == NULL)
	{
		return NULL;
	}
	cout << "p is q" << p->val<<q->val<<endl;
	if (is_father(p, q) == 1)
	{
		cout << "p is ff" << endl;
		return p;
	}
		
	else if (is_father(q, p) == 1)
	{
		cout << "q is ff"  << endl;
		return q;
	}
	
	else
	{
		cout << "root is ff" << endl;
		return get(root,p,q);
	}




}

bool huiwen(int x)
{
	if (x < 0 || x % 10 == 0 && x>0)
		return 0;
	int revnum = 0;
	while (x > revnum)
	{
		revnum = revnum * 10 + x % 10;
		x /= 10;
	}

	return x == revnum || x == revnum / 10;
}

int  int_num(int a[], int len)
{
	int i = 0;
	int key = 0;
	key = a[0];
	int j = 0;
	for (i = 1; i < len; ++i)
	{
		if (key == a[i])
		{
			for (j = i-1; j < len; ++j)
			{
				a[j] = a[j+1];
			
			}
			len--;
			i = i - 1;
		}
		else
		{
			key = a[i];
		}
		
	}
	return len;
}
