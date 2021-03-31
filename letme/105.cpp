class Solution {
public:
	int get_index(vector<int>& preorder, int b1, vector<int>& inorder)
	{
		int x = 0;
		for (auto &ch : inorder)
		{
			if (ch == preorder[b1])
				break;
			x++;
		}
		return x;
	
	}

	//对于B2-B1>1,not ac
	TreeNode* dfs(vector<int>& preorder,int b1,int e1, vector<int>& inorder,int b2,int e2)
	{
		if (b1 == e1 || b2 == e2)
			return nullptr;
		TreeNode* root = new TreeNode(preorder[b1]);
		root->left = new TreeNode(inorder[b2]);//dfs(preorder,b1+1,e1,inorder,b2,e2);
		root->right = dfs(preorder, b1 + 2, e1, inorder, b2+2, e2);

		return root;
	}
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.size() == 2)
		{
			if (preorder[0] == inorder[0])
			{
				TreeNode* root = new TreeNode(preorder[0]);
				root->right = new TreeNode(preorder[1]);
				return root;
			}
			else
			{
				TreeNode* root = new TreeNode(preorder[0]);
				root->left = new TreeNode(preorder[1]);
				return root;
			}
			
			
		}
		if (preorder.size() == 1)
		{
			TreeNode* root = new TreeNode(preorder[0]);
			return root;
		}
		return dfs(preorder,0, preorder.size()-1, inorder,0, inorder.size()-1);
	}


	//ac 体会分支
	std::unordered_map<int, int>mp;
	TreeNode* dfs(vector<int>& preorder, int b1, int e1, vector<int>& inorder, int b2, int e2)
	{
		if (b1 > e1)
			return nullptr;

		int root_index = mp[preorder[b1]];
		TreeNode* root = new TreeNode(preorder[b1]);//(inorder[root_index]);

		int left_num = root_index - b2;
		root->left = dfs(preorder, b1 + 1, b1 + left_num, inorder, b2 , root_index-1);
		root->right = dfs(preorder, b1 + left_num + 1, e1, inorder, root_index +1, e2);
		return root;
	}

	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int i = 0;
		for (auto &ch : inorder)
			mp[ch] = i++;
		return dfs(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
	}
};
