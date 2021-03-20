class MyClass
{
public:
	MyClass();
	~MyClass();

	virtual void base()
	{
		cout << "base" << endl;
	}

private:

};

MyClass::MyClass()
{
	cout << "construct MyClass" << endl;
}

MyClass::~MyClass()
{
	cout << "delete MyClass" << endl;
}


class son : public MyClass
{
public:
	son()
	{
		cout << "construct son" << endl;
	}
	~son()= default;

	virtual void base()
	{
		cout << "son" << endl;
	}

private:

};
int main()
{
	int a = 8; 
	int b = 10;
	cout << cmp(a, b) << endl;;

	MyClass * my = new son();
	my->base();

	//向上转型，是安全的
	MyClass * my_static = static_cast<MyClass *>(new son());
	my_static->base();

	MyClass * my_dynamic = dynamic_cast<MyClass *>(new son());
	my_dynamic->base();

	
	//向下转型，是不安全的
	cout << "convert to down" << endl;
	MyClass * my_down = new MyClass();
	son* s = new son();

	cout << "convert to down=====" << endl;

	//类型不一致，不能转换
	son * s2 = dynamic_cast<son *>(my_down);
	s2->base();

	////类型不一致，static_cast没有做检测，能转换不安全
	son *s3 = static_cast<son *>(new MyClass());
	s3->base();//ok 调用的是父类的虚函数，这里由于没有做类型转换，虽然OK，但是不安全的

	cout << "convert to down===3==" << endl;

	
	//类型不一致，不能转换
	son *s4 = dynamic_cast<son *>(new MyClass());
	s4->base();//err，这里由于有做类型转换，运行期检测，所以是安全的
	cout << "convert to down===4==" << endl;

	MyClass * my_down5 = new son();
	son *s5 = dynamic_cast<son *>(my_down5);
	s5->base();//ok,调用的是子类的虚函数
	cout << "convert to down===5==" << endl;

	son *s6 = static_cast<son *>(my_down5);
	s6->base();//ok,调用的是子类的虚函数

	cout << "convert to down===6==" << endl;
