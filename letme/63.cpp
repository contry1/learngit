class Solution_63 {
public:
	int maxProfit(vector<int>& prices) {
		stack<int>in;
		stack<int>out;
		int max_val = 0;
		int ans = 0;
		int len = prices.size();
		for (auto &ch : prices)
		{
			if (!in.empty())
			{
				if (ch < in.top())
				{
					
					if (!out.empty())
					{
						max_val = out.top() - in.top();
						ans = max(max_val, ans);
					}
					in.pop();
					in.push(ch);

					//if (ch == prices[len - 1])
					{
						if (!out.empty())
							out.pop();
					}
					continue;
					
				}
			}
			else
			{
				in.push(ch);
				continue;
			}
	
			
			if (!out.empty())	
			{
				if (ch > out.top())
				{
					//out.pop();
					out.push(ch);
				}
			}
			else
			{
				//diyici
				if (!in.empty() && ch > in.top())
				{
					out.push(ch);
				}
			
			}
		}

		
		if (!out.empty())
		{
			max_val = out.top() - in.top();
			ans = max(max_val, ans);
		}
		
		return ans;

	}
};
