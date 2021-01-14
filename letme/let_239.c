class Solution_239 {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k)
	{
		int max_l = nums[0];
		vector<int> ans;
		vector<int> tmp;

		//start pos
		for (int j = 0; j < k; ++j)
		{
			max_l = max(max_l,nums[j]);
			tmp.push_back(nums[j]);
		}
		ans.push_back(max_l);

		//next
		
		for (int i = k; i < nums.size(); ++i)
		{
			int left = i - k;
		/*	tmp.erase(nums[left]);*/
			tmp.erase(tmp.begin());
			tmp.push_back(nums[i]);

			max_l = tmp[0];
			for (auto &ch:tmp)
			{
				max_l = max(max_l,ch);	
			}
			ans.push_back(max_l);
		}
		return ans;
	}


	vector<int> maxSlidingWindow2(vector<int>& nums, int k)
	{
		int max_l = nums[0];
		vector<int> ans;
		vector<int> tmp;

		//start pos
		for (int j = 0; j < k; ++j)
		{
			max_l = max(max_l, nums[j]);
			tmp.push_back(nums[j]);
		}
		ans.push_back(max_l);

		//next
		for (int i = k;i < nums.size(); ++i)
		{
		/*	tmp[i] = nums[i];*/
			tmp.push_back(nums[i]);
			for (int j = 0; j < k; ++j)
			{
				tmp[j] = tmp[j+1];
			}

			tmp.resize(k);//tmp.pop_back();
			max_l = tmp[0];
			for (auto &ch : tmp)
			{
				max_l = max(max_l, ch);
			}
			ans.push_back(max_l);
		}
		return ans;
	}
};
