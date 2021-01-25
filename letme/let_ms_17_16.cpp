class Solution_ms_17_16 {
public:
	//动态规划
	int massage(vector<int>& nums) 
	{
		int len = nums.size();
		if (len == 0)
			return 0;
		if (len < 2 &&len >0)
		{
			return nums[0];
		}
		if (len == 2)
		{
			return nums[0]>nums[1]?nums[0]:nums[1];
		}
		vector<int> dp(len,0);

		dp[0] = nums[0];
		dp[1] = nums[1];
		int ans = 0;

		//这个题目并未严格限制是相隔一个元素，如果是相隔一个元素，那么这葛做法没有问题
		/*for (int i = 2; i < len; ++i)
		{
			dp[i] = max(dp[i-2]+nums[i],dp[i-1]);
			ans = max(ans,dp[i]);
		}*/

		for (int i = 2; i < len; ++i)
		{
			for (int j = 0; j < i-1; ++j)
				dp[i] = max(dp[i], max(dp[j] + nums[i], dp[i - 1]));
			ans = max(ans, dp[i]);
		}
		return ans;

	}
};
