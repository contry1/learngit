class solution_70 {
public:
	vector<int> path;
	vector<vector<int>> ans;
	void dfs( int start, int n,int size, int num)
	{
		if (num == size)
		{
			//if (find(ans.begin(), ans.end(), path) == ans.end())
			ans.push_back(path);
			num = 0;
			return;
		}

		for (int i = start; i <= n; ++i)
		{
			/*if (i > start && nums[i] == nums[i - 1])
			{
				cout << "nums0000[i]:" << nums[i] << endl;
				continue;
			}*/
			//cout << "nums[i-1]:" << nums[i-1] << endl;
			
			path.push_back(i);

			//cout << "nums[i]:" << nums[i] << endl;
			//start = i;
			dfs(i+1,n, size, num+1);
			path.pop_back();
}



	}
	vector<vector<int>> get_left_index(int n, int k)
	{
	
	
		dfs(1, n, k, 0);
		return ans;
	}
};






class solution_77 {
public:
	vector<int> path;
	vector<vector<int>> ans;
	void dfs(int start, int n, int size)
	{
		if (path.size() == size)
		{
			ans.push_back(path);
			return;
		}
		if (start > n)
			return;
	
		
		path.push_back(start);
	
		cout << "start:" << start << endl;
			
		dfs(start + 1, n, size);
		path.pop_back();

		cout << "star1t:" << start << endl;
			
		dfs(start+1, n, size);
		
		
		cout << "star2t:" << start  << endl;



	}
	vector<vector<int>> get_left_index(int n, int k)
	{


		dfs(1, n, k);
		return ans;
	}
};
