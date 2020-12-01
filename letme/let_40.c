class solution_5 {
public:
	vector<int> path;
	vector<vector<int>> ans;
	void dfs(vector<int> &nums, int start, int size,int target)
	{
		if (target == 0)
		{
			if(find(ans.begin(),ans.end(),path) == ans.end())
				ans.push_back(path);
			return;
		}
		for (int i = start; i < size; ++i)
		{
			/*if (i > start && nums[i] == nums[i - 1])
			{
				cout << "nums0000[i]:" << nums[i] << endl;
				continue;
			}*/
			//cout << "nums[i-1]:" << nums[i-1] << endl;
			if (target < nums[i])
			{
				cout << "nums0000[i]:" << nums[i] << endl;
				continue;
			}			
			path.push_back(nums[i]);

			cout << "nums[i]:" << nums[i] << endl;
			start = i;
			dfs(nums, start + 1, size,target - nums[i]);
			path.pop_back();
		}



	}
	vector<vector<int>> get_left_index(vector<int> &nums,int target)
	{
		int len = nums.size();
		sort(nums.begin(),nums.end());
		dfs(nums, 0, len, target);
		return ans;
	}
};
