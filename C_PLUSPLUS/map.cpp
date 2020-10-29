#include "stdafx.h"
#include <iostream>
#include <map>
#include <vector>
#include <stdlib.h>
using namespace std;
#define max(a,b) (((a) > (b)) ? (a) : (b))
bool canjump(vector<int> &nums)
{
	int max_step = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		//if(max_step>=i)//
		max_step = max(max_step,i+nums[i]);
		if (max_step >= nums.size())
			return true;
	}
	return false;

}
int main()
{
	map <int,int> mp;
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		mp.emplace(i,6);
	}

	for (auto &c : mp)
		cout << c .first<< c.second<<endl;
	return 0;
}


、、。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。

#include "stdafx.h"
#include <iostream>
#include <map>
#include <vector>
#include <stdlib.h>
using namespace std;
#define max(a,b) (((a) > (b)) ? (a) : (b))
bool canjump(vector<int> &nums)
{
	int max_step = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		//if(max_step>=i)//
		max_step = max(max_step,i+nums[i]);
		if (max_step >= nums.size())
			return true;
	}
	return false;

}
int main()
{
	map <int,int> mp;
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		mp.emplace(i,6);
	}

	//1.第一种遍历
	for (auto &c : mp)
		cout << c .first<< c.second<<endl;


	//2.第2种遍历，采用迭代器
	//cout << "iterator :"<<endl;
	//map <int, int> ::iterator it = mp.begin();
	//for (it; it != mp.cend(); it++)
	//{
	//	cout << (*it).first << (*it).second;
	//}
	//cout  << endl;




	//3.第3种遍历，采用只读const迭代器,c++11 support
	// 一个函数中不能同时出现两种迭代器，必须是同一种，const和非const，否则会报错。
	//主要应用于key 为const value type的map
	cout << "const iterator :" << endl;
	map <int, int> ::const_iterator  it  = mp.cbegin();
	for (it; it != mp.cend(); it++)
	{
		cout << (*it).first << (*it).second;
	}
	cout << endl;


	//5.第5种遍历，反转遍历
	cout << "reverse iterator :" << endl;
	map <int, int> ::reverse_iterator  rit = mp.rbegin();
	for (rit = mp.rbegin(); rit != mp.rend(); rit++)
	{
		cout << (*rit).first << " => " << (*rit).second << '\n';
		//equal :
		//std::cout << rit->first << " => " << rit->second << '\n';
	}
	cout << endl;

	//4.第4种遍历，擦除最前的元素，但是擦出了元素和前面几个不一样
	cout << "4 iterator :" << endl;
	while (!mp.empty())
	{
		std::cout << mp.begin()->first << " => " << mp.begin()->second << '\n';
		mp.erase(mp.begin());
	}

	//swap function
	std::map<int, int>mp1;
	mp1[1] = 100;
	mp1[10] = 1000;
	mp1[100] = 10000;
	std::map<int, int>mp2;
	mp2[0] = 9;

	cout << "ago swap :" << endl;
	for(auto &ch:mp1)
		cout << ch.first << " mp1=> " << ch.second << endl;
	for (auto &ch : mp2)
		cout << ch.first << " mp2=> " << ch.second << endl;

	mp2.swap(mp1);
	cout << "after swap :" << endl;
	for (auto &ch : mp1)
		cout << ch.first << " mp1=> " << ch.second << endl;
	for (auto &ch : mp2)
		cout << ch.first << " mp2=> " << ch.second << endl;
#if 0
	//insert func
	if (mp.empty())
	{
		//insert 1
		mp.insert(mp.begin(), { 1,33 });
		std::pair<int, int> node1 = { 2,77 };
		mp.insert(mp.begin(), node1);
		mp.insert(mp.begin(), std::pair<int, int>(3,55));

		cout << mp.begin()->first << " a=> " << mp.begin()->second<< endl;
		//insert 2,default insert at tail
		mp.insert(std::pair<int, int>(4, 55));
		cout << mp.begin()->first << " b=> " << mp.begin()->second << endl;

		//insert 3,one map insert to the other map
		std::map<int, int>newmp;
		newmp.insert(mp.begin(),mp.find(4));

		for (auto &c : newmp)
			cout << c.first << " newmp=> " << c.second << endl;
		//newmp输出信息：
	/*	1 newmp = > 33
			2 newmp = > 77
			3 newmp = > 55*/
		
	}

	for (auto &c : mp)
		cout << c.first << " => " << c.second << endl;
	//mp输出信息：
	//1 = > 33
	//	2 = > 77
	//	3 = > 55
	//	4 = > 55
#endif	
	return 0;
}
