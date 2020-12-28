class solution_34 {
public:
	int get_left(vector<int> &nums, int target)
	{
		int l = 0;
		int r = nums.size();
		int m;
		while (l < r)
		{
			m = (l + r) >> 1;
			if (nums[m] < target)
			{
				l =m+1;
			}
			else
			{	
				r = m;//this "=" 要考虑会不会陷入死循环
			}
		}
		//exit time, l == r
		return l;
	
	}

	int get_right(vector<int> &nums, int target)
	{
		int l = 0;
		int r = nums.size();
		int m;
		while (l < r)
		{
			 m= (l + r) >> 1;

			/* 这个逻辑如下：*/
			 //if (nums[m] == target)//==?skip the 1st
			 //{
				// l = m + 1; //	l = m + 1; //
				// std::cout << "hello 2 ===" << endl;
			 //}
			 //else if (nums[m] < target)//==?skip the 1st
			 //{
				// l = m + 1; //	l = m + 1; //
				// std::cout << "hello 2 ===" << endl;
			 //}
			if (nums[m] <= target)//==?skip the 1st
			{
				//这里的判断条件是target》num【mid】，为何l = m+1,而不是L=M?
			/*	1.因为我们要寻找的是target出现在最右边的一个数，对于该数，有如下特点：
					存在一个m = target, 使得x >= m时，num[x] = target, 而我们要寻找的就是这个x的max。
					极端情况，max_x = m, 即等于target的值只出现一次。如果l ==m,则会必然出现死循环！

					2. 最后一个端点值，M = R - 1;=>L = R,会有越界风险，所以 up = get_right(nums, target) - 1;*/
				l = m + 1; 
			}
			else
			{
				r = m;
			}
		}
		//exit time, l == r
		return l;

	}
	vector<int>  get_left_index(vector<int> &nums, int target)
	{
		int len = nums.size();
		int left = 0;
		int right = len - 1;
		if (len == 0)
			return vector<int>{-1, -1};
		int low = get_left(nums,target);
		int up = get_right(nums, target)-1;
		if (low == len||nums[low] != target )
		//if (nums[low] != target || low == len)//会有溢出风险，所以low要先判断！
			return vector<int>{-1,-1};
		return vector<int>{low, up};
	}
};


class solution_34_2 {
public:
	int get_left(vector<int> &nums, int target)
	{
		int l = 0;
		int r = nums.size()-1;
		int m;
		while (l <= r)//this "=" 要考虑会不会陷入死循环
		{
			m = (l + r) >> 1;
			if (nums[m] < target)//<
			{
				l = m + 1;
			}
			else
			{
				r = m;// m ;
				if (l == r)
					break;//this 这里会陷入死循环，break
			}
		}
		return l;

	}

	int get_right(vector<int> &nums, int target)
	{
		int l = 0;
		int r = nums.size()-1;
		int m;
		while (l <= r)
		{
			m = (l + r) >> 1;

			/* 这个逻辑如下：*/
			 //if (nums[m] == target)//==?skip the 1st
			 //{
				// l = m + 1; //	l = m + 1; //
				// std::cout << "hello 2 ===" << endl;
			 //}
			 //else if (nums[m] < target)//==?skip the 1st
			 //{
				// l = m + 1; //	l = m + 1; //
				// std::cout << "hello 2 ===" << endl;
			 //}
			if (nums[m] <= target)//==?skip the 1st
			{
				//这里的判断条件是target》num【mid】，为何l = m+1,而不是L=M?
			/*	1.因为我们要寻找的是target出现在最右边的一个数，对于该数，有如下特点：
					存在一个m = target, 使得x >= m时，num[x] = target, 而我们要寻找的就是这个x的max。
					极端情况，max_x = m, 即等于target的值只出现一次。如果l ==m,则会必然出现死循环！

					2. 最后一个端点值，M = R - 1;=>L = R,会有越界风险，所以 up = get_right(nums, target) - 1;*/
				l = m + 1;
			}
			else
			{
				r = m;
				if (l == r)
					break;
				//this 这里会陷入死循环，break
			}
		}
		return l;

	}
	vector<int>  get_left_index(vector<int> &nums, int target)
	{
		int len = nums.size();
		int left = 0;
		int right = len - 1;
		if (len == 0)
			return vector<int>{-1, -1};
		int low = get_left(nums, target);
		int up = get_right(nums, target) - 1;
		if (low == len || nums[low] != target)
			//if (nums[low] != target || low == len)//会有溢出风险，所以low要先判断！
			return vector<int>{-1, -1};
		return vector<int>{low, up};
	}
};

class Solution_34_demo {
public:
	int get_left(vector<int> &nums, int target)
	{
		int l = 0;
		int r = nums.size();// - 1;
		int m;
		while (l < r)//this "=" 要考虑会不会陷入死循环
		{
			m = (l + r) >> 1;
			if (nums[m] >= target)//<
			{
				r = m;
				//		std::cout<< "hello ===" << endl;

			}
			else
			{
				//	std::cout << "hello  ****" << endl;

				l = m + 1;// m ;
			}
		}
		//exit time, l == r
		//std::cout << "hello  1 container" << l << r <<m<< endl;
		return l;

	}

	int get_right(vector<int> &nums, int target)
	{
		int l = 0;
		int r = nums.size();// - 1;
		int m;
		while (l < r)
		{
			m = (l + r) >> 1;
			if (nums[m] > target)//==?skip the 1st
			{
				r = m; //l = m 

			}
			else
			{
				l = m + 1;
				//	std::cout << "hello 2 ****" << endl;
			}
		}
		//exit time, l == r
	//	std::cout << "hello  container" <<l<<r<<m<< endl;
		return l;

	}
	vector<int> searchRange(vector<int>& nums, int target) {

		int len = nums.size();
		if (len == 0)
			return vector<int>{-1, -1};

		int low = get_left(nums, target);
		int up = get_right(nums, target) - 1;

		if (low == len || nums[low] != target)
			//if (nums[low] != target || low == len)
			return vector<int>{-1, -1};
		return vector<int>{low, up};

	}
};
