class Solution_205 {
public:
	bool isIsomorphic(string s, string t) 
	{
		unordered_map<char, char>s2t;
		unordered_map<char, char>t2s;

		int j = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			//哈希表中已经存在一个相同的key值了，但是key值映射的哈希值不一致，说明不是同构
			if (s2t.count(s[i]) && s2t[s[i]]!=t[i] || t2s.count(t[i]) && t2s[t[i]] != s[i])
				return false;
			s2t[s[i]] = t[i];
			t2s[t[i]] = s[i];
		}
		return true;
	}
};

class Solution_890 {
public:
	bool isIsomorphic(string s, string t)
	{
		unordered_map<char, char>s2t;
		unordered_map<char, char>t2s;

		int j = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			//哈希表中已经存在一个相同的key值了，但是key值映射的哈希值不一致，说明不是同构
			if (s2t.count(s[i]) && s2t[s[i]] != t[i] || t2s.count(t[i]) && t2s[t[i]] != s[i])
				return false;
			s2t[s[i]] = t[i];
			t2s[t[i]] = s[i];
		}
		return true;
	}
	vector<string> findAndReplacePattern(vector<string>& words, string pattern) 
	{
		vector<string>ans;
		for (auto &str : words)
		{
			if (isIsomorphic(str, pattern))
			{
				ans.push_back(str);
			}
		}
		return ans;
	}
};
