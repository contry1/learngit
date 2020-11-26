class solution_2 {
public:
vector <int>num_34(vector<int> &nums, int target)
	{
		if (nums.size() == 0)
		{
			return vector <int>({-1,-1});
		}

		if (target <nums[0] || target>nums[nums.size() - 1])
		{
			return vector < int>({ -1,-1 });
		}
		vector <int> ans;
		int mid = nums.size() >> 1;
		int left = 0;
		int right = nums.size()-1;
		while (left <= right)
		{
	
			
			if (target < nums[mid])
			{
				cout << "hello  1 mid" << mid << endl;
				right = mid - 1;
				mid = (right + left) >> 1;
			}
			else if (target == nums[mid])
			{
				cout << "hello  mid" << mid<< endl;
				int min = mid;
				while (min >= 0 && nums[min] == target)
				{
					min--;
				}

				int max = mid;
				while (max < nums.size() && nums[max] == target)
				{
					max++;

				}
				ans.push_back(min+1);
				ans.push_back(max-1);
				break;

			}
			else
			{
				cout << "hello  2 mid" << mid << endl;
				left = mid+1;
				mid = (right + left) >> 1;
			}
		}

		return ans;
		

	}
};



class solution_22 {
public:

	int get_left_index(vector<int> &nums, int target,bool flag)
	{
		bool left_sub = flag;
		int l = 0;
		int r = nums.size();
		int last = 0;

		int m;
		cout << "hello  r" << r << endl;
		while (l < r)
		{
			m = (1 + r) /2;
		
			//cout << "hello  1 mid" << m << endl;
			if (nums[m] > target || left_sub && nums[m] == target)
			{
			
				cout << "hello  2 mid" << m<< endl;
				r = m;

			}
			else
			{
				//cout << "hello  3 mid" << m << endl;
				if (l == m && nums[m] == target)
				{
					//cout << "hello  3 mid" << m << endl;
					break;
				}
				l = m+1;//xunhuan
				

			/*	l = m;*/
			}
			
			if (l == 4 && r == 5)
			{
				//cout << "hello 333333333 mid" << m << endl;
			}
		

		}
		return l;
	}

	vector <int>num_34(vector<int> &nums, int target)
	{
		if (nums.size() == 0)
		{
			return vector <int>({ -1,-1 });
		}

		if (target <nums[0] || target>nums[nums.size() - 1])
		{
			return vector < int>({ -1,-1 });
		}
		vector <int> ans;
	
		//int left = get_left_index(nums,target,true);
		int right = get_left_index(nums, target, false);
		
		//ans.push_back(left);
		ans.push_back(right-1);
		return ans;


	}
};
