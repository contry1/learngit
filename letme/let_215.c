class Solution_215 {
public:
	int findKthLargest(vector<int>& nums, int k)
	{
		int len = nums.size();
	

		unordered_map<int, int>mp;
		for (auto &ch : nums)
			mp[ch]++;

		auto cmp = [](pair<int, int>&a, pair<int, int>&b) {return a.first > b.first; };
		priority_queue<pair<int, int>,vector<pair<int, int>>,decltype(cmp)> q(cmp);
		
		
		for (auto &ch : mp)
		{
			q.emplace(ch);
		}
		
		int ret = 0;
		while (!q.empty())
		{
		
			k -= q.top().second;
			if (0 >= k)
			{
				ret = q.top().first;
				break;
			}
			q.pop();
		}

		return ret;
	}

	//not ac
	int findKthLargest2(vector<int>& nums, int k)
	{
		int len = nums.size();
		unordered_map<int, int>mp;
		for (auto &ch : nums)
			mp[ch]++;

		auto cmp = [](pair<int, int>&a, pair<int, int>&b) {return a.first < b.first; };
		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);

		
		for (auto &ch : mp)
		{
			//最多k个数
			if (q.size() == k)
			{
				if (q.top().first < ch.first)
				{
					q.pop();
					q.emplace(ch);
				}
			}
			else
			{
				q.emplace(ch);
			}
		
		}

		int ret = 0;
		while (!q.empty())
		{

			k -= q.top().second;
			if (0 >= k)
			{
				ret = q.top().first;
				break;
			}
			q.pop();
		}
		return ret;
	}

	//function 3
	static bool cmp(int &a, int&b)
	{
		return a > b;
	}
	int findKthLargest2(vector<int>& nums, int k)
	{
		int len = nums.size();
		sort(nums.begin(), nums.end(), cmp);
		int ret = 0;

#if 0
		for (auto &ch : nums)
		{
			k--;
			if (0 == k)
			{
				ret = ch;
				break;
			}
				
		}
		return ret;
#else
		return nums[k - 1];
#endif
	}


	//function 4 匿名cmp
	int findKthLargest2(vector<int>& nums, int k)
	{
		int len = nums.size();

		auto cmp2 = [](int &a, int&b)
		{
			return a > b;
		};
		sort(nums.begin(), nums.end(), cmp2);
		int ret = 0;

#if 0
		for (auto &ch : nums)
		{
			k--;
			if (0 == k)
			{
				ret = ch;
				break;
			}

		}
		return ret;
#else
		return nums[k - 1];
#endif
	}


	//function 5 lamda
	int findKthLargest2(vector<int>& nums, int k)
	{
		int len = nums.size();
		sort(nums.begin(), nums.end(), [](int &a, int&b)
		{return a > b;});
		int ret = 0;

#if 0
		for (auto &ch : nums)
		{
			k--;
			if (0 == k)
			{
				ret = ch;
				break;
			}

		}
		return ret;
#else
		return nums[k - 1];
#endif
	}

	//function 6 qsort
	void qsort(vector<int>& nums, int left, int right, int k ,int &ret)
	{
		if (left + 1 >= right)
		{
			if (k == right + 1)
				ret = nums[left];//5,6
			
			return;
		}
			
		int a = left;
		int b = right - 1;
		int key = nums[rand() % (right - left)];

		while (a < b)
		{
			while (a < b && nums[b] >= key)
				--b;
			nums[a] = nums[b];
			while (a < b && nums[a] <= key)
				++a;
			nums[b] = nums[a];
		}
		nums[a] = key;
		if (a == k-1)
		{
			ret = nums[a];
			return;
		}
		else if (a > k - 1)
		{
			qsort(nums, left, a, k,ret);
		}
		else
		{
			qsort( nums, a+1, right, k,ret);
		}
	}

	int findKthLargest2(vector<int>& nums, int k)
	{
		int len = nums.size();
		int ret = 0;
		qsort(nums, 0, nums.size(), k,ret);
		return ret;
	
	}
};
