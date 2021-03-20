class MyClass
{
public:
	MyClass();
	~MyClass();

	virtual void base1()const
	{
		cout << "base" << endl;
	}

	void base2(int num)const
	{
		cout << "base 2" << endl;
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

	//隐藏demo 1
	 void base1(int Num) const 
	{
		cout << "son" << endl;
	}

	 //隐藏demo 2
	 void base2(int num)const
	 {
		 cout << "son 2" << endl;
	 }

private:

};
int main()
{
	int a = 8; 
	int b = 10;
	cout << cmp(a, b) << endl;;

	//隐藏1
	MyClass * my = new son();
	my->base1();//打印的是复类中的方法，子类中的base不是虚函数

	son * s = new son();
	//s->base1();//会提示报错，因为我们子类中base和父类中的base同名，但是参数不一致，无论父类base是不是虚函数，
	//父类中的base发生了隐藏


	//隐藏2
	/*
	construct MyClass
	construct son
	base 2
	
	*/
	MyClass * my2 = new son();
	my2->base2(3);//不是虚函数，所以不会打son的base2


	/*	construct MyClass
		construct son
		son 2*/
	son * s2 = new son();
	s2->base2(3);//父类和子类函数名一致，参数一致，此外父类不是虚函数，父类的函数在子类中发生隐藏
