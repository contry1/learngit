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
