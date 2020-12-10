class solution_55 {
public:
	bool is_str(vector<int> &str)
	{
		int n = str.size();
		int max1 = 0;
		/*for (int i = 0; i < n; ++i)
		{
			if (i + str[i] >= n - 1) //ex 1,1,1,1 is not ac
				return true;
		}*/

		for (int i = 0; i < n; ++i)
		{
			max1 = max(i + str[i],max1); 
			if (max1 >= n - 1)
				return true;
		}

		return false;
	}
};
