class solution_162 {
public:

	//1.function 1, on，89%
	int findPeakElement(vector<int>& nums) {

		int len = nums.size();
		int left = 0;
		int right = len - 1;
		if (len == 0)
			return -1;
		
		//1.特殊情况下的峰值，只有一个数，有两个数，以及前两个数降序
		if (len == 1)
			return 0;
		if (len == 2)
			return nums[0] > nums[1] ? 0 : 1;
		if (nums[0] > nums[1])
			return 0;

		//2.一般情况，从第二个数到倒数第二个数
		int i;
		for (i = 1; i < right; ++i)
		{
			if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
			{
				return i;
			}
			else
			{
				/*if (nums[i] > nums[i + 1])
					i = i + 2;*/
			}
		}
		//i == right,right is max，ex ：1，2，3
		return i;
	}

	//2.function 2, on， 98%
	int findPeakElement(vector<int>& nums) {

		int len = nums.size();
		int left = 0;
		int right = len - 1;
		if (len == 0)
			return -1;
		if (len == 1)
			return 0;
		if (len == 2)
			return nums[0] > nums[1] ? 0 : 1;
		if (nums[0] > nums[1])
			return 0;


		int i;
		for (i = 1; i < right; ++i)
		{
			if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
			{
				return i;
			}
			else
			{
				if (nums[i] > nums[i + 1])
					i = i + 1;
			}
		}
		//i == right,right is max
		return i;

	}


	//3.function bina 3, on，89%
	int findPeakElement(vector<int>& nums) {

		int len = nums.size();
		int l = 0;
		int r = len - 1;
		if (len == 0)
			return -1;
		if (len == 1)
			return 0;
		if (len == 2)
			return nums[0] > nums[1] ? 0 : 1;
		if (nums[0] > nums[1])
			return 0;

		l = 1;
		while (l < r)
		{

			int m = (r + l) >> 1;
			if (nums[m] > nums[m - 1] && nums[m] > nums[m + 1])
			{
				return m;
			}
			else if (nums[m] > nums[m - 1] && nums[m] < nums[m + 1])
			{
				l = m + 1;
			}
			else if (nums[m] < nums[m - 1] && nums[m] > nums[m + 1])
			{
				r = m-1;
			}
			else
				l = m + 1;//r = m-1 也ac!
		}
		//i == right,right is max
		return r;


	}
};
