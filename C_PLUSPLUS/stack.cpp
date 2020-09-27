#include "stdafx.h"
#include <stack>
#include <stdio.h>
#include <tchar.h>
#include <stdlib.H>
#include <algorithm>
#include <iostream>
#include <functional>
#include <exception>
using namespace std;

int main()
{
	
	std::stack <int> v;
	cout << "hello  container" << endl;
	//	cout << "v.begin" <<v.begin()<< endl;
	try {

		cout << "v.top" << v.top() << endl;
	}
	catch(exception &p)
	{
		cout << p.what() << endl;
		abort();
	}
	
	cout << " v.size" << v.size() << endl;

	
	for (int i = 0; i < 5; i++)
		v.push(i);



	while (v.empty() != 0)
	{
		cout << "v.top" << v.top() << endl;
		v.pop();
	}
		cout << endl;
	
	while (v.empty() != 0)
	{
		cout << "v.top" << v.top() << endl;
		v.pop();
	}
	cout << endl;



	return 0;
}


编译提示错误。
deque iterator not dereferencable

其实就是对栈进行非法操作导致的。没有元素，我们却调用top方法。
https://www.cnblogs.com/curo0119/p/8012232.html

更正之后如下：
int main()
{
	
	std::stack <int> v;
	cout << "hello  container" << endl;
	//	cout << "v.begin" <<v.begin()<< endl;
	try {
		if(v.empty() != 1)
			cout << "v.top" << v.top() << endl;
	}
	catch(exception &p)
	{
		cout << p.what() << endl;
		abort();
	}
	
	cout << " v.size" << v.size() << endl;

	
	for (int i = 0; i < 5; i++)
		v.push(i);



  while (v.empty()!= true)
	{
		cout << "v.top" << v.top() << endl;
		v.pop();
	}
		cout << endl;
	
	while (!v.empty())
	{
		cout << "v.top" << v.top() << endl;
		v.pop();
	}
	cout << endl;





	//std::stack<int> mystack;

	//for (int i = 0; i<5; ++i) 
	//	mystack.push(i);

	//std::cout << "Popping out elements...";
	//while (!mystack.empty())
	//{
	//	std::cout << ' ' << mystack.top();
	//	mystack.pop();
	//}
	//std::cout << '\n';
	return 0;
}

测试通过。
总结：
1.栈pop，top要先判断是否非空
2.非空表达式，是等价的。v.empty()!= true   !v.empty()  v.empty() != 1。记住 empty() == 1,为空
