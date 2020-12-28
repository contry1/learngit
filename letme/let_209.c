class solution_209 {
public:

	/*1. func1  timeout*/ 
	int search1(vector<int> &nums, int start, int target)
	{
		
		if (target <= 0)
			return start;
		if (start >= nums.size())
			return 0;
		return search1(nums,start+1,target - nums[start]);
	}

	int search2(vector<int> &nums, int start, int target)
	{
		while (start < nums.size())
		{
		
		
			target -= nums[start];
			cout << "target:  " << target << endl;
			start++;
			if (target <= 0)
			{
				cout << "start " << start << endl;
				return start;
			}
			
		}

		//if (target <= 0)
		//	return start;
		//if (start >= nums.size())
			return 0;
		//return search1(nums, start + 1, target - nums[start]);
	}
	int  get_left_index(vector<int> &nums, int s)
	{
		int len = nums.size();
		int left = 0;
		int right = len - 1;

		if (len == 0)
			return 0;
		
		int low = 0;
		int up=0;
		vector<int> prev;
		for (int i = 0; i <= right; ++i)
		{
			up = search1(nums, i + 1, s - nums[i]);
			if (up)
			{
				//cout << "v.size" << up - i << endl;
				prev.push_back(up-i);
			}
		
		}
		if (prev.size() == 0)
		{
			return 0;
		}
		else if (prev.size() == 1)
			return prev[0];
		else
		{
			low = prev[0];
			for (int i = 0; i < prev.size(); ++i)
			{
				low = min(prev[i], low);
				cout << "low.size" << low << endl;

			}
		}
		
	
		return low;
	}



	/*2. func2*/

	int  get_left_index2(vector<int> &nums, int s)
	{
		int len = nums.size();
		int left = 0;
		int right = len - 1;

		if (len == 0)
			return 0;
		//1.特殊情况
		if (nums[0] >= s)
			return 1;
		int low = len;
		int up = 0;
		
		//2.一般情况，至少两个数
		int null_num = 0;
		for (int i = 0; i <= right; ++i)
		{
			up = search2(nums, i + 1, s - nums[i]);
			if (up)
			{
				cout << "v.size" << up - i << endl;
				low = min(low,up-i);
			}
			else
			{
				null_num++;
			}

		}
		if (len == null_num)
		{
			return 0;
		}
		//3.特殊情况
		if (nums[right] >= s)
			return 1;
		
		return low;
	}


	/*22. func2  优化*/

	int  get_left_index22(vector<int> &nums, int s)
	{
		int len = nums.size();
		int left = 0;
		int right = len - 1;

		if (len == 0)
			return 0;
		//1.特殊情况
		if (nums[0] >= s)
			return 1;

		int low = len+1;
		int up = 0;

		//2.一般情况，至少两个数
		for (int i = 0; i <= right; ++i)
		{
			up = search2(nums, i + 1, s - nums[i]);
			if (up)
			{
				cout << "v.size" << up - i << endl;
				low = min(low, up - i);
			}
		

		}
		if (low == len + 1)
		{
			return 0;
		}
		//3.特殊情况
		if (nums[right] >= s)
			return 1;

		return low;
	}
};
