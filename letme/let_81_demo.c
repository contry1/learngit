class solution_81 {
public:

	bool  get_left_index(vector<int> &nums, int target)
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
				return true;
			}
			else
			{
				if (nums[left] == nums[mid])
				{
					left++;
				}
				else if (nums[left] < nums[mid])
				{
					if (target >= nums[left] && target < nums[mid])
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
					if (target > nums[mid] && target <= nums[right])
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

		return false;
	}

	bool  get_left_index2(vector<int> &nums, int target)
	{
		int len = nums.size();
		if (len == 0)
			return false;
		int left = 0;
		int right = len - 1;

		//这里要不要加等于号，要判断两点。
		//1.加上之后，是否会死循环
		//2.是否有元素被skip过
		while (left < right)
		{
			int mid = (left + right) >> 1;
			if (nums[mid] == target)
			{
				cout << "mid:" << mid << endl;
				return true;
			}
			else
			{
				if (nums[left] == nums[mid])
				{
					left++;
				}
				else if (nums[left] < nums[mid])
				{
					if (target >= nums[left] && target < nums[mid])
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
					if (target > nums[mid] && target <= nums[right])
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

		//最后一个数left == right判断一下和目标的大小
		return nums[left] == target;
	}
};
