int main()
{
	int a = 8; 
	int b = 10;
	cout << cmp(a, b) << endl;;

	int ans = 100;
	//int * a = &ans;
	//1.not support make_unique

	unique_ptr<int> p(new int(22));
	/*cout << *p << endl;*/
	//2.不支持普通拷贝构造和拷贝赋值
	//unique_ptr<int>p2(p);

	//unique_ptr<int>p3;
	//p3 = p;

	//3.支持先relrease后拷贝
	unique_ptr<int>p4(p.release());
	cout << *p4 << endl;
	unique_ptr<int>p5(new int(100));
	p5.reset(p.release());
	
	auto pp = p5.release();
	unique_ptr<int>p6(p5.get());
	//cout << *p6 << endl;
};
