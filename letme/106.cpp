class Solution_106 {
public:
	std::unordered_map<int, int>mp;
	TreeNode* dfs(vector<int>& inorder, int b1, int e1, vector<int>& postorder, int b2, int e2)
	{
		if (e2<b2)
			return nullptr;

		int root_index = mp[postorder[e2]];
		TreeNode* root = new TreeNode(postorder[e2]);//(inorder[root_index]);

		int left_num = root_index - b1;
		root->left = dfs(inorder, b1 , root_index - 1, postorder, b2, b2+ left_num);
		root->right = dfs(inorder, root_index + 1, e1, postorder, b2 + left_num + 1, e2-1);
		return root;
	}


	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
	{
		int i = 0;
		for (auto &ch : inorder)
			mp[ch] = i++;
		return dfs(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
	}
};
