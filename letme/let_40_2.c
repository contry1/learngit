class solution_40 {
public:
	vector<int> path;
	vector<vector<int>> ans;
	void dfs(vector<int> &nums, int start, int size, int target)
	{
		if (target == 0)
		{
			ans.push_back(path);
			return;
		}
		for (int i = start; i < size; ++i)
		{
		
			if (target < nums[i])
			{
				continue;
			}
			path.push_back(nums[i]);
			start = i;
			dfs(nums, start + 1, size, target - nums[i]);
			path.pop_back();
		}
	}
	vector<vector<int>> get_left_index(vector<int> &nums, int target)
	{
		int len = nums.size();
		sort(nums.begin(), nums.end()); //quchong
		dfs(nums, 0, len, target);
		return ans;
	}
};
