class Solution_18_demo2 {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		if (nums.size() < 4)
		{

			return vector<vector<int>>({});
		}

		sort(nums.begin(), nums.end());
		vector<vector<int>>ans;
		for (int i = 0; i < nums.size() - 3; ++i)
		{
			//1.优化1
			if (i >= 1 && nums[i] == nums[i - 1])
			{
				continue;
			}


			if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
			{
				break;
			}
			if (nums[i] + nums[nums.size() - 3] + nums[nums.size() - 2] + nums[nums.size() - 1] < target)
			{
				continue;
			}


			for (int l = i + 1; l < nums.size() - 2; ++l)
			{
				if (l > i + 1 && nums[l] == nums[l - 1])
				{

					continue;
				}

				if (nums[i] + nums[l] + nums[l + 1] + nums[l + 2] > target)
				{
					break;
				}
				if (nums[i] + nums[l] + nums[nums.size() - 2] + nums[nums.size() - 1] < target)
				{

					continue;
				}
				int c = l + 1;
				int r = nums.size() - 1;
				
				while (c < r)
				{

					int sum = nums[i] + nums[l] + nums[r] + nums[c];
					cout << "l:  r:" << i << l << r << c << endl;
					if (target == sum)
					{
						cout << "l: = r:" << i << l << r << c << endl;
						ans.push_back({ nums[i] ,nums[l] ,nums[c] ,nums[r] });

						if (c < r - 1)
						{
						//	if (nums[i] + nums[l] + nums[r] + nums[c + 1] > target)
              if (nums[c + 1] > nums[c])
							{
								r--;
								while (r > c && nums[r] == nums[r + 1])
								{
									r--;
								}

							}
							else {
								c++;
								while (c < r && nums[c] == nums[c - 1])
								{
									c++;
								}

							}
						}
						else
						{
							break;
						}
						
						
					
					}
					else if (target < sum)
					{
						cout << "large r:" << r << endl;
						r--;
						
					}
					else
					{
						cout << "large c:" << c << endl;
						c++;
						
					}

				}
			}
			
		}

		return ans;
	}
};



