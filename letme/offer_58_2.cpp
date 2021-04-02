class Solution {
public:
    string reverseLeftWords(string s, int n) {
	int len = s.length();
		string ans;

		string sub = s.substr(0,n);
		string res = s.substr(n, len-n);

		ans = res;
		ans.append(sub);
		return ans;
    }
};
