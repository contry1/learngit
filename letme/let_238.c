class Solution_238 {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int>left(nums.size(),1);
		vector<int>right(nums.size(), 1);

		for (int i = 1; i < nums.size(); ++i)
		{
			left[i] = left[i-1]*nums[i-1];
			right[i] = right[i + 1] * nums[i + 1];
		}

		for (int i = nums.size()-2; i >=0; --i)
		{
			right[i] = right[i + 1] * nums[i + 1];
		}

		//因为乘积不会让nums长度变小，所以可以直接用nums.size()
		for (int i = 0; i < nums.size(); ++i)
		{
			nums[i] = left[i] * right[i];
		}

		return nums;
	}



	vector<int> productExceptSelf2(vector<int>& nums) {
		vector<int>left(nums.size(), 1);
		vector<int>right(nums.size(), 1);

		for (int i = 1; i < nums.size(); ++i)
		{
			left[i] = left[i - 1] * nums[i - 1];
			right[nums.size() - i-1] = right[nums.size() - i] * nums[nums.size() - i];
		}

		
		//因为乘积不会让nums长度变小，所以可以直接用nums.size()
		for (int i = 0; i < nums.size(); ++i)
		{
			nums[i] = left[i] * right[i];
		}

		return nums;
	}



	vector<int> productExceptSelf3(vector<int>& nums) {
		int left = 1;
		int right  =1 ;

		vector<int>res(nums.size(), 1);
		for (int i = 0; i < nums.size(); ++i)
		{
			/*
			先记录左边的乘积
			res[i] *= left;
			left = left * nums[i];

			//这里i =nums.size() - 1, 最终的乘积等于左边的乘积乘以右边的乘积，很巧妙
			res[nums.size() - i - 1] *= right;
			right = right * nums[nums.size() - i-1];*/



			res[nums.size() - i - 1] *= right;
			right = right * nums[nums.size() - i - 1];
			res[i] *= left;
			left = left * nums[i];

		}

		return res;
	}
};
