class Solution_98 {
public:
	//上下线逼近
	bool helper(TreeNode* root, long low, long up)
	{
		if (root == nullptr)
			return true;
		if (root->val<=low || root->val>=up)
			return false;
		return helper(root->left,low,root->val)&& helper(root->right, root->val,up);
	}
	bool isValidBST(TreeNode* root)
	{
		return helper(root,LONG_MIN,LONG_MAX);
	}


	class Solution {
	public:
		long limit = LONG_MIN;
		bool isValidBST(TreeNode* root)
		{
			if (root == nullptr)
			{
				return true;
			}

			if (isValidBST(root->left) == false)
				return false;
			if (root->val <= limit)
			{
				return false;
			}
			limit = root->val;
			return isValidBST(root->right);


		}
	};
};
