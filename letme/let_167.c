class solution_167 {
public:
	
	//1.two point func  on
	vector<int>  get_left_index(vector<int> &nums, int target)
	{
		int len = nums.size();
		int left = 0;
		int right = len - 1;
		if (len == 0)
			return vector<int>{-1, -1};

		int low;
		int up;
		while (left < right)
		{
			if (nums[left] + nums[right] > target)
			{
				right--;
			}
			else if (nums[left] + nums[right] == target)
			{
				low = left + 1;
				up = right + 1;
				break;
			}
			else
			{
				left++;
			}
		}
		if (left == right)
			return vector<int>{-1, -1};
		return vector<int>{low, up};
}

	//2.bina seach func  nlogn
	int search1(vector<int> &nums, int start,int target)
	{
		int len = nums.size();
		int l = start;
		int r = len - 1;

		while (l <= r)
		{

			int mid = (r + l) >> 1;
			if (nums[mid] == target)
			{
				return mid;
			}
			else if (nums[mid] < target)
			{
				l = mid + 1;
				cout << "hhhhh1hhhhhh" << endl;
			}
			else
			{
				r = mid - 1;
				cout << "hhhhh2hhhhhhh" << endl;
			}

			//if last l == r
			//it must return or break loop since l>r on the next time,so it is ok!

		}
		return -1;
	}
	vector<int>  get_left_index2(vector<int> &nums, int target)
	{
		int len = nums.size();
		int left = 0;
		int right = len - 1;
		if (len == 0)
			return vector<int>{-1, -1};

		int low;
		int up;
		for (int i = 0; i < right; ++i)
		{
			if ((up = search1(nums,i+1, target - nums[i]) )!= -1)
			{
				low = i;
				break;
			}
		}
		if (left == right)
			return vector<int>{-1, -1};
		return vector<int>{low+1, up+1};
	}
};
