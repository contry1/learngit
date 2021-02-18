//哈希表，空间换时间，记录每一个位置出现的数，如果首次出现置一，第二次出现为1，那么返回false
class Solution_36 {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		int row[9][10] = {0};
		int col[9][10] = { 0 };
		int box[9][10] = { 0 };

		for (int i = 0; i < 9; ++i)
		{
			for (int j = 0; j < 9; ++j)
			{
				if (board[i][j] == '.')
					continue;
				int num = board[i][j] - '0';
				
				if (1 == row[i][num] || col[j][num] == 1||
					box[(i / 3) * 3 + j / 3][num] == 1)
					return false;

				row[i][num] = 1;
				col[j][num] = 1;
				box[(i / 3 )* 3 + j / 3][num] = 1;
			}
		}
		return  true;

	}
};
