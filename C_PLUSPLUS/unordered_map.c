namespace hash1 {
	using namespace std;
	
	void test_hash()
	{
		unordered_map <int,int> um;
		int a[5] = {1,2,3,4,1};
		for (int i = 0; i < 5; i++)
		{
			um.emplace(i,a[i]);
		}

		/*for (auto it = um.begin();it!=um.end();it++)
		{
			cout << "unique key: " << it->first << "value: " << it->second << endl;;
		}
		和下面等价，不建议这样写
		*/

		unordered_map <int, int>::iterator it;
		for (it = um.begin(); it != um.end(); it++)
		{
			cout << "unique key: " << it->first << "value: " << it->second << endl;;
		}

		//insert operation
		unordered_map <int, int> u;
		u = { {7,9} };
		
		pair<int, int>u2({10,10});
		um.insert(u.begin(),u.end());
		um.insert({ { 22,19 } ,{ 28,39 } });
		um.insert(u2);
		um.insert(pair<int, int>({ 100,10 }));

		for (auto it = um.begin();it!=um.end();it++)
		{
			cout << "==unique key: " << it->first << "==value: " << it->second << endl;;
		}
	
		um.insert(pair<int, int>({ 100,100 }));//无法插入，因为key已经在里面
		for (auto it = um.begin(); it != um.end(); it++)
		{
			cout << "=2=unique key: " << it->first << "=2=value: " << it->second << endl;;
		}

		um.erase(um.find(100));//删除key=100
		um.insert(pair<int, int>({ 100,100 }));//可以插入
		for (auto it = um.begin(); it != um.end(); it++)
		{
			cout << "=3=unique key: " << it->first << "=3=value: " << it->second << endl;;
		}

		cout << endl;
	}

}
