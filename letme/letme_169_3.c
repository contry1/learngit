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

			/*	sort(nums.begin(), nums.end());
				return nums[len >> 1];*/
		int index = 0;
	loop:
		int many = nums[index];
		int cnt = 0;
		for (int i = 0; i < len; ++i)
		{
			if (nums[i] == many)
			{
				cnt++;
			}
			else
			{
				cnt--;
			}


		}

		if (cnt > 0)
		{
			return many;
		}

		else
		{
			index++;
			goto loop;
		}
		return many;
	}
};
