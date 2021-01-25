class Solution_ms_16_17 {
public:
	//funvtion1
	int maxSubArray1(vector<int>& nums)
	{
		int len = nums.size();
		vector<int>dp(len+1,0);

		int ans = nums[0];
		dp[0] = nums[0];
		for (int i = 1; i < len; ++i)
		{	
			//must contained the current ori i
			dp[i] = max(dp[i - 1] + nums[i], nums[i]);
			ans = max(ans, dp[i]);
		}
		return ans;
	}


	//function2
	int maxSubArray2(vector<int>& nums)
	{
		int len = nums.size();
		vector<int>dp(len + 1, 0);

		int ans = nums[0];
		dp[0] = nums[0];
		for (int i = 1; i < len; ++i)
		{
			//must contained the current ori i
			//there is DP[I-1] ,not is nums[i-1]. as of the DP[I-1] is 
			//contained the all before nums. such as
			/*
				i   0  1   2   3  4  5  6  7   8
		nums[i]    -2, 1 ,-3 , 4,-1 ,2 ,1 ,-5 ,4
		dp[i]	   -2  1  -2   4  3  5  6   -1 4 //use DP[I-1]
		dp[i]	   -2  1  -2   4  3  2  3   -2 4 //use nums[i-1]
			*/
			if(dp[i-1]<0)//if(nums[i-1]<0)
				dp[i] =  nums[i];
			else
				dp[i] = dp[i - 1] + nums[i];
			ans = max(ans, dp[i]);
		}
		return ans;
	}


	
};
