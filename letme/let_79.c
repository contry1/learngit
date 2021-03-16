	//题目意思，是相邻
	bool dfs(vector<vector<char>>& board, vector<vector<int>>visted,
		int i, int j, string& word, int k)
	{
		if (board[i][j] != word[k])
		{
			return false;//首字母不同，后缀子字符串一定不同，直接返回
		}
		else if (k == word.size() - 1)
			return true;
		visted[i][j] = true;
		int ret = false;
		int flag = 0;
		vector<pair<int, int>> dir = { {0,1 },{0,-1},{1,0},{-1,0} };
		for (const auto &d : dir)
		{
			int first = d.first+i;
			int second = d.second+j;
			if (first >= 0 && first < board.size() 
				&& second >= 0 && second < board[0].size())
			{
				if (!visted[first][second])
				{
					flag = dfs(board, visted, first, second, word, k + 1);
					if (flag)
					{
						ret = true;
						break;//找到一条通路，即返回
					}
				}
			}
		}
		visted[i][j] = false;
		return ret;
	}
	bool exist(vector<vector<char>>& board, string word)
	{
		int m = board.size();
		int n = board[0].size();
		vector<vector<int>>visted(m, vector<int>(n));
		int k = 0;
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				bool flag = dfs(board, visted,i, j, word, 0);
				if (flag == true)
					return true;
			}
		}
		return 	false;
	}
};
