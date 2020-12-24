class solution_153 {
public:
	//function 1
	//如果数组有旋转，则：
	//1.所有变化点左侧元素 >= 数组第一个元素  =>变化点右侧元素 的最小元素>= 数组第一个元素 => a[0] == a[0]
	//2.所有变化点右侧元素 < 数组第一个元素  =>变化点右侧元素 的最大元素< 数组第一个元素   => a[right]<a[0]
	//有重复数组依然满足，2加上等号
	int get_left_index(vector<int> &nums)
	{
		int len = nums.size();
		int left = 0;
		int right = len - 1;

		while (left <= right)
		{
			int mid = (left + right) >> 1;


			if (nums[left] <= nums[mid])
			{
				if (nums[left] <= nums[mid] && nums[mid] <= nums[right])
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
				if (nums[right] >= nums[mid] && nums[mid] < nums[left])
				{

					//return nums[mid];
					right = mid;
				}
				else
				{
					right = mid - 1;
				}
			}

		}

		return -1;
	}

	//function 2
	int get_left_index2(vector<int> &nums)
	{
		int len = nums.size();
		int left = 0;
		int right = len - 1;

		while (left < right)
		{
			int mid = (left + right) >> 1;

			//这里的==必须要加的。
			if (nums[left] <= nums[mid])
			{
				if (nums[left] <= nums[mid] && nums[mid] <= nums[right])
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
				if (nums[right] >= nums[mid] && nums[mid] < nums[left])
				{

					//return nums[mid];
					right = mid;
				}
				/*else
				{
					right = mid - 1;
				}*/
				//line 1389 - 1392 is no used,so it deleted
			}

		}

		return nums[left];
	}

	//function 3
	int get_left_index3(vector<int> &nums)
	{
		int len = nums.size();
		int left = 0;
		int right = len - 1;

		while (left < right)
		{
			int mid = (left + right) >> 1;


			if (nums[left] <= nums[mid])
			{
				if (nums[mid] <= nums[right])//nums[left] <= nums[mid] &&
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
				if (nums[right] >= nums[mid])//&& nums[mid]< nums[left]
				{

					right = mid;
				}

			}


		}
		return nums[left];
	}


	//function 4
	int get_left_index4(vector<int> &nums)
	{
		int len = nums.size();
		int left = 0;
		int right = len - 1;

		while (left < right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] >= nums[right])//说明mid之前都是旋转的，最小值只会出现在mid右侧。不会出现，2，7,3之类的
			{
				left = mid + 1;
			}
			else 
			{
				right = mid;
			}
		}
		return nums[left];
		
	}

	//function 5
	int findMin(vector<int>& nums) {
		int len = nums.size();
		int left = 0;
		int right = len - 1;

		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (mid == right) {
				return nums[left];
			}
			if (nums[mid] > nums[right]) {
				//根据旋转数组性质，由nums[mid] > nums[right] ,
			//推出数组是有经过旋转的，即nums[0] > nums[right]，而且nums[mid] > nums[0]，所以就有第6中function
				left = mid + 1;
			}
			else {
				right = mid;
			}
		}
		return -1;

	}

	//function 6
	int findMin2(vector<int>& nums) {
		int len = nums.size();
		int left = 0;
		int right = len - 1;

		if (nums[right] > nums[0])
			return nums[0];

		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (mid == right) {
				return nums[left];
			}
			if (nums[mid] >= nums[0]) {
				left = mid + 1;
			}
			else {
				right = mid;
			}
		}
		return -1;

	}

	//function 7

	int findMin3(vector<int>& nums) {
		int len = nums.size();
		int left = 0;
		int right = len - 1;

		if (nums[right] > nums[0])
			return nums[0];

		while (left < right) {
			int mid = left + (right - left) / 2;

			if (nums[mid] >= nums[0]) {
				left = mid + 1;
			}
			else {
				right = mid;
			}
		}
		return nums[left];

	}

};
