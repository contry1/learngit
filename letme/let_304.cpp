class NumMatrix {
public:
vector< vector<int >> num;
	NumMatrix(vector<vector<int>>& matrix) {
		int m = matrix.size();
        if(m<=0)
            return;
        int n = matrix[0].size();
		num.resize(m, vector<int >(n+1));
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				num[i][j + 1] = num[i][j] + matrix[i][j];
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		int ans = 0;

		for (int i = row1; i <= row2; ++i)
		{
			ans += num[i][col2 + 1] - num[i][col1];//每一行的之和
		}
		return ans;
	}
};
