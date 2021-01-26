class Solution_offer_56_1 {
public:
	//x为一位数
	/*x & 1 = x, x & 0 = 0;
	x^0 = x, x^1 = ~x*/
	vector<int> singleNumbers(vector<int>& nums)
	{
		int ret = 0;
		vector<int> ans1;
		vector<int> ans2;
		for (auto &ch : nums)
		{
			ret ^= ch;
		}

		int div = 1;//div = 2 ,some option is not ac and will overfolw
		while ((div &ret) == 0)
			div <<= 1;

	
		int x = 0;
		int y = 0;
		for (auto &ch : nums)
		{
			if ((ch &div) == 0)
				x ^= ch;
			else
				y ^= ch;
		}

		
		
		return 	vector<int>{x,y};
	}
};
