class Solution_offer_47 {
public:
	int maxValue(vector<vector<int>>& grid) 
	{
		int m = grid.size();
		int n = grid[0].size();

		vector<vector<int>>dp(m, vector<int>(n, 0));
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				//走方格问题，难得就是对于临界点的取值进行判断
				//记住下面几个要素，原点，x,y,对角线
				if (i == 0 && j == 0)
					dp[i][j] = grid[i][j];
				else if (i == 0 && j > 0)
					dp[i][j] = dp[i][j-1] + grid[i][j];
				else if (j == 0 && i > 0)
					dp[i][j] = dp[i-1][j] + grid[i][j];
				else
					dp[i][j] = max(dp[i-1][j]+grid[i][j], dp[i][j-1] + grid[i][j]);
			}
		}

		return dp[m-1][n-1];

	}
};
