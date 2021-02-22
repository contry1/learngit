class Solution_766 {
public:
	bool isToeplitzMatrix(vector<vector<int>>& matrix) 
	{
		int m = matrix.size();
		int n = matrix[0].size();

		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (i == m - 1 || j == n - 1)
					continue;
				if (matrix[i][j] == matrix[i + 1][j + 1])
					continue;
				else
					return false;
			
			}
		}

		return true;

	}
};
