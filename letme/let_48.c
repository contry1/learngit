class Solution {
public:
        void swap(int *a, int *b)
	{
		int c = *a;
		*a = *b;
		*b = c;
	}
    



	void rotate(vector<vector<int>>& matrix) 
	{
		int len = matrix.size();
	vector<vector<int>>mid(len, vector<int>(0));
		for (int i = 0; i < len; ++i)
		{
			for (int j= 0; j < len; ++j)
			{
				if (i == j)
				{
					matrix[i][j] = matrix[i][j];
				}
			    else if(i>j)
				{
					swap(&matrix[i][j], &matrix[j][i]);
					
				}
			}
		}


		for (int i = 0; i < len; ++i)
		{
			int right = len - 1;
			for (int j = 0; j < len; ++j)
			{
				if (j <= right)
				{
					swap(&matrix[i][j],&matrix[i][right]);
					right--;
				}
			}
		}

    }
};
