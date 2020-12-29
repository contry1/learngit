//1.function backtrack  timeout
	int get_left_index(int m, int n)
	{
		if (m == 1 && n == 1)
			return 1;
		if (m == 0 || n == 0)
			return 0;

		return get_left_index(m-1,n) + get_left_index(m,n-1);
	}


	//2.function dp ac

	int get_left_index4(int m, int n)
	{
	
		vector<vector<int>> nums(m, vector<int>(n, 0));
	

		int i;
		int j;
		/*for ( i = 1,  j = 1; i <= m, j <= n; ++i, ++j)
		{
			nums[i][j] = nums[i - 1][j] + nums[i][j - 1];
		}*/
		for (i = 0; i < m; ++i)
		{
			for ( j = 0; j < n;  ++j)
			{
				if (i == 0 && j == 0)
				{
					nums[i][j] = 1;
					cout << "ans.size():" << endl;
				}
				else if (i == 0 )
				{
					nums[i][j] = 1;// nums[i][j - 1];

				}
				else if ( j == 0)
				{
					nums[i][j] = 1;// nums[i - 1][j];

				}
				else
				{
					nums[i][j] = nums[i - 1][j] + nums[i][j - 1];

				}
		
			}
		
		}
		return nums[m-1][n-1];
	}
