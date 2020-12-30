class Solution_16 {
public:
	int threeSumClosest1(vector<int>& nums, int target) {
		sort(nums.begin(),nums.end());
		int best = 1e7;
		for (int i = 0; i < nums.size()-2; ++i)
		{
			int l = i + 1;
			int r = nums.size() - 1;
			while (l<r)
			{
				int sum = nums[i] + nums[l] + nums[r];
				cout << "l:  r:" << l<<r << endl;
				if (target == sum)
				{
					return target;
				}

				if (abs(sum - target) <= abs(best - target))
				{
					best = sum;
		
				}
				

				if (sum > target)
				{
					--r;
				}
				if (sum < target)
				{
					++l;
				}
			}
		}

		return best;
	}

	//2.two point func
	int threeSumClosest2(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int best = 1e7;
		for (int i = 0; i < nums.size() - 2; ++i)
		{
			//1.优化1
			if (i >= 1 && nums[i] == nums[i - 1])
			{
				continue;
			}

			int l = i + 1;
			int r = nums.size() - 1;
			while (l < r)
			{
				int sum = nums[i] + nums[l] + nums[r];
				cout << "l:  r:" << l << r << endl;
				if (target == sum)
				{
					return target;
				}

				if (abs(sum - target) <= abs(best - target))
				{
					best = sum;
		
				}

				if (sum > target)
				{
					--r;
					//2.优化去除重复左端
					while (r > l && nums[r] == nums[r + 1])
					{
						r--;

					}
				}

				if (sum < target)
				{
					++l;
					//3.优化去除重复右端
					while (l < r && nums[l] == nums[l - 1])
					{
						l++;

					}
				}

				if (sum > target)
				{
					--r;
					//2.优化去除重复左端
					while (r > l && nums[r] == nums[r + 1])
					{
						r--;

					}
				}

				
				

			}
		}

		return best;
	}
};
