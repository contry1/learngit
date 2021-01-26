class Solution_offer_62 {
public:
	//function1  russia farmer alg 
	int mul(int a, int b)
	{
		int ans = 0;
		while (b && a)
		{
			if (b & 1)
				ans += a;
			b >>= 1;
			a <<= 1;
		}
		return ans;
	}
	int sumNums(int n) 
	{
		return mul(n,n+1)>>1;
	}


	//function2  russia farmer alg 
	int mul(int a, int b)
	{
		int ans = 0;
		for(;b; b >>= 1)
		{
			if (b & 1)
				ans += a;
			
			a <<= 1;
		}
		return ans;
	}
	int sumNums(int n)
	{
		return mul(n, n + 1) >> 1;
	}


	//function3  russia farmer alg 
	int mul(int a, int b)
	{
		int ans = 0;
		while (b >=1)//第二个数减到1为止
		{
			if (b & 1)//奇数行才加，偶数行不加
				ans += a;
			b >>= 1;//第二个数每次缩小一倍
			a <<= 1;//第一个数每次扩大一倍
		}
		return ans;
	}
	int sumNums(int n)
	{
		return mul(n, n + 1) >> 1;
	}
};
