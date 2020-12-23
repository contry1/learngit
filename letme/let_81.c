class solution_81 {
public:

	int get_left_index(vector<int> &nums, int target)
	{
		int len = nums.size();
		int left = 0;
		int right = len - 1;

		while (left <= right)
		{
			int mid = (left + right) >> 1;
			if (nums[mid] == target)
			{
				cout << "mid:" << mid << endl;
				return mid;
			}
			else
			{
				if (nums[left] == nums[mid])
				{
					left++;
				}
				else if (nums[left] < nums[mid])
				{
					if (target >= nums[left] && target <= nums[mid])
					{
						right = mid - 1;
					}
					else
					{
						left = mid + 1;
					}
				}
				else
				{
					if (target >= nums[mid] && target <= nums[right])
					{

						left = mid + 1;
					}
					else
					{
						right = mid - 1;
					}
				}
}
		}

		return -1;
	}
};
