class solution_216 {
public:
	vector<int> path;
	vector<vector<int>> ans;
	void dfs(int start, int n, int size)
	{
		if (path.size() == size && n == 0)
		{
			ans.push_back(path);
			return;
		}
		if (start > 9)
			return;


		path.push_back(start);

		cout << "start:" << start << endl;

		dfs(start + 1, n-start, size);
		path.pop_back();

		cout << "star1t:" << start << endl;

		dfs(start + 1, n, size);


		cout << "star2t:" << start << endl;



	}
	vector<vector<int>> get_left_index(int n, int k)
	{


		dfs(1, n, k);
		return ans;
	}
};
