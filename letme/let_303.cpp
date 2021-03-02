class NumArray_303 {
public:
	vector<int >num;
	NumArray(vector<int>& nums) {
		int m = matrix.size();
		if (m <= 0)
			return;

		num.resize(m+1);
		for (int i = 0; i < m; ++i)
		{
			num[i + 1] = num[i] + matrix[i];
		}
	}

	int sumRange(int i, int j) {
		int ans = 0;

		//for (int k = i; k <= j; ++k)
		{
			ans = num[j+1] - num[i];//每一行的之和
		}
		return ans;
	}
};
