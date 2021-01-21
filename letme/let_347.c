
class Solution_347 {
public:
	
	//function 1
	void qsort(vector<pair<int, int>>&mp, int left, int right)
	{
		if (left + 1 >= right)
			return;
		int start = left;
		std::cout << "hello  l" << start << endl;
		int end = right - 1;
		pair<int, int> key = mp[start];
		std::cout << "hello  container" << start << end << endl;
		while (start < end)
		{
			while (start < end && mp[end].second >= key.second)
				--end;
			mp[start] = mp[end];

			while (start < end && mp[start].second <= key.second)
				start++;
			mp[end] = mp[start];

		}

		mp[start]= key;
		std::cout << "hello 2 container" << start << end << endl;
		qsort(mp, left, start);
		qsort(mp, start + 1, right);
	}
	vector<int> topKFrequent(vector<int>& nums, int k) {
		int len = nums.size();
		if (k >= len)
		{
			return nums;
		}

		if (k == 0)
		{
			return  vector<int>{};
		}

		unordered_map<int, int>mp;
		for (auto &ch : nums)
			++mp[ch];

		/*	map插入元素会自动排序, 其本质是基于红黑树实现的, 在查找元素和访问元素上面速度快,
				vecotor的实现则是基于数组, , 随机访问(下标访问)速度快.因为其不需要排序, 所以在插入元素上比map要快
				在c++STL中, 序列式容器与关联式容器各有优势:
			1.例如你要对pair元素进行value或者key的重新排序等操作就最好用vector >
				2.如果只是通过key, 寻找value, 就用关联式容器, 查找速度不是一般的快*/
		vector <pair<int, int>>vp;
		for (auto &ch : mp)
			vp.push_back(ch);

		//此题转化为mp[ch]前k个最大的元素
		qsort(vp,0,vp.size());
		vector<int>ans;
		int j = 0;
		for (auto &ch : vp)
		{

			if (j >= vp.size() - k)
				ans.push_back(ch.first);
			j++;
		}
		return ans;


	}


		//function 2 .
		static bool cmp_second(pair<int, int>a, pair<int, int>b)
		{
			return a.second < b.second;
		}
		
		vector<int> topKFrequent2(vector<int>& nums, int k) {
			int len = nums.size();
			if (k >= len)
			{
				return nums;
			}

			if (k == 0)
			{
				return  vector<int>{};
			}

			unordered_map<int, int>mp;
			for (auto &ch : nums)
				++mp[ch];

			/*	map插入元素会自动排序, 其本质是基于红黑树实现的, 在查找元素和访问元素上面速度快,
					vecotor的实现则是基于数组, , 随机访问(下标访问)速度快.因为其不需要排序, 所以在插入元素上比map要快
					在c++STL中, 序列式容器与关联式容器各有优势:
				1.例如你要对pair元素进行value或者key的重新排序等操作就最好用vector >
					2.如果只是通过key, 寻找value, 就用关联式容器, 查找速度不是一般的快*/
			vector <pair<int, int>>vp;
			for (auto &ch : mp)
				vp.push_back(ch);

			//此题转化为mp[ch]前k个最大的元素
	
			sort(vp.begin(), vp.end(), cmp_second);

			vector<int>ans;
			int j = 0;
			for (auto &ch : vp)
			{

				if (j >= vp.size() - k)
					ans.push_back(ch.first);
				j++;
			}
			return ans;
	

	}



		//function 3 ac
		void qsort2(vector<pair<int, int>>&mp, int left, int right, vector<int>&ans,int k)
		{
			std::cout << "hello  2 container" << endl;
			if (left + 1 >= right)
				return;
			int start = left;
			std::cout << "hello  l" << start << endl;
			int end = right - 1;
			pair<int, int> key = mp[start];
			std::cout << "hello  container" << start << end << endl;
			while (start < end)
			{
				//降序排列
				while (start < end && mp[end].second <= key.second)
					--end;
				mp[start] = mp[end];

				while (start < end && mp[start].second >= key.second)
					start++;
				mp[end] = mp[start];

			}
			mp[start] = key;
			if (start == k)
			{
				for (int i = left; i < start; ++i)
				{
					ans.push_back(mp[i].first);
				}
				return;
			}
			else if (start > k)
			{
				qsort2(mp, left, start,ans,k);
			}
			else
			{
				
				for (int i = left; i <= start; ++i)
				{
					ans.push_back(mp[i].first);
				}
				qsort2(mp, start + 1, right,ans,k);
			}

	
		}
		vector<int> topKFrequent3(vector<int>& nums, int k) {
			int len = nums.size();
			if (k >= len)
			{
				return nums;
			}

			if (k == 0)
			{
				return  vector<int>{};
			}
		
			unordered_map<int, int>mp;
			for (auto &ch : nums)
				++mp[ch];

			vector <pair<int, int>>vp;
			for (auto &ch : mp)
				vp.push_back(ch);

			//此题转化为mp[ch]前k个最大的元素
			vector<int>ans;
			//if vp.size = 1,qsort2 will return at start,so we check the option
			if (vp.size() <= k)
			{
				for (auto &ch : vp)
					ans.push_back(ch.first);
			}
			else
			{
				qsort2(vp, 0, vp.size(), ans, k);
			}
			return ans;


		}



		//function 4 priority_queue ac
	/*	std::priority_queue
			C++ Containers library std::priority_queue
			Defined in header <queue>
			template<
			class T,
			class Container = std::vector<T>,
			class Compare = std::less<typename Container::value_type>
			> class priority_queue;*/
		static bool cmp(pair<int, int>&a, pair<int, int>&b)
		{
			return a.second > b.second;//类比大顶对
		}
		vector<int> topKFrequent4(vector<int>& nums, int k) {
			int len = nums.size();
			if (k >= len)
			{
				return nums;
			}

			if (k == 0)
			{
				return  vector<int>{};
			}

			unordered_map<int, int>mp;
			for (auto &ch : nums)
				mp[ch]++;

			auto cmp = [](pair<int, int>&a, pair<int, int>&b) {return a.second > b.second; };
			priority_queue < pair<int, int>, vector <pair<int, int>>, decltype(cmp)> q(cmp);
			priority_queue < pair<int, int>, vector <pair<int, int>>, decltype(cmp)> q2(cmp);
		/*	priority_queue<pair<int, int>, vector <pair<int, int>>, decltype(&cmp)> q(cmp);*/

			//for (auto &ch :mp)
			//	q.emplace(ch.first,ch.second);

			for (auto &ch : mp)
			{
				if (q.size() == k)
				{
					std::cout << "hello  container" <<k<< endl;
					std::cout << "hello first: second: " << q.top().first<< q.top().second <<ch.second<< endl;
					if (q.top().second < ch.second)
					{
						q.pop();
						q.emplace(ch);
					}
				}
				else
				{
				
					q.emplace(ch);
					std::cout << "hello 2 container" << k << endl;
					std::cout << "hello first: second: " << q.top().first << q.top().second << endl;
				}
				
			}

			

			//此题转化为mp[ch]前k个最大的元素
			vector<int>ans;
			while (!q.empty())
			{
				
				ans.emplace_back(q.top().first);
				q.pop();
			}
			return ans;


		}



		//function 5 priority_queue 2 ac
	/*	std::priority_queue
			C++ Containers library std::priority_queue
			Defined in header <queue>
			template<
			class T,
			class Container = std::vector<T>,
			class Compare = std::less<typename Container::value_type>
			> class priority_queue;*/
		
		vector<int> topKFrequent5(vector<int>& nums, int k) {
			int len = nums.size();
			if (k >= len)
			{
				return nums;
			}

			if (k == 0)
			{
				return  vector<int>{};
			}

			unordered_map<int, int>mp;
			for (auto &ch : nums)
				mp[ch]++;

			auto cmp = [](pair<int, int>&a, pair<int, int>&b) {return a.second < b.second; };
			priority_queue < pair<int, int>, vector <pair<int, int>>, decltype(cmp)> q(cmp);
			for (auto &ch :mp)
				q.emplace(ch.first,ch.second);


			//此题转化为mp[ch]前k个最大的元素
			vector<int>ans;
			while (!q.empty())
			{
				if (ans.size() == k)
					break;
				std::cout << "hello  container" << k << endl;
				std::cout << "hello first: second: " << q.top().first << q.top().second << endl;
				ans.emplace_back(q.top().first);
				q.pop();
			}
			return ans;


		}

		//function 6 priority_queue 3 ac
/*	std::priority_queue
		C++ Containers library std::priority_queue
		Defined in header <queue>
		template<
		class T,
		class Container = std::vector<T>,
		class Compare = std::less<typename Container::value_type>
		> class priority_queue;*/

		vector<int> topKFrequent6(vector<int>& nums, int k) {
			int len = nums.size();
			if (k >= len)
			{
				return nums;
			}

			if (k == 0)
			{
				return  vector<int>{};
			}

			unordered_map<int, int>mp;
			for (auto &ch : nums)
				mp[ch]++;

			auto cmp = [](pair<int, int>&a, pair<int, int>&b) {return a.second > b.second; };
			priority_queue < pair<int, int>, vector <pair<int, int>>, decltype(cmp)> q(cmp);
		
			//
			for (auto &ch : mp)
			{
				q.emplace(ch.first, ch.second);
				if (q.size() > k)//维持k个最小堆即可
					q.pop();
			}
			vector<int>ans;
			while (!q.empty())
			{
				std::cout << "hello  container" << k << endl;
				std::cout << "hello first: second: " << q.top().first << q.top().second << endl;
				ans.emplace_back(q.top().first);
				q.pop();
			}
			return ans;


		}
};
