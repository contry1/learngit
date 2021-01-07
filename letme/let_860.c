class Solution_860 {
public:
	bool lemonadeChange(vector<int>& bills) {
		//sort(bills.begin(), bills.end());//顺序会影响结果，所以这里不能排序
		int a = 0;
		int b = 0;
		int	c = 0;

		for (int i = 0; i < bills.size(); ++i)
		{
			if (bills[i] == 5)
				a++;
			else if (bills[i] == 10)
			{
				b++;//遗漏点
				if (a <= 0)
					return false;
				a--;

			}
			else if (bills[i] == 20)
			{
				if (b>0)
				{
					b--;
					if (a <= 0)
						return false;
					a--;
				}
				else
				{
					if (a <3)
						return false;
					a -= 3;
				}
			}
		}

		return true;

	}
};
