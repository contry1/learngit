class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.size() == 0)
			return;
	
		int left = 0;
		int right = nums.size();

		if (k >= nums.size())
		{
			if (k%nums.size() == 0)
				return;
			else
				k = k % nums.size();
		}

	    vector<int> tmp(k, 0);
		int off = k;
		while (off)
		{
			right--;
			off--;
		}

		int j = 0;
		for (int i = right; i <= nums.size() - 1; ++i)
		{
			tmp[j++] = nums[i];	
		}

		for (int i = right + k-1; i >=k; --i)
		{
		
			nums[i] = nums[i - k];
		}

		j = 0;
		for (int i = 0; i < k; ++i)
		{

			nums[i] = tmp[j++];
		}
    }
};
