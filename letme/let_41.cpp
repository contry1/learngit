class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
		vector<int>ans;

		//1. make  all elements that smalled than zero into n+1
	  	for (auto &ch : nums)
		{
			if (ch <= 0)
			{
				ch = len + 1;//
			}
		}

		//2.
		for (int i = 0;i<len;++i)
		{
			int num = abs(nums[i]);
				if (num <= len && num >= 1)
			{
				nums[num - 1] = -abs(nums[num-1]);
			}
		
		}

		for (int i = 0; i < len; ++i)
		{
			if (nums[i] > 0)
				return i + 1;
		}
		return  len +1;
    }
};
