
class Solution_1208 {
public:

	//必须是连续的字符串，所以这个方式不可行
	int equalSubstring(string s, string t, int maxCost)
	{
		int len = s.length();
		map<int, int>mp;
		int val = 0;
		for (int i = 0; i < len; ++i)
		{
			val = abs(s[i] - t[i]);
			cout << val << "\t" ;
			cout << endl;
			mp[val]++;
		}

		int ans = 0;
		//while (maxCost >= 0)
		int flag = 1;
		for (auto &ch : mp)
		{
			cout << ch.first << "\t"<< ch.second;
			cout << endl;
			while (ch.second--)
			{

				maxCost -= ch.first;
				if (maxCost < 0)
				{
					flag = 0;
					cout <<"==100===="<< endl;
					break;
				}
				ans++;
			}
			if (flag == 0)
			{
				break;
			}


		}
		return ans;
	

	}

	//slip windows   timeout
	int equalSubstring2(string s, string t, int maxCost)
	{
		int len = s.length();
		vector<int>nums;
		int val = 0;
		for (int i = 0; i < len; ++i)
		{
			val = abs(s[i] - t[i]);
			cout << val << endl;
			nums.push_back(val);
		}

		int ans = 0;
		deque<int>slip;
		int sum = 0;
		int len2 = 0;
		for (int i = 0;i<len;++i)
		{
		
			int j = i;
			sum = maxCost;
			while (sum >=0 && j < len)
			{
				
				sum -= nums[j];
				if (sum <0)
				{
					break;
				}

				cout <<"sum:"<< sum << endl;
				slip.push_back(nums[j]);
				j++;
				len2++;
			}
			ans = max(ans,len2);
			cout << "len2==="<<len2 << endl;
			while (!slip.empty())
			{
				slip.pop_front();
				len2 = 0;
			}
			

		}
		
		return ans;


	}


	int equalSubstring3(string s, string t, int maxCost)
	{
		int len = s.length();
		vector<int>nums;
		int val = 0;
		for (int i = 0; i < len; ++i)
		{
			val = abs(s[i] - t[i]);
			cout << val << endl;
			nums.push_back(val);
		}

		int ans = 0;
		deque<int>slip;
		int sum = 0;
	
		for (int i = 0; i < len; ++i)
		{

			int j = i;
			
			while (sum <= maxCost && j < len)
			{
				sum += nums[j];
				if (sum > maxCost)
				{
					sum -= nums[j];
					break;
				}

				cout << "sum:" << sum << endl;
				slip.push_back(nums[j]);
				j++;
			
			}
			int length = slip.size();
			ans = max(ans, length);
			cout << "length===" << length <<"ans="<<ans<< endl;
			if(!slip.empty())
			{
				sum -= slip.front();
				slip.pop_front();
				i += slip.size();
			/*	i += len2 - 1;
				len2--;*/
			}


		}

		return ans;


	}

	//slip wind  fisrt ac
	int equalSubstring4(string s, string t, int maxCost)
	{
		int len = s.length();
		vector<int>nums;
		int val = 0;
		for (int i = 0; i < len; ++i)
		{
			val = abs(s[i] - t[i]);
			cout << val << endl;
			nums.push_back(val);
		}

		int ans = 0;
		deque<int>slip;
		int sum = 0;

		int left = 0;
		int right = nums.size();
		int offset = left;
		while(left < right)
		{
			cout << "0sum:" << sum << endl;
			cout << "0offset:" << offset << endl;
			while (sum <= maxCost && offset < len)
			{
				cout << "000sum:" << sum << endl;
				sum += nums[offset];
				if (sum > maxCost)
				{
					sum -= nums[offset];
					break;
				}
				cout << "sum:" << sum << endl;
				slip.push_back(nums[offset]);
				offset++;
			}
			int length = slip.size();
			ans = max(ans, length);
			cout << "length===" << length << "ans=" << ans << endl;
			if (!slip.empty())
			{
				sum -= slip.front();
				slip.pop_front();
				cout << "55sum:" << sum << endl;	
			}
			else
			{
				offset++;
			}
			left++;
		}
		return ans;
	}


	//slip wind 2ac 我们只是访问数组的长度和之和，不需要用一个数组和队列来缓存，可以优化如下： 
	int equalSubstring5(string s, string t, int maxCost)
	{
		int len = s.length();
		vector<int>nums;
		int val = 0;
		for (int i = 0; i < len; ++i)
		{
			val = abs(s[i] - t[i]);
			cout << val << endl;
			nums.push_back(val);
		}

		int ans = 0;
		int sum = 0;

		int left = 0;
		int right = nums.size();
		int offset = left;
		while (left < right)
		{
			while (sum <= maxCost && offset < len)
			{
				sum += nums[offset];
				if (sum > maxCost)
				{
					sum -= nums[offset];
					break;
				}
				offset++;
			}
		
			ans = max(ans, offset - left);
			if(sum)
			{
				sum -= nums[left];
			}
			else
			{
				offset++;
			}
			left++;
		}
		return ans;
	}



	//slip wind 2ac 我们只是访问数组的长度和之和，不需要用一个数组和队列来缓存，可以优化如下： 
	int equalSubstring6(string s, string t, int maxCost)
	{
		int len = s.length();
		vector<int>nums;
		int val = 0;
		for (int i = 0; i < len; ++i)
		{
			val = abs(s[i] - t[i]);
			cout << val << endl;
			nums.push_back(val);
		}

		int ans = 0;
		int sum = 0;

		int i = 0;
		int right = nums.size();
		int offset = i;
		for (i = 0; i < len; ++i)
		{
			while (sum <= maxCost && offset < len)
			{
				sum += nums[offset];
				if (sum > maxCost)
				{
					sum -= nums[offset];
					break;
				}
				offset++;
			}

			ans = max(ans, offset - i);
			if (sum)
			{
				sum -= nums[i];
			}
			else
			{
				offset++;
			}
			
		}
		return ans;
	}


	//slip wind 2ac 去掉所有的数组 ac
	int equalSubstring62(string s, string t, int maxCost)
	{
		int len = s.length();
		int ans = 0;
		int sum = 0;

		int i = 0;
		int offset = i;
		for (i = 0; i < len; ++i)
		{
			while (sum <= maxCost && offset < len)
			{
				sum += abs(s[offset] - t[offset]);
				if (sum > maxCost)
				{
					sum -= abs(s[offset] - t[offset]);
					break;
				}
				offset++;
			}
			ans = max(ans, offset - i);
			if (sum)
			{
				sum -= abs(s[i] - t[i]);
			}
			else
			{
				offset++;
			}

		}
		return ans;
	}

	/*总结一下：滑动窗口的写法要注意窗口的左端点和右端点，循环截止的条件是左端点到达末尾，而非右端点到达末尾*/
};
