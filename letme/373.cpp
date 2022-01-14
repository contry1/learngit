class Solution {
public:

// struct cmp{
// 		bool operator()(std::pair<int, int>& a, std::pair<int, int>& b)
// 		{
// 			return a.first + a.second < b.first + b.second;
// 		}

// 	};

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size();
		int n2 = nums2.size();

  auto cmp = [&nums1, &nums2](const pair<int, int> & a, const pair<int, int> & b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };


		using pr = std::pair<int, int>;
		std::priority_queue<pr, std::vector<pr>,decltype(cmp)> pq(cmp);

		std::vector<std::vector<int>>ans;
		for (size_t i = 0; i < n1; i++)
		{
			pq.emplace(std::pair<int, int>{i, 0});
		}

		while (k-- &&!pq.empty())
		{
            	//auto [x, y] = pq.top();
			std::pair<int, int> cur = pq.top();
            pq.pop();//lose
		
			ans.emplace_back(std::vector<int>{nums1[cur.first], nums2[cur.second]});
			if (cur.second + 1 < n2)
			{
				// pq.emplace(cur.first, cur.second +1);
                pq.emplace(std::pair<int, int>{cur.first, cur.second + 1});
			}
		}
		return ans;

    }
};



//ownself by

	struct cmp{
		bool operator()(std::pair<int, int>& a, std::pair<int, int>& b)
		{
			return a.first + a.second < b.first + b.second;
		}

	};

	std::vector<std::vector<int>> kSmallestPairs(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
		//std::priority_queue<int,vector<int>>
		int n1 = nums1.size();
		int n2 = nums2.size();

		using pr = std::pair<int, int>;
		std::priority_queue<pr, std::vector<pr>,decltype(cmp())> pq;

		std::vector<std::vector<int>>ans;
		for (size_t i = 0; i < n1; i++)
		{
			pq.emplace(std::pair<int, int>{i,0});
		}

		while (k-- &&!pq.empty())
		{
			std::pair<int, int> cur = pq.top();
			//auto [x, y] = pq.top();
			ans.emplace_back(std::vector<int>{cur.first, cur.second});
			if (cur.second + 1 < n2)
			{
				pq.emplace(std::pair<int, int>{cur.first, cur.second +1});
			}
		}
		return ans;

	}
