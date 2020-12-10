class solution_106 {
public:
	string is_str(string str)
	{
		if (str.length() == 0)
			return str;
	
		int cnt = 0;
		char c = str[0];
		string ans;
		for (int i = 0; i < str.length(); ++i)
		{
			if (str[i] == c)
			{

				cnt++;
			}
			else
			{
				ans.push_back(c);
				ans.push_back(cnt + 48);
				c = str[i];
				cnt = 1;
		
			}

		}

		//mp.emplace_hint(mp.begin(),c+1, cnt);
		//key is same ,so used mutilmap,but mutilmap insert and  emplace_hint is seriers,so it can't be used!


		ans.push_back(c);
		ans.push_back(cnt + 48);
		cout << str.length() << ans.size() << endl;
		if (str.length() <= ans.size())
			return str;
		else
			return ans;
	}
};
