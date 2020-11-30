class solution_3 {
public:
	vector<int> path;
	vector<vector<int>> ans;
	vector<vector<int>> dfs(vector<int> &nums, int start, int size)
	{
		ans.push_back(path);
	/*	for (int j = 0; j < path.size(); ++j)
		{
			cout << path[j] << "\t";
		}*/
		/*cout << endl;*/

		for (int i = start; i < size; ++i)
		{
			path.push_back(nums[i]);
			cout << "nums[i]:" << nums[i]<< endl;
			dfs(nums,i+1,size);
			path.pop_back();
		}
		return ans;
	
	}
	vector<vector<int>> get_left_index(vector<int> &nums)
	{
		int len = nums.size();
		return dfs(nums,0,len);
	}
};
