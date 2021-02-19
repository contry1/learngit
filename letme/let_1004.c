class Solution_1001 {
public:
	int longestOnes(vector<int>& A, int K) {
		int len = A.size();
		int left = 0;
		int right = 0;
		int ans = 0;

		vector<int>vec;
		while (left < len)
		{
			vec[right]=A[right];
			right++;

			if (right - left >vec.size()+ K)
			{
				vec[left]--;//pop the leftest value
				vec.erase(vec.begin()+left);
				left++;
			}
			else
			{
				ans++;
			}
		}

		return ans;

	}
};


not    ac


