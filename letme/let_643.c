class Solution_643 {
public:
	double findMaxAverage(vector<int>& nums, int k) 
	{
		int sum = 0;
		int ans = 0;

		for (int i = 0; i < k; ++i)
		{
			sum += nums[i];
		}
		ans = sum ;

		for (int i = k; i < nums.size(); ++i)
		{
			sum -= nums[i - k];
			sum += nums[i];
			ans = max(ans,sum);
		}

		return (double)ans / k;

	}

	//use queue come true slip windows
	double findMaxAverage2(vector<int>& nums, int k)
	{
		int sum = 0;
		int ans = 0;
		std::queue<int>qsum;
		for (int i = 0; i < k; ++i)
		{
			qsum.push(nums[i]);
			sum += nums[i];
		}
		ans = sum;
		for (int i = k; i < nums.size(); ++i)
		{
			sum += nums[i] - qsum.front();
			ans = max(ans, sum);

			qsum.pop();
			qsum.push(nums[i]);
		}
		return (double)ans / k;
	}

	//use  dongtai guihau
	double findMaxAverage3(vector<int>& nums, int k)
	{
		int sum = 0;
		int ans = 0;
		std::vector<int>dp(nums.size());
		for (int i = 0; i < k; ++i)
		{
			sum += nums[i];
		}
		dp[k-1] = sum;
		ans = sum;
		for (int i = k; i < nums.size(); ++i)
		{
			dp[i] = dp[i - 1] + nums[i] - nums[i - k];
			ans = max(ans,dp[i]);
		
		}
		return (double)ans / k;
	}
};
