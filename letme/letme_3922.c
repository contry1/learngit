class solution_392 {
public:

	
	std::size_t found = 0;
	int get_index(string t, int start,char s)
	{
		for (int i = start; i < t.length(); ++i)
		{
			if (t[i] == s)
			{
				return i;
			}

		}
		return -1;
	}
	bool is_substr(string s,string t)
	{
		if (s.length() == 0)
			return true;
		for (int i = 0; i < s.length(); ++i)
		{
			found = get_index(t,found,s[i]);

			if (found == std::string::npos)//static const size_t npos = -1;
			{
				cout <<"found: "<<found << endl;
				return false;
			}
		
			cout << "found3: " << found << endl;

		}
		return true;
	}
};
