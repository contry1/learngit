class solution_302 {
public:
	vector<int> path;
	vector<vector<int>> ans;

	void dfs(vector<int>nums,  deque<bool>used)
	{
		if (path.size() == nums.size())
		{
			ans.push_back(path);
			return;
		}


		for (int i = 0; i < nums.size(); ++i)
		{

		
			if (used[i] == true)
			{
				cout << i << "=1==:" << nums[i] << endl;
				continue;
			}
      
      //这里used[i] == false 一定
      //我们判断前一个i-1状态即可，可以为false ，也可以为true
			if (i > 0 && used[i - 1] == false && nums[i] == nums[i - 1])
			{
				cout << i << "=2==:" << nums[i] << endl;
				continue;
			}

			
			path.push_back(nums[i]);
			used[i] = 1;
			dfs(nums, used);

			used[i] = 0;
			path.pop_back();
			

		


		}
	}
	vector<vector<int>> get_left_index(vector<int> nums)
	{
		deque<bool>used(nums.size(), 0);
		dfs(nums, used);
		return ans;
	}
};
