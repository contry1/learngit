class Solution_331 {
public:
	bool isValidSerialization(string preorder)
	{
		int n = preorder.size();
		stack<char>st;

		for (int i = 0; i < n; ++i)
		{
			if (preorder[i] == ',')
			{
				i++;
				continue;
			}
			else if (preorder[i] != '#')
			{
				//read such as "123" 
				while (i < n && preorder[i] != ',')
					i++;
				//push to st
			}
			else
			{

			}

			while (!st.empty() && st.top() == '#' && preorder[i] == '#')
			{
				//9##->#
				st.pop();
				if (!st.empty())
				{
					st.pop();
				}
			}
			st.push(preorder[i]);
		}

		if (st.size() == 1 && st.top() == '#')
			return true;
		else
			return false;
	}

	//function 2   split every string with ",",then 
	void  split(const string &src, vector<string> &ans, const string &c)
	{
		std::string::size_type pos1, pos2;
		int len = c.size();

		pos2 = src.find(c);
		pos1 = 0;

		while (std::string::npos != pos2)
		{
			ans.push_back(src.substr(pos1,pos2-pos1));
			pos1 = pos2 + len;
			pos2 = src.find(c,pos1);

			while (ans.size() >= 3 && ans[ans.size() - 1] == "#"
				&&ans[ans.size() - 2] == "#"
				&& (ans[ans.size() - 3] != "#"))
			{
				ans.pop_back();
				ans.pop_back();
				ans.pop_back();
				ans.push_back("#");
			}
		}

		//push the last part 
		if (pos1 != src.length())
		{
			ans.push_back(src.substr(pos1));
			while (ans.size() >= 3 && ans[ans.size() - 1] == "#"
				&&ans[ans.size() - 2] == "#"
				&& (ans[ans.size() - 3] != "#"))
			{
				ans.pop_back();
				ans.pop_back();
				ans.pop_back();
				ans.push_back("#");
			}
		}

	}
	bool isValidSerialization2(string preorder)
	{
		vector<string>ans;
		split(preorder,ans,",");
		if (ans.size() == 1 && ans.back() == "#")
			return true;
		else
			return false;
	}

	//function3 stack 
	bool isValidSerialization2(string preorder)
	{
		stack<int>ans;
		int n = preorder.size();
		ans.push(1);
		for (int i = 0; i < n; ++i)
		{
			if (ans.empty())
				return false;
			if (preorder[i] == ',')
				continue;
			else if (preorder[i] != '#')
			{
				while (i < n &&preorder[i] != ',')
					i++;
				
				ans.top()--;
				if (ans.top() == 0)
				{
					ans.pop();
				}

				ans.push(2);
			}
			else
			{
				ans.top()--; //ans.top() 是左值？ 
				if (ans.top() == 0)
				{
					ans.pop();
				}
			}
		}


		return ans.empty();
	}
};
