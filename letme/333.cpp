class solution6 {

public:
    bool intr(std::vector<int> &nums) {
        int n = nums.size();

        if (n < 3) return false;
        std::vector<int>left(n);     
        std::vector<int>right(n);

        for (size_t i = 0; i < n; i++)
        {
            if (i == 0)
            {
                left[0] = nums[0];
                continue;
            }
            left[i] = std::min(left[i-1], nums[i]);
        }

        for (size_t i = n-1; i >=0; i--)
        {
            if (i == n-1)
            {
                right[i] = nums[n-1];
                continue;
            }
            right[i] = std::max(right[i + 1], nums[i]);
        }


        for (size_t i = 1; i < n; i++)
        {
          
            if (left[i-1] < nums[i] && nums[i] < right[i+1])
                return true;

        }
        return false;
    
    }
};
