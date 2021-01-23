class Solution_73 {
public:
	//not ac
	void setZeroes(vector<vector<int>>& matrix)
	{
		int m = matrix.size();
		int n = matrix[0].size();

		int i_flag = -1;
		int j_flag = -1;

		int i_flag2 = -1;
		int j_flag2 = -1;
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (i == i_flag)
				{
					if (j_flag2 != -1)
					{
						//matrix[i][j] = 0;
					}
					else
					{
						continue;
					}
				}
					
				if (j == j_flag)
				{
					if (i_flag2 != -1)
					{
						//matrix[i][j] = 0;
					}
					else
					{
						continue;
					}
				}
					

				if (matrix[i][j] == 0)
				{
					i_flag = i;
					j_flag = j;
					for (int k = 0; k < m; ++k)
					{
						if (matrix[k][j] == 0 )//&& k!=i)
						{
							i_flag2 = k;
							matrix[k][j] = 0;
						}
						else
						{
							matrix[k][j] = 0;
						}
						
					}

					for (int l = 0; l < n; ++l)
					{
						if (matrix[i][l] == 0)//&&l!=j)
						{
							j_flag2 = j;
							matrix[i][l] = 0;
						}
						else
						{
							matrix[i][l] = 0;
						}
						
					}
				}
			}
		}

	}


	//官方题解1，先统计完所有为0的坐标，然后再更新
	void setZeroes2(vector<vector<int>>& matrix)
	{
		int m = matrix.size();
		int n = matrix[0].size();

		std::set<int> myset_m;
		std::set<int> myset_n;
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				
				if (matrix[i][j] == 0)
				{
					myset_m.emplace(i);
					myset_n.emplace(j);
				}
			}
		}


		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{

				if (myset_m.count(i) || myset_n.count(j))
				{
					matrix[i][j] = 0;
				}
			}
		}



		void setZeroes3(vector<vector<int>>& matrix) {
			int m = matrix.size();
			int n = matrix[0].size();

			for (int i = 0; i < m; ++i)
			{
				for (int j = 0; j < n; ++j)
				{

					if (matrix[i][j] == 0)
					{
						for (int k = 0; k < m; ++k)
						{
							if (matrix[k][j] != 0)
								matrix[k][j] = -100000000;

						}

						for (int l = 0; l < n; ++l)
						{
							if (matrix[i][l] != 0)
								matrix[i][l] = -100000000;

						}
					}
				}
			}


			for (int i = 0; i < m; ++i)
			{
				for (int j = 0; j < n; ++j)
				{

					if (matrix[i][j] == -100000000)
					{
						matrix[i][j] = 0;
					}
				}
			}

		}
	
};
