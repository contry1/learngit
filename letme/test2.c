class solution {
public:
	vector<vector<int>> three_sum(vector<int> &nums)
	{
		vector<vector<int>> ans;
		//set<vector<int>> ans;
		int len = nums.size();
		int k = 0;
		int flag = 0;
		sort(nums.begin(), nums.end());
		cout << "hello  container" << endl;
		for (int i = 0; i < len; ++i)
		{
			if (i > 0 && (nums[i] == nums[i - 1]))
				continue;
			cout << "hello  1 container" << endl;
			for (int j = i + 1; j < len; ++j)
			{
				if (j > i + 1 && (nums[j] == nums[j - 1]))
					continue;
				for (int k = i + 2; k < len; ++k)
				{
					if (k > 0 && (nums[k] == nums[k - 1]))
						continue;
					cout << "hello 2  container" << endl;
					if (nums[i] + nums[j] + nums[k] == 0)
					{
						/*	ans[k].push_back(nums[i]);
							ans[k].push_back(nums[i + 1]);
							ans[k].push_back(nums[j]);
							k++;*/   /*excedd  arrary len?*/

						vector<int> B;
						B.push_back(nums[i]);
						B.push_back(nums[j]);
						B.push_back(nums[k]);

						/*for (auto &ch : ans)
						{
							if (ch == B)
							{
								flag = 1;
								cout << "hello3333333333 container" << endl;
								break;
							}
						}
						if (flag !=1)*/
						{
							/*ans.push_back(B); */
							ans.push_back({ nums[i] ,nums[j] ,nums[k] });
							//flag = 1;
						}
						/*ans.insert(ans.begin,B);*/
					}
				}
			}

			
		}
		return ans;

	}
};
