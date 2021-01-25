class Solution_ms_1_1 {
public:

	//function1 stl map
	bool isUnique1(string astr)
	{
		unordered_map<char, int>map;
		for (auto &ch : astr)
		{
			map[ch]++;
		}

		for (auto &ch : map)
		{
			if(ch.second>1)
				return false;
		}
		return true;

	}

	//暴力，线性
	bool isUnique2(string astr)
	{
	
		for (int i = 0;i<astr.length();++i)
		{

			for (int j = i+1; j < astr.length(); ++j)
			{
				if(astr[j] == astr[i])
					return false;

			}
		}

		
		return true;

	}


	//bit
	bool isUnique3(string astr)
	{
		int mark = 0;
	/*	for (int i = 0; i < astr.length(); ++i)
		{
		
			if ((mark &(1 << astr[i] -'a')) == 0)
			{
				mark |= 1 << (astr[i] - 'a');
			
			}
			else
				return false;
		}*/

		for (auto &c:astr)
		{

			/*if (mark &(1 << c - 'a') == 0,is error  priority*/
			if ((mark &(1 << c - 'a')) == 0)
			{
				
				mark |= 1 << (c - 'a');
			}
			else
				return false;
			
		}

		return true;

	}
};
