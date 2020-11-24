class solution2 {
	void backtrack(vector<string> &ans, string &cur, int left, int right,int depth) {
		if (left == depth && right ==depth)
		{
			ans.push_back(cur);
			return;
		}
		if (right > left)
		{
			return;
		}
		if (left < depth)
		{
			cur.push_back('(');
			backtrack(ans, cur, left + 1, right, depth);
			cur.pop_back();
		}

		
		if (right < depth)
		{
			cur.push_back(')');
			backtrack(ans, cur, left, right + 1, depth);
			cur.pop_back();
		}
	}
public:
	vector<string>ge(int n)
	{
		vector<string> ans;
		string cur;
		backtrack(ans, cur, 0,0,n);
		return ans;
	}
};

int main()
{
	solution2 so;
	vector<string>ans  = so.ge(3);
	cout << "hello %d:" <<ans.size()<< endl;
	/*for (auto &ch : ans)*/
	for(int i = 0;i<ans.size();++i)
	{
		//cout << "hello"<<endl;
		std::cout << ans[i] << '\t';
	}
	
	cout << endl;

	
	return 0;
}



//ok
hello %d:5
((()))  (()())  (())()  ()(())  ()()()

E:\vs2015_1\ltr1\Debug\ltr1.exe (进程 16652)已退出，返回代码为: 0。
按任意键关闭此窗口...




class solution2 {
	void backtrack(vector<string> &ans, string &cur, int left, int right,int depth) {
		if (left == depth && right ==depth)
		{
			ans.push_back(cur);
			return;
		}
		
		if (left > depth)
		{
			return;
		}
		if (right > left)
		{
			cout << "hello %d:   %d:" << left << right << cur << endl;
			/*if(!cur.empty())
				cur.pop_back();*/
			return;
		}

		if (right < depth)
		{

			cur.push_back(')');
			backtrack(ans, cur, left, right + 1, depth);
			cur.pop_back();
		}
		if (left < depth)
		{
			cur.push_back('(');
			backtrack(ans, cur, left + 1, right, depth);
			cur.pop_back();
		
		}

		
	}
public:
	vector<string>ge(int n)
	{
		vector<string> ans;
		string cur;
		backtrack(ans, cur, 0,0,n);
		return ans;
	}
};


class solution3 {
	void backtrack(vector<string> &ans, string &cur, int left, int right, int depth) {
		if (left == 0 && right == 0)
		{
			ans.push_back(cur);
			return;
		}

		if (left >right)
		{
			return;
		}
		//if (right ==0)
		//{
		//	cout << "hello %d:   %d:" << left << right << cur << endl;
		//	/*if(!cur.empty())
		//		cur.pop_back();*/
		//	return;
		//}

	
		if (left )
		{
			/*cur.push_back('(');*/
			backtrack(ans, cur+'(', left - 1, right, depth);
		/*	cur.pop_back();*/

		}
		if (right )
		{

			/*cur.push_back(')');*/
			backtrack(ans, cur+')', left, right - 1, depth);
			/*cur.pop_back();*/
		}

	}
public:
	vector<string>ge(int n)
	{
		vector<string> ans;
		string cur;
		backtrack(ans, cur, n, n, n);
		return ans;
	}
};
