class solution_520 {
public:
	bool is_substr_big(string t)
	{
		int index = -1;
		int flag = 0;
		for (auto &ch : t)
		{
			if (ch >= 'A' && ch <= 'Z')
			{
				if (ch == t[0])
				{
					flag = 1;
				}
				index++;
				
					
			}
			
				
		}

		if (flag == 1 && index == 0 || index == t.length()-1 || index ==-1 && flag == 0)
			return true;
		
		return false;
	}

	//bool is_substr_small(string t)
	//{
	//	for (auto &ch : t)
	//	{
	//		if (ch >= 'a' && ch <= 'z')
	//		{

	//		}
	//		else
	//		{
	//			//cout << ch << endl;
	//			return false;
	//		}
	//			
	//	}
	//	return true;
	//}

	bool is_substr(string t)
	{
		if (t.length() == 0)
			return true;
		
		//return is_substr_small(t) || is_substr_big(t);
		return  is_substr_big(t);

	}
};
