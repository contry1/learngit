class solution_64 {
public:
	//1.function backtrack  timeout
	int get_left_index(vector<vector<int>> &dp)
	{
		int m = dp.size();
		int n = dp[0].size();
		vector<vector<int>> nums(m, vector<int>(n, 0));
		int i;
		int j;
		
		for (i = 0; i < m; ++i)
		{
			for (j = 0; j < n; ++j)
			{
				if (i == 0 && j == 0)
				{
					nums[i][j] =dp[i][j];//第一个元素值
					cout << "ans.size():" << endl;
				}
				else if (i == 0)
				{
					//x水平位置
					nums[i][j] = nums[i][j - 1] + dp[i][j];//1;// nums[i][j - 1];
				}
				else if (j == 0)
				{
					//y位置
					nums[i][j] = nums[i - 1][j] + dp[i][j];//1;// nums[i - 1][j];
				}
				else
				{
					nums[i][j] = min(nums[i - 1][j] , nums[i][j - 1]) + dp[i][j];//要么是左边，要么是上边存在最小值
				}

			}

		}
		return nums[m - 1][n - 1];
	}
};
