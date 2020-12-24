class Solution_154 {
public:
	int findMin(vector<int>& nums) {
		int len = nums.size();
		int left = 0;
		int right = len - 1;

		if (nums[right] > nums[0])
			return nums[0];

		while (left < right)
		{
			int mid = (left + right) >> 1;


			if (nums[left] == nums[mid])
			{
				//nums[left] < nums[right]此时，left已经在一个单调递增的区间，最左侧，退出即可，不需要再次往右递增
				if (nums[left] < nums[right])
					break;
				left++;//这里为何不能是left == mid,因为如果这样，最后一个数可能会陷入死循环
			}
			else if (nums[left] < nums[mid])
			{
				if (nums[mid] <= nums[right])
				{
					//1.只有在一个单调递增的区间，才能确定最小值。 2.最小值为最左端值
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

					//return nums[mid];
					right = mid;
				}

			}

		}

		return nums[left];

	}
};
