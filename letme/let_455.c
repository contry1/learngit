class Solution_455 {
public:
	int findContentChildren(vector<int>& g, vector<int>& s) {
		sort(g.begin(),g.end());

		sort(s.begin(), s.end());

		int ch = 0;
		int cake = 0;
		while (cake < s.size())
		{
			if (ch >= g.size())
				break;
			if (s[cake] >= g[ch])
				ch++;
			cake++;
		}
		return ch;
	}
};
