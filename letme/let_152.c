class Solution_152 {
public:
	int maxProduct(vector<int>& nums) {
		int maxf = nums[0];
		int minf = nums[0];
		int ans = nums[0];

		for (int i = 1; i < nums.size(); ++i)
		{
			int mx = maxf;
			int mn = minf;

			maxf = max(mx*nums[i], max(mn*nums[i],nums[i]));

			minf = min(mn*nums[i], min(mx*nums[i], nums[i]));

			ans = max(ans,maxf);
		}
		//这一题，只能想到的是状态方程如下：
		///*maxn = max(maxn*nums[i], nums[i]);*/
		//但是这题还有负数，所以fen的话，有可能是最小的数相乘，得到了最大的数
		
	/*	我们逻辑如下：
		1.最大值*一个正数还是最大值，最小值*一个负数是最大值，还有一种特殊情况：前面均是负数，nums[i]是正数，最大值是nums【i】*/

		return ans;

	}
};
