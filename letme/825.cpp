class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(),ages.end());
		int left = 0;
		int right = 0;
		int ans = 0;
		int n = ages.size();
		for(auto age :ages) {
			if (age < 15)
				continue;
			while (ages[left] <= 0.5 * age + 7)
				left++;
			while (right + 1 < n && ages[right+1] <=age)// 不是ages[right]>age！！
				right++;
			ans += right - left;
		}
		return ans;
    }
};
