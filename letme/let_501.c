class Solution_501 {
public:
	//functin1 暴力法
	map<int,int>mp;
	void help(TreeNode* root)
	{
		if (root == nullptr)
			return;
		help(root->left);
		mp[root->val]++;
		help(root->right);
	}
	vector<int> findMode(TreeNode* root)
	{
		help(root);
		vector<int>ans;
		int ms = 0;
		for (auto &ch : mp)
		{
			ms = max(ms,ch.second);
		}

		for (auto &ch : mp)
		{
			if (ms == ch.second)
			{
				ans.emplace_back(ch.first);
			}
		}
		return ans;
	}


	//优化
	map<int, int>mp;
	int ms = 0;
	void help(TreeNode* root)
	{
		if (root == nullptr)
			return;
		help(root->left);
		mp[root->val]++;
		ms = max(mp[root->val],ms);
		help(root->right);
	}
	vector<int> findMode(TreeNode* root)
	{
		help(root);
		vector<int>ans;
		for (auto &ch : mp)
		{
			if (ms == ch.second)
			{
				ans.emplace_back(ch.first);
			}
		}
		return ans;
	}
};
