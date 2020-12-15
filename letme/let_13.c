class solution_roma{

public:
	int roma(string s)
	{
		map<char, int>mp = {
			{'I',1 },
			{'V',5 },
			{'X',10 },
			{'L',50 },
			{'C',100 },
			{'D',500 },
			{'M',1000 },
		
		};

		int sum = 0;
		for (int i = 0; i < s.length(); i++)
		{
			//NOTICE : prev val is lager next val ,or prev val is equal to next val
			if (mp[s[i]] >= mp[s[i + 1]])
				sum += mp[s[i]];
			else
				sum -= mp[s[i]];
		}

		return sum;
	}
};
