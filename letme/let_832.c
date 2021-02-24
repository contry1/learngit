class Solution_832 {
public:
	void swap(int &a, int &b)
	{
		int c = a;
		a = b;
		b = c;
	
	}
	vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) 
	{
		int m = A.size();
		int n = A[0].size();

		
		int left = 0;
		int right = n-1;
		for (int i = 0; i < m; ++i)
		{
			//for (int j = 0; j < n; ++j)
			while(left<right)
			{
				swap(A[i][left], A[i][right]);
				left++;
				right--;
			}
			 left = 0;
			 right = n - 1;
		}

#if 0	
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				//ans.push_back(A[i][j]^1);
				A[i][j] ^= 1;
			}
			
		}
		return A;
#else
		vector<vector<int>>ans;
		vector<int>num;
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				num.push_back(A[i][j]^1);
			
			}
			ans.push_back(num);
			num.clear();
		}
		
//或者第三个方法
	/*	vector<vector<int>>ans(m, vector<int>(n,1));
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				ans[i][j] = A[i][j] ^ ans[i][j];

			}
			
		}*/
		return ans;
#endif
	}
};
