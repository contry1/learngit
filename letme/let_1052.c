class Solution_1052 {
public:
	int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) 
	{
		int len1 = customers.size();
		int len2 = grumpy.size();

		int ans = 0;
		int left = 0;
		int right = 0;

		int leftsum = 0;
		int rightsum = 0;
		int midsum = 0;
		for (int i = 0; i < len1-X+1; ++i)
		{
			left = i;
			right = left + X;

			for (int j = 0; j < left; ++j)
			{
				cout <<"customers[j]: "<< customers[j] << endl;
				cout << "grumpy[j]^1: " << (grumpy[j] ^ 1) << (customers[j] & (grumpy[j] ^ 0x1) )<< endl;
				cout << leftsum << "\t";
				int b = (grumpy[j] ^ 1);
				customers[j] = grumpy[j] == 1 ? 0:customers[j];
				leftsum += customers[j];
				cout << "==========="<<leftsum << endl;
			}
			cout << leftsum << "\t";
			for (int j = left; j < right; ++j)
			{
				midsum += customers[j];
			}
			cout << midsum << "\t";
			for (int j = right; j < len1; ++j)
			{
				customers[j] = (grumpy[j] == 1) ? 0 : customers[j];
				rightsum += customers[j];
			}
			cout << rightsum << "\t";
			cout << endl;
			ans = max(ans,leftsum+midsum+rightsum);
			leftsum = 0;
			midsum = 0;
			rightsum = 0;
			cout << ans << "\t";
			cout << endl;
		}
		return ans;

	}




		//timeout   ac 74/78
		int maxSatisfied2(vector<int>& customers, vector<int>& grumpy, int X) {
			int len1 = customers.size();
			int len2 = grumpy.size();

			int ans = 0;
			int left = 0;
			int right = 0;

			int leftsum = 0;
			int rightsum = 0;
			int midsum = 0;
			for (int i = 0; i < len1 - X + 1; ++i)
			{
				left = i;
				right = left + X;

				for (int j = 0; j < left; ++j)
				{
					//  customers[j] = (grumpy[j] == 1) ? 0:customers[j];
					if (grumpy[j] == 1)
					{
						continue;
					}
					leftsum += customers[j];

				}

				for (int j = left; j < right; ++j)
				{
					midsum += customers[j];
				}

				for (int j = right; j < len1; ++j)
				{
					//  customers[j] =(grumpy[j] == 1) ? 0:customers[j];
					if (grumpy[j] == 1)
					{
						continue;
					}

					rightsum += customers[j];
				}

				ans = max(ans, leftsum + midsum + rightsum);
				leftsum = 0;
				midsum = 0;
				rightsum = 0;
			}
			return ans;
		}

		//ac 
		//1.用缓存替代遍历，降低时间复杂度
		//2.寻找更多的不变量，降低变量的个数
		int maxSatisfied3(vector<int>& customers, vector<int>& grumpy, int X) {
			int len1 = customers.size();
			int len2 = grumpy.size();

			int ans = 0;
			int left = 0;
			int right = 0;

			vector<int>new_customers;
			int orinum = 0;
			for (int i = 0; i < len1; ++i)
			{
				if (grumpy[i] == 1)
				{
					new_customers.push_back(0);
					continue;
				}

				new_customers.push_back(customers[i]);
				orinum += customers[i];
			}
	
			int midsum = 0;
			for (int i = 0; i < len1 - X + 1; ++i)
			{
				left = i;
				right = i + X;
				for(int j = left;j<right;j++)
				{
					midsum += customers[j] - new_customers[j];
				}
				ans = max(ans,orinum+ midsum);
				midsum = 0;
			}
			return ans;
		}


		//滑动窗口相减
		int maxSatisfied4(vector<int>& customers, vector<int>& grumpy, int X) {
			int len1 = customers.size();

			int ans = 0;
			int left = 0;
			int right = 0;

			vector<int>new_customers;
			int orinum = 0;
			for (int i = 0; i < len1; ++i)
			{
				if (grumpy[i] == 1)
				{
					new_customers.push_back(0);
					continue;
				}

				new_customers.push_back(customers[i]);
				orinum += customers[i];
			}
		

			int midsum = 0;
			int oldsum = 0;
			int newsum = 0;
			for (int j = 0; j < X; j++)
			{
				oldsum += customers[j];
				newsum += new_customers[j];
			}
			midsum = oldsum - newsum;
			ans = max(ans, orinum + midsum);
			cout << ans << endl;
			for (int i = X; i < len1 ; ++i)
			{
				oldsum += customers[i];
				oldsum -= customers[left];

				newsum += new_customers[i];
				newsum -= new_customers[left];
				
				midsum = oldsum - newsum;
				cout <<"midsum: "<< midsum << endl;
				ans = max(ans, orinum + midsum);
				midsum = 0;
				left++;
			}
			return ans;
		}
	
};
