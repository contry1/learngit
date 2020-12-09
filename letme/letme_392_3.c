class solution_392 {
public:
	bool is_substr(string s,string t)
	{
		if (s.length() == 0)
			return true;
		int j = 0;
		for (int i = 0; i < t.length(); ++i)
		{
			if (t[i] == s[j])
			{
				j++;
				//i--?
			}
			if (j == s.length())
			{
				return true;
			}

		}

		return false;

	
	}
};
