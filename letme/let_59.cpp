class Solution_59 {
public:
	vector<vector<int>> generateMatrix(int n) 
	{
		//vector<vector<int>>ans; failed ,must be push_back
		vector<vector<int>>ans(n, vector<int>(n,0));
		vector<int>ret;

		int total = n * n;
		int num = 1;
		int top = 0;
		int bot = n - 1;
		int left = 0;
		int right = n - 1;

		while (num <= total)
		{
			for (int i = left; i <= right; ++i)
			{
				ans[top][i] = num++;
			}
			top++;

			for (int i = top; i <= bot; ++i)
			{
				ans[i][right] = num++;
			}
			right--;

			for (int i = right; i >= left; --i)
			{
				ans[bot][i] = num++;
			}
			bot--;

			for (int i = bot; i >= top; --i)
			{
				ans[i][left] = num++;
			}
			left++;

		}
		return ans;
	}
};
