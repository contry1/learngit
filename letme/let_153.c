class solution_153{
public:

	int get_left_index(vector<int> &nums)
	{
		int len = nums.size();
		int left = 0;
		int right = len - 1;

		while (left <= right)
		{
			int mid = (left + right) >> 1;
			
				
			if (nums[left] < nums[mid])
			{
				if (nums[left] < nums[mid] && nums[mid] < nums[right])
				{
					return nums[left];
				}
				else
				{
					left = mid + 1;

				}
			}
			else
			{
				if (nums[right] >= nums[mid])
				{

					return nums[left];
				}
				else
				{
					left = mid + 1;
				}
			}

		}

		return -1;
	}
};
