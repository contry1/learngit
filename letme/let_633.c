class Solution_633 {
public:
	bool get_left(long start,long end,int k) {
		while (start <= end)
		{
			long m = (start + end) >> 1;
			if (m*m == k)
				return true;
			/*else if (m*m > k)
			{
				end--;
			}
			else
			{
				start++;
			}*/
			//这里的二分法和双指针搞混淆了！！！二分的步进为区间的一半，双指针每次一个单位
			else if (m*m > k)
			{
				end = m - 1;
			}
			else
			{
				start = m + 1;
			}
		}
		return false;

	}
	bool judgeSquareSum(int c) {
		if (c < 2)
			return true;
		
		for (long i = 0; i *i<= c; ++i)
		{
			int j = (int)(c - i * i);
			if (get_left(0, j, j) == true)//不能直接返回，必须等到遍历完所有的i,或者已经是true了，才可以直接返回
			{
				return true;
			}
		}

		return false;
	}
};
