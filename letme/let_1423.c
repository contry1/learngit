class Solution_1423 {
public:
	//反向思维，求解滑动窗口的最小值 动态规划
	int get_left(vector<int>& cardPoints, int n)
	{
		int len = cardPoints.size();
		std::vector<int>dp(len);
		int sum = 0;
		for (int i = 0; i < n; ++i)
		{
			sum += cardPoints[i];
		}
		int ans = 0;
		if (n > 0)
		{
			dp[n - 1] = sum;
			ans = sum;
			for (int i = n; i < len; ++i)
			{
				dp[i] = dp[i - 1] + cardPoints[i] - cardPoints[i - n];
				ans = min(ans, dp[i]);
			}
		}
		return ans;
	}

	int maxScore(vector<int>& cardPoints, int k)
	{
		int len = cardPoints.size();
		int sum = 0;
		for (auto &ch : cardPoints)
		{
			sum += ch;
		}
		return sum - get_left(cardPoints, len - k);
	}

	//function2 slip windows 
	int get_left2(vector<int>& cardPoints, int n)
	{
		int len = cardPoints.size();
		int sum = 0;
		for (int i = 0; i < n; ++i)
		{
			sum += cardPoints[i];
		}
		int ans = 0;
		if (n > 0)
		{
			ans = sum;
			for (int i = n; i < len; ++i)
			{
				sum = sum + cardPoints[i] - cardPoints[i - n];
				ans = min(ans, sum);
			}
		}
		return ans;
	}

	int maxScore2(vector<int>& cardPoints, int k)
	{
		int len = cardPoints.size();
		int sum = 0;
		for (auto &ch : cardPoints)
		{
			sum += ch;
		}
		return sum - get_left2(cardPoints, len - k);
	}
};
