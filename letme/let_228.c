class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
		if (nums.size() == 0)
			return 	vector<string>{};
		if (nums.size() == 1)
		{
			string s = to_string(nums[0]);
			ans.push_back(s);
			return ans;
		}
			
		int b;
        int max =2147483647;
		for (int a = 0; a < nums.size(); ++a)
		{
			for (b = a + 1; b < nums.size(); ++b)
			{
				// if ( (nums[a]>=0&&nums[b]>=0 || nums[a]<0&&nums[b]<0)&&(nums[b] - nums[a]) > (b - a))
				// {
				// 	//ans.push_back(to_string(nums[a]));
				// 	break;
				// }
                // if(nums[a]>=0&&nums[b]<0 || nums[a]<=0&&nums[b]>0 )
                // {
                //     if((nums[b] >=max&& nums[a]<=0))
                //          break;
                // }
 if((nums[b] >=max&& nums[a]<=0))
                         break;
               if((nums[b] - nums[a]) > (b - a)) 
                     break;
             
			}
			if(b - a ==1)
            {
			    ans.push_back(to_string(nums[a]));
            }
	
			else
			{
				ans.push_back(to_string(nums[a])+"->"+to_string(nums[b-1]));
				// ans.push_back("->");
				// ans.push_back(to_string(nums[b-1]));

				a = b - 1;
			}
		}
    return ans;
    }
};
