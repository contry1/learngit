class Solution_1688 {
public:
	int cnt = 0;
	int numberOfMatches(int n) {
		int tmp;
		if (1 == n)
			return cnt;
		if (n % 2)
		{
			tmp = n >> 1;
			cnt += tmp;
			return numberOfMatches(tmp + 1);
		}
		else
		{
			tmp = n >> 1;
			cnt += tmp;
			return numberOfMatches(tmp);
		}
		
	}


	//FUCNTION2
	void dfs(int n, int &ans)
	{
		int tmp;
		if (1 == n)
			return ;
		if (n % 2)//	if ((n &0x1)^1 == 0) //if ((n &0x1)^0) 
		{
			tmp = n >> 1;
			ans += tmp;
			dfs(tmp + 1,ans);
		}
		else
		{
			tmp = n >> 1;
			ans+= tmp;
			 dfs(tmp,ans);
		}
	}

	int numberOfMatches(int n) {
		int ans = 0;
		dfs(n,ans);
		return ans;
	}
};
