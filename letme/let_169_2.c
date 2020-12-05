class solution_169 {
public:

	int get_many(vector<int> nums)
	{
		int len = nums.size();
	/*	unordered_map<int, int>mp;
		for (int &ch : nums)
		{
			mp[ch]++;
			if (mp[ch] > len >> 1)
				return ch;
		}*/

		sort(nums.begin(), nums.end());
		return nums[len >> 1];
		
	}
};
