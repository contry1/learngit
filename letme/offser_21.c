class Solution_of_21 {
public:
	vector<int> exchange(vector<int>& nums)
	{
		vector<int>left;
		vector<int>right;

		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] % 2 == 0)
			{
				right.emplace_back(nums[i]);
			}
			else
			{
				left.emplace_back(nums[i]);
			}
		}

		for (int i = 0; i < right.size(); ++i)
		{
			left.emplace_back(right[i]);
		}
		return left;
	}

	//not ok
	vector<int> exchange2(vector<int>& nums)
	{
		
		vector<int>right;

		int len = nums.size();
		for (int i = 0; i < len; ++i)
		{
			if (nums[i] % 2 == 0)
			{
				nums.erase(nums.begin()+i);
				right.emplace_back(nums[i]);
				i--;
				len--;
			}
			
		}

		for (int i = 0; i < right.size(); ++i)
		{
			nums.emplace_back(right[i]);
		}
		return nums;
	}

	//第三种揭发，递归，最后两个数据过长没有通过超时了
	void swap(int *a, int *b)
	{
		int c = *a;
		*a = *b;
		*b = c;

	}
	vector<int> get_left(vector<int>& nums, int left, int right)
	{
		if (left < right)
		{
			if (nums[left] % 2 == 0 && nums[right] % 2 != 0)
			{
				swap(&nums[left], &nums[right]);
				left++;
				right--;
				get_left(nums, left, right);
			}
			else if (nums[left] % 2 == 0 && nums[right] % 2 == 0)
			{
				right--;
				get_left(nums, left, right);
			}
			else if (nums[left] % 2 != 0 && nums[right] % 2 == 0)
			{
				left++;
				right--;
				get_left(nums, left, right);
			}
			else if (nums[left] % 2 != 0 && nums[right] % 2 != 0)
			{
				left++;
				get_left(nums, left, right);
			}
		}
		
		return nums;
	}

	vector<int> exchange3(vector<int>& nums)
	{	
		return get_left(nums,0, nums.size()-1);
	}
};
