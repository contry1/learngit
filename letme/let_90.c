
1 functin 
class solution_90 {
public:
	vector<int> path;
	vector<vector<int>> ans;

	void dfs(vector<int> &nums, int start, int size, deque<bool>used)
	{
	

		//for (int i = start; i < size; ++i)
	/*	if(start < size)
		{
	
			path.push_back(nums[start]);
			cout << "nums[i]:" << nums[start] << endl;
			ans.push_back(path);
			dfs(nums, start + 1, size);
			path.pop_back();
			dfs(nums, start + 1, size);
		}*/
		
		ans.push_back(path);
		for ( int i = start; i < size; ++i)
		{
			if (used[i] == true)
				continue;

			if (i > 0&& used[i-1] == 0&& (nums[i] == nums[i-1]))

				//if (i > start  && (nums[i] == nums[i - 1]))
			{
				cout << "=========start:" << start << "\tnums[start]:" << nums[start] << endl;
				cout << "=========i:" << i << "\tnums[i]:" << nums[i] << endl;
				continue;
			}
			
			
			
			path.push_back(nums[i]);
			used[i] = true;
			cout << "start:"<<start << "\tnums[start]:" << nums[start] << endl;
			cout << "i:"<<i<< "\tnums[i]:" << nums[i] << endl;
		
			dfs(nums, i + 1, size,used);
			used[i] = false;
			path.pop_back();

			
		
		}
		//return ans;

	}
	vector<vector<int>> get_left_index(vector<int> &nums)
	{
		int len = nums.size();
		deque<bool>used(len,false);
	
			dfs(nums, 0, len,used);
			return ans;
	}
};




2 functinm

class solution_90 {
public:
	vector<int> path;
	vector<vector<int>> ans;

	void dfs(vector<int> &nums, int start, int size)
	{
	

		//for (int i = start; i < size; ++i)
	/*	if(start < size)
		{
	
			path.push_back(nums[start]);
			cout << "nums[i]:" << nums[start] << endl;
			ans.push_back(path);
			dfs(nums, start + 1, size);
			path.pop_back();
			dfs(nums, start + 1, size);
		}*/
		
		ans.push_back(path);
		for ( int i = start; i < size; ++i)
		{
			

		

			if (i > start  && (nums[i] == nums[i - 1]))
			{
				cout << "=========start:" << start << "\tnums[start]:" << nums[start] << endl;
				cout << "=========i:" << i << "\tnums[i]:" << nums[i] << endl;
				continue;
			}
			
			
			
			path.push_back(nums[i]);
			
			cout << "start:"<<start << "\tnums[start]:" << nums[start] << endl;
			cout << "i:"<<i<< "\tnums[i]:" << nums[i] << endl;
		
			dfs(nums, i + 1, size);
	
			path.pop_back();

			
		
		}
		//return ans;

	}
	vector<vector<int>> get_left_index(vector<int> &nums)
	{
		int len = nums.size();
	
	//sort
			dfs(nums, 0, len);
			return ans;
	}
};

line99 see 
