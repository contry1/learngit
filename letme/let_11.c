class Solution_11 {
public:
	int maxArea(vector<int>& height) 
	{
		int len = height.size();
		int i = 0;
		int j = len - 1;
		int ans = 0;
		while (i < j)
		{
			int area = (j - i)*min(height[j],height[i]);
			ans = max(ans,area);
			if (height[i] < height[j])
			{
				i++;//we must use i++,or not j--? the below is reason
				//if (height[i - 1] < height[i])
				//	int area2 = (j - i)*min(height[j], height[i]);/* > area1; this is might*/
				//else
				//	continue;

				//j--;
				//int area3 = 0;
				//if (height[j + 1] < height[j])
				//{
				//	area3 = (j - i)*min(height[j], height[i]);
				//	area3<area must
				//}
				//else
				//{
				//	area3 = (j - i)*min(height[j], height[i]);
				//	area3 < area must
				//}

			}
			else
			{
				j--;
			}
		}
		return ans;
	}
};
