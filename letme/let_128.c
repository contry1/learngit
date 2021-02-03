class uf {
	vector<int>id;
public:
	uf(int n) :id(n)
	{
		std::iota(id.begin(),id.end(),0);
	}

	//query
	int find(int p)
	{
		if (p == id[p])
		{
			return p;
		}
		else
		{
			return find(id[p]);
		}
	}

	//merge
	void merge(int p, int q)
	{
		id[find(p)] = id[q];
	}

	//is connect?
	bool is_connect(int p, int q)
	{
		return find(p) == find(q);
	}

};

//path zip alg
class fu {
	vector<int>fa;
	vector<int>rank;//这里我们默认是树的最大深度depth
public:
	fu(int n) :fa(n)
	{
		std::iota(fa.begin(), fa.end(), 0);
	}

	//query
	int find(int p)
	{
		if (p == fa[p])
		{
			return p;
		}
		else
		{
			return find(fa[p]);
		}
	}

	//merge
	void merge(int p, int q)
	{
		int x = find(p);
		int y = find(q);

		if (x == y)
		{
			return;
		}
		else 
		{
			if (rank[x] < rank[y])
			{
				fa[x] = y;
			}
			else if(rank[x] == rank[y])
			{
				fa[x] = y;
				rank[y]++;
			}
			else
			{
				fa[y] = x;
			}
		}
	}

	//is connect?
	bool is_connect(int p, int q)
	{
		return find(p) == find(q);
	}

};

class Solution_128 {
public:

	//function1 not ac ，这个解答是要求数组元素连续的，不符合题意
	int cnt = 0;
	int mm = 0;

	//思考，如果我们不能排序，那么对于一个起始数1，他的下一个连续数2在数组中出现的位置是不定的，
	//一般的思维就是对于每一个数，遍历整个数组，但是这样，时间复杂度大大增加。我们之前也遇到类似问题
	//可以通过哈希表方式存储起来，以空间换时间，然后再利用并查集

	//官方思路1.哈希表 ac
	int longestConsecutive(vector<int>& nums)
	{
		int len = nums.size();
		unordered_set<int>set;
		for (int &ch : nums)
		{
			//去重
			set.emplace(ch);
		}

		int mx = 0;
		int currnum = 0;
		int ans = 0;

		for (auto &ch : set)
		{
			//如果有前驱节点存在，那么跳过，反正后面也会遍历到该点的
			if (!set.count(ch - 1))
			{
				//前驱节点不存在，去判断后续节点。如果有前驱节点存在，那么跳过，反正后面也会遍历到该点的
				mx = 1;
				currnum = ch;
				while (set.count(currnum + 1))
				{
					mx++;
					currnum = currnum + 1;
				}
				ans = max(mx, ans);
			}	
		}
		return ans;
	}


	//并查集 ac
	unordered_map<int,int>set;
	unordered_map<int,int>rank;
	int find(int p)
	{
		if (p == set[p])
		{
			return p;
		}
		else
		{
			return find(set[p]);
		}
	}
	int merge(int p, int q)
	{
		int x = find(p);
		int y = find(q);

		if (x == y)
		{
			return rank[x];
		}
		else
		{
			if (rank[x] <= rank[y])
			{
				set[x] = y;
				rank[y] += rank[x];//这里为个数
				return rank[y];
			}
			else
			{
				set[y] = x;
				rank[x] += rank[y];//这里为个数
				return rank[x];
			}
		}
		return 1;
	}

	int longestConsecutive(vector<int>& nums)
	{
		int len = nums.size();
		if (len <=1)
			return len;
	
		for (int &ch : nums)
		{
			set[ch] = ch;
			rank[ch] = 1;
		}

		int mx = 0;
		int ans = 1;

		for (auto &ch : nums)
		{
			if (ch != INT_MAX && set.count(ch+1))//find(ch+1)== ch+1)//set[ch + 1])
			{
				mx = merge(ch,ch+1);
				ans = max(ans,mx);
			}
		}
		return ans;
	}
};
