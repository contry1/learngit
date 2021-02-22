class Solution_1438 {
public:
	//functin1   timeout ,because  we calculate the max or min every time
	int longestSubarray1(vector<int>& nums, int limit) 
	{
		int len = nums.size();
		if (len == 0)
			return 0;
		if (len == 1)
		{
			if (limit >= 0)
				return 1;
			else
				return 0;
		}
		int max_num = nums[0];
		int min_num = nums[0];

		int sec_a = 0;
		int sec_i = 0;

		int right = 0;
		int left = 0;

		int ans = 0;
		while (right < len - 1)
		{
			while (right < len - 1 && (max_num - min_num) <= limit)
			{
				right++;
				max_num = max(nums[right], max_num);
				min_num = min(nums[right], min_num);
			}


			// cout << right << "\t"<<left<<endl;
			if ((max_num - min_num) <= limit)
				ans = max(ans, right - left + 1);
			else
				ans = max(ans, right - left);
			left++;
			right = left;
			max_num = nums[left];
			min_num = nums[left];

		}

		return ans;
	}

	//滑动窗口的关键在于取得子数组的最小值和最大值
	//我们可以利用map mulset 等自动排序的
	int longestSubarray2(vector<int>& nums, int limit)
	{
		int len = nums.size();
		map<int, int>mp;
		if (len == 0)
			return 0;
		if (len == 1)
		{
			if (limit >= 0)
				return 1;
			else
				return 0;
		}
		
		int ans = 0;
		int j = 0;
		for (int i = 0; i < len; ++i)
		{
			++mp[nums[i]];
			while (mp.rbegin()->first - mp.begin()->first > limit)
			{
				mp[nums[j]]--;
				if (0 == mp[nums[j]])
				{
					mp.erase(nums[j]);
				}
				j++;
			}
			ans = max(ans,i-j-1);

		}

		return ans;
	}

	//这个一般的滑动窗口有区别，我们有两个指标
	//一个是源数组的下标j,另外一个就是sort map的下标mp.begin()
	int longestSubarray3(vector<int>& nums, int limit) {
		int len = nums.size();
		map<int, int>mp;
		int ans = 0;
		int j = 0;
		for (int i = 0; i < len; ++i)
		{
			++mp[nums[i]];
			while (mp.rbegin()->first - mp.begin()->first > limit)
			{
				mp[nums[j]]--;
				if (0 == mp[nums[j]])
				{
					mp.erase(nums[j]);
				}
				j++;
			}
			ans = max(ans, i - j + 1);

		}
		return ans;
	}
};
