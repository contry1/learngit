class solution_33{
public:
	
	int get_left_index(vector<int> &nums,int target)
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
				//nums[0] use nums[left]?
				if (nums[0] < nums[mid])
				{
					//说明前半段递增的，我们先假定在这个区间
					if (target >= nums[0] && target <= nums[mid])
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
					//说明mid往后半段递增的，我们先假定在这个区间
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
