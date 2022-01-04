class Solution {
public:
    vector<int> grayCode(int n) {
        	vector<int>ans;
            int m = 0;
      int total = 1；
        while(n)
        {
          total *=2;
          n--;
        }
      
		for(int i = 0;i<total;++i)
		{
            m = i;
			m ^= (m>>1);
			ans.push_back(m);
		}
        return ans;
    }
};

