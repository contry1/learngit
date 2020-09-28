namespace hash2 {
	using namespace std;

	void test_hash2()
	{
		unordered_set <int> us;
		int a[5] = { 1,2,3,4,1 };
		for (int i = 0; i < 5; i++)
		{
			us.emplace(i);
		}

		/*for (auto it = um.begin();it!=um.end();it++)
		{
		cout << "unique key: " << it->first << "value: " << it->second << endl;;
		}
		和下面等价，不建议这样写
		*/

		unordered_set <int, int>::iterator it;
		for (it = us.begin(); it != us.end(); it++)
		{
			cout << "unique key: " << *it << endl;;
		}

		//insert operation
		unordered_set <int > u; //声明unordered_set <int,allocator<int> > u 报错？
		u = { { 7,9,7 } };//重复元素不会插入到set

	
		us.insert(u.begin(), u.end());
	

		for (auto it = us.begin(); it != us.end(); it++)
		{
			cout << "==unique key: " << *it<< endl;;
		}

		pair<int, int>u2({ 10,10 });
		for (auto it = us.begin(); it != us.end(); it++)
		{
			cout << "=2=unique key: " << *it << endl;;
		}

		auto ret = us.find(100);
		if (ret == us.end())
		//	cout << "not found" << *ret <<endl; //us.end 是访问不到的，这里加上*ret会打印失败
			cout << "not found" << endl; 
		else
			us.erase(us.find(100));//删除key=100

		for (auto it = us.begin(); it != us.end(); it++)
		{
			cout << "=3=unique key: " << *it << endl;;
		}

		cout << endl;
	}

}
