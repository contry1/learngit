class solution_binary {
public:
	bool search1(vector<int> &nums, int target)
	{
		int len = nums.size();
		int l = 0;
		int r = len - 1;

		while (l <= r)
		{
			
			int mid = (r +l) >> 1;
			if (nums[mid] == target)
			{
				return true;
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
		return false;
	}

	bool search2(vector<int> &nums, int target)
	{
		int len = nums.size();
		int l = 0;
		int r = len - 1;

		while (l < r)
		{
			int mid = (r + l) >> 1;
			if (nums[mid] == target)
			{
				return true;
			}
			else if (nums[mid] < target)
			{
				l = mid + 1;
			}
			else
			{
				r = mid - 1;
			}

			//if last l == r-1 =>mid = (2r-1)/2 = r -0.5 = r-1（取整） = L;
			//it must return or break loop since l==r on the next time,so it is ok!

		}
		return target == nums[l];
	}
};
