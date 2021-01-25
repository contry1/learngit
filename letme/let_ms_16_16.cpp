class Solution_ms_16_16 {
public:
	//double piont
	vector<int> subSort1(vector<int>& array)
	{
		int len = array.size();
		if (len == 0)
			return vector<int>{-1,-1};

		//思路1:n我们要寻找的是一个局部最大值,我们名为p，而且这个最大值右边一定要求存在小于他的值y，
		//我们要找的就是这个值y，而且是离他最远的那一个
		int p = array[0];
		//1.这里赋值为-1，避免我们循环之后再次进行判断
		int r = -1;
		for (int i = 1; i < len; ++i)
		{
			//2.这里要加=，因为我们要求的是最小区间
			if (p <= array[i])
				p = array[i];
			else
				r = i;

		}

		//思路2:m我们要寻找的是一个局部最小值,我们名为q，而且这个最小值右边一定要求存在大于他的值x，
		//我们要找的就是这个值x，而且是离他最远的那一个
		int q = array[len-1];
		//1.这里赋值为-1，避免我们循环之后再次进行判断
		int l = -1;

		for (int i = len-2; i >=0; --i)
		{
			//2.这里要加=，因为我们要求的是最小区间
			if (p >= array[i])
				p = array[i];
			else
				l = i;

		}
		return vector<int>{l,r};
		
	}

	//第二种方法，记录下当前值的index，存map。
	//然后sort，从两端寻找index不相同的两个值最小最大。 not ac
	vector<int> subSort2(vector<int>& array)
	{
		//int len = array.size();
		//if (len == 0)
		//	return vector<int>{-1, -1};
		//unordered_multimap<int,int> map;
		//for (int i = 0; i < len; ++i)
		//{
		//	map.emplace(i,array[i]);
		//}

		//auto cmp = [](pair<int, int>a, pair<int, int>b) {return a.second > b.second; };
		//sort(map.begin(),map.end(),cmp);

		//int before = -1;
		//int after = -1;
		//for (auto &ch : map)
		//{
		//	if (ch.first - before == 1)
		//	{
		//		before = ch.first;
		//	}
		//	else
		//	{
		//		break;
		//	}		
		//}


		//int p = array[0];
		////1.这里赋值为-1，避免我们循环之后再次进行判断
		//int r = -1;
		//for (int i = 1; i < len; ++i)
		//{
		//	//2.这里要加=，因为我们要求的是最小区间
		//	if (p <= array[i])
		//		p = array[i];
		//	else
		//		r = i;

		//}
		//return vector<int>{before, r};
	}
};
