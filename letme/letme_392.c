class solution_392 {
public:

	std::size_t prev = 0;
	bool is_substr(string s,string t)
	{
		if (s.length() == 0)
			return true;
		for (int i = 0; i < s.length(); ++i)
		{
			std::size_t found = t.find(s[i]);
			if (found == std::string::npos)
			{
				cout <<"found: "<<found << endl;
				return false;
			}
			if (found < prev)
			{
				cout << "found2: " << found <<prev<< endl;
				return false;
			}
				
			prev = found;
			cout << "found3: " << found << endl;

		}
		return true;
	}
};
