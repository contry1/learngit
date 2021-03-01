#include "stdafx.h"
#include <vector>
#include <set>
#include <stdio.h>
#include <tchar.h>
#include <stdlib.H>
#include <unordered_map>
#include <deque>
#include <iostream>
#include <string>
#include <functional>
#include <algorithm> 
//using namespace std;
#include <thread>     

void f1()
{
	cout << "f1-----" << endl;
}

void f2()
{
	cout << "f1-----" << endl;
}
int main()
{
	thread a(f1);
	std::thread b(f2);

	a.join();
	b.join();

	return 0;
}
