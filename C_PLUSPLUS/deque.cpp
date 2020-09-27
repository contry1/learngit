#include "stdafx.h"
#include <deque>
#include <stdio.h>
#include <tchar.h>
#include <stdlib.H>
#include <algorithm>
#include <iostream>
#include <functional>
//
//using namespace std;
namespace deque1
{
	using namespace std;
	void test_deque()
	{
		std::deque<int> d(100);
		/*std::deque<int> d;*/
		
		//access 1
		for (int i = 0; i < 10; i++)
		{
			d.push_back(i);
		}

		while (!d.empty())
		{
			std::cout << "d.front " << d.front() << endl;;
			std::cout << "d.back " << d.back() << endl;;
		
			d.pop_back();
			//front is 0 all time; and back is less than before
	
		}

		cout << "========================="<<endl;
		//access 2
		for (int i = 0; i < 10; i++)
		{
			d.push_front(i);
		}

		while (!d.empty())
		{
			std::cout << "d.front " << d.front() << endl;;
			std::cout << "d.back " << d.back() << endl;;

			d.pop_front();
			//back is 0 all time; and front is less than before
		
		}


		//access 3
		for (int i = 0; i < 10; i++)
		{
			d.push_front(i);
		}
		std::deque<int> ::iterator it = d.begin();
		while (it != d.end())
		{
			std::cout << "it  " << *it;
			it++;
		}
		cout << endl;

		//access 4
		for (int i = 0; i < d.size(); i++)
		{
			d.at(i) = i;
		}
		int i = 0;
		while (i < d.size())
		{
			std::cout << "at  " << d.at(i);
			i++;
		}

	
		//insert
		std::deque<int> ::iterator it2 = d.begin();
		it2++;
		d.insert(it2,100);

		it2 = d.begin();// "it" now points to the newly inserted 10,so we must reassign the it2,otherwise it will error.
    
		while (it2 != d.end())
		{
			std::cout << "it2  " << *it2;
			it2++;
		}
		cout << endl;

		cout << endl;
	}
	

}

int main()
{
	using namespace deque1;
	test_deque();
	return 0;

}
