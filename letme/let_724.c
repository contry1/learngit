class Solution_724 {
public:
	//fucntuon 1 timeout last not ac
	int dfs(vector<int>&nums, int mid)
	{
		if (mid > nums.size() - 1)
			return -1;
		int left = 0;
		int right = 0;
		for (int i = 0; i < mid; ++i)
			left += nums[i];
		for (int j = mid+1; j <= nums.size()-1; ++j)
			right += nums[j];
		if (left == right)
			return mid;
		else
			return dfs(nums,mid+1);
	
	}
	int pivotIndex(vector<int>& nums)
	{
		if (nums.size() < 3)
			return -1;
		return dfs(nums,0);

	}


	//fucntuon 2 ac 100%.exceed 5%
	int dfs(vector<int>&nums, int mid,int cnt)
	{
		if (mid > nums.size() - 1)
			return -1;
		int left = 0;
		int right = 0;
		for (int i = 0; i < mid; ++i)
			left += nums[i];
		
		if (left == cnt-left-nums[mid])
			return mid;
		else
			return dfs(nums, mid + 1,cnt);

	}
	int pivotIndex(vector<int>& nums)
	{
		if (nums.size() < 3)
			return -1;
		int cnt = 0;
		for (auto &ch : nums)
			cnt += ch;
		return dfs(nums, 0,cnt);

	}



	//fucntuon 3 ac 100%.exceed 5%
	int dfs3(vector<int>&nums, int mid, int cnt,int flag)
	{
		if (mid > nums.size() - 1)
			return -1;
		int left = 0;
		int right = 0;

		if (flag == 0)
		{
			while (nums[mid] % 2 == 1 && mid <= nums.size() - 1)
				++mid;
		}
		else
		{
			while (nums[mid] % 2 == 0 && mid <= nums.size() - 1)
				++mid;
		}
		for (int i = 0; i < mid; ++i)
			left += nums[i];

		if (left == cnt - left - nums[mid])
			return mid;
		else
			return dfs3(nums, mid + 1,cnt,flag);

	}
	int pivotIndex(vector<int>& nums)
	{
		if (nums.size() < 3)
			return -1;
		int cnt = 0;
		for (auto &ch : nums)
			cnt += ch;
		int flag = (cnt & 1) ^ 0;//0,偶数，1奇数
		return dfs3(nums, 0, cnt,flag);

	}


	//fucntuon 4 not ac
	int dfs4(vector<int>&nums, int cnt, unordered_multimap<int, int>&odd)
	{
		
		int left = 0;
		for (auto &ch : odd)
		{
			for (int i = 0; i < ch.second; ++i)
				left += nums[i];

			if (left == cnt - left - ch.first)
				return ch.second;
	
		}
		return -1;
		

	}
	int pivotIndex(vector<int>& nums)
	{
		if (nums.size() < 3)
			return -1;
		int cnt = 0;
		unordered_multimap<int, int>odd;
		unordered_multimap<int, int>even;//偶数
		int i = 0;
		for (auto &ch : nums)
		{
			if ((ch & 1) ^ 0 == 0)
			{
				even.emplace(ch,i);
			}
			else
			{
				odd.emplace(ch, i);
			}
			cnt += ch;
			i++;
		}
			
		int flag = (cnt & 1) ^ 0;//0,偶数，1奇数
		if(flag == 0)
			return dfs4(nums, cnt, even);
		else
			return dfs4(nums, cnt,  odd);

	}
};
