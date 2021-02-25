class Solution_984 {
public:
	//function1 贪心法 
	/*1.每次从个数最多的那一个开始排，第一次排2个，然后排下一个字母一个。
	2.然后统计剩余字母个数，如果剩余字母个数不同，下一步走第一步。如果相同，那么交替排列1个即可。*/
	string strWithout3a3b(int a, int b)
	{
		string ans;
		//1.如果长度之和没有超过3个字节，随便组合
		if (a + b <= 3)
		{
			ans.assign(a, 'a');
			ans = ans.append(b, 'b');
		}
		else
		{
			while (a || b)
			{
				//1.先放多的
				if (a > b)//a>=3
				{
						if (a >= 2)
						{
							ans = ans.append(2, 'a');
							a -= 2;
						}
						else
						{
							ans = ans.append(a, 'a');
							a -= a;
						}
						if (b >= 1)
						{
							ans = ans.append(1, 'b');
							b -= 1;
						}

						else
						{
							ans = ans.append(b, 'b');
							b -= b;
						}
				}
				else if (a < b)
				{
						if (b >= 2)
						{
							ans = ans.append(2, 'b');
							b -= 2;
						}

						else
						{
							ans = ans.append(b, 'b');
							b -= b;
						}

						if (a >= 1)
						{
							ans = ans.append(1, 'a');
							a -= 1;
						}
						else
						{
							ans = ans.append(a, 'a');
							a -= a;
						}
				}
				else if (a == b)
				{
						if (b >= 1)
						{
							ans = ans.append(1, 'b');
							b -= 1;
						}

						else
						{
							ans = ans.append(b, 'b');
							b -= b;
						}

						if (a >= 1)
						{
							ans = ans.append(1, 'a');
							a -= 1;
						}
						else
						{
							ans = ans.append(a, 'a');
							a -= a;
						}
				}
			
			}
		}
		return ans;
	}


	//优化之后
	string strWithout3a3b(int a, int b) {
		string ans;
		while (a || b)
		{
			//1.先放多的
			if (a > b)//a>=3
			{

				if (a >= 2)
				{
					ans = ans.append(2, 'a');
					a -= 2;
				}
				else
				{
					ans = ans.append(a, 'a');
					break;
				}


				if (b >= 1)
				{
					ans = ans.append(1, 'b');
					b -= 1;
				}

				else
				{
					ans = ans.append(b, 'b');
					break;
				}
			}
			else if (a < b)
			{

				if (b >= 2)
				{
					ans = ans.append(2, 'b');
					b -= 2;
				}

				else
				{
					ans = ans.append(b, 'b');
					break;
				}

				if (a >= 1)
				{
					ans = ans.append(1, 'a');
					a -= 1;
				}
				else
				{
					ans = ans.append(a, 'a');
					break;
				}
			}
			else if (a == b)
			{

				if (b >= 1)
				{
					ans = ans.append(1, 'b');
					b -= 1;
				}
				else
				{
					ans = ans.append(b, 'b');
					break;
				}

				if (a >= 1)
				{
					ans = ans.append(1, 'a');
					a -= 1;
				}
				else
				{
					ans = ans.append(a, 'a');
					break;
				}
			}

		}
	}
	return ans;
	}
};
