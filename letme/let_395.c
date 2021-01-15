class Solution_395_2 {
public:
	int longestSubstring(string s, int k)
	{
		int len = s.length();
		if (0 == len)
			return 0;
		unordered_map<char, int>mp;
		for (int i = 0; i < len; ++i)
		{
			mp[s[i]]++;
		}

		int left = 0;
		int right = 0;
		int max_l = 0;
	
		vector<int>split;
		for (int i = 0; i < len; ++i)
		{

			std::cout << " s[i]: " << s[i] << "  i:  " << i << endl;
			if (mp[s[i]] < k)
			{
				split.push_back(i);
			}
		}

		//说明每一个字符都符合
		if (split.size() == 0)
			return len;

		split.push_back(len);
		for (int j = 0; j < split.size(); +j)
		{
			right = split[j];
			if (right -left > max_l)
			{
				max_l = max(max_l, longestSubstring(s.substr(left,right),k));
				left = right + 1;
			}

		}
			
		std::cout << "flag == 0..." << max_l << right - left << left << endl;
		return max_l;
	}


};
