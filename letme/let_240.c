class Solution_240 {
public:
	//类似skip table
	bool searchMatrix(vector<vector<int>>& matrix, int target)
	{
		int n = matrix.size();
		int m = matrix[0].size();

		for (int i = 0; i < n; ++i)
		{
			if (target < matrix[i][0])
			{
				return false;
			}
			else if (matrix[i][0] <= target && target <= matrix[i][m-1])
			{
				int left = 0;
				int right = m - 1;
				while (left < right)
				{
					int mid = (left + right) >> 1;
					if (target == matrix[i][mid])
					{
						return true;
					}
					else if (target < matrix[i][mid])
					{
						right = mid - 1;
					}
					else 
					{
						left = mid + 1;
					}
				}

				if(target == matrix[i][left])
					return true;

			}
			else if (matrix[i][m - 1] < target)
			{
				continue;
			}
		
		}
		return false;

	}


	//类似skip table
	bool searchMatrix2(vector<vector<int>>& matrix, int target)
	{
		int n = matrix.size();
		int m = matrix[0].size();

		int x = n - 1;
		int y = 0;
		while (x >= 0 && y <= m-1)
		{
			if (matrix[x][y] > target)
			{
				x--;
			}
			else if (matrix[x][y] < target)
			{
				++y;
			}
			else
				return true;
		}
		return false;

	}
};
