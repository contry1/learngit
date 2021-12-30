class Solution17 {
public:
	map<int, string> mp;
	string tmp;
	void dfs(vector<string>& ans, string digits, int start, int end)
	{
		if (start == end) {
			ans.push_back(tmp);
			return;
		}
		//for (size_t i = start; i < end; i++) {
		size_t i = start;
			auto index = digits[i] - '0';
			auto &str = mp[index];
			for (int j = 0; j < str.size(); ++j) {
			/*	if (tmp == "" && end>1&& index == digits[end-1] - '0' )
					continue;*/
				tmp += str[j];
				dfs(ans, digits, start + 1, end);
				tmp.pop_back();
			}
		//}
	}

	vector<string> letterCombinations(string digits) {
		mp[2] = { 'a','b','c' };
		mp[3] = { 'd','e','f' };
		mp[4] = { 'g','h','i' };
		mp[5] = { 'j','k','l' };
		mp[6] = { 'm','n','o' };
		mp[7] = { 'p','q','r','s' };
		mp[8] = { 't','u','v' };
		mp[9] = { 'w','x','y','z' };
		vector<string> ans{};
		if (digits.size() == 0)
			return ans;
		int n = digits.size();
		dfs(ans, digits, 0, n);
		return ans;
	}
};
