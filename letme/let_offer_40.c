class Solution_offer_40 {
public:

	//1. min heap alg
	void swap(int *a, int *b)
	{
		int c = *a;
		*a = *b;
		*b = c;
	}
	//void QuickSort(vector<int>&a, int low, int high)
	//{
	//	int i = low;
	//	int j = high;
	//	int key = a[low];
	//	if (low >= high)  //如果low >= high说明排序结束了
	//	{
	//		return;
	//	}
	//	while (low < high)  //该while循环结束一次表示比较了一轮
	//	{
	//		while (low < high && key <= a[high])
	//		{
	//			--high;  //向前寻找
	//		}
	//		if (key > a[high])
	//		{
	//			swap(&a[low], &a[high]);
	//			++low;
	//		}
	//		while (low < high && key >= a[low])
	//		{
	//			++low;  //向后寻找
	//		}
	//		if (key < a[low])
	//		{
	//			swap(&a[low], &a[high]);
	//			--high;
	//		}
	//	}
	//	QuickSort(a, i, low - 1);  //用同样的方式对分出来的左边的部分进行同上的做法
	//	QuickSort(a, low + 1, j);  //用同样的方式对分出来的右边的部分进行同上的做法
	//}
	void msort(vector<int>&arr,int left, int right)
	{
		if (left + 1>= right)
			return;
		int L = left;
		std::cout << "hello  l" << L  << endl;
		int r = right-1;
		int key = arr[L];
		std::cout << "hello  container" <<L<<r <<endl;
		while (L< r)
		{
			while (L < r && arr[r] >= key)
				--r;
			arr[L] = arr[r];
			
			while (L < r && arr[L] <= key)
				L++;
			arr[r] = arr[L];
	
		}

		arr[L] = key;
		std::cout << "hello 2 container" << L << r << endl;
		msort(arr,left,L);
		msort(arr, L+1, right);
	}

	vector<int> getLeastNumbers(vector<int>& arr, int k) 
	{
		int len = arr.size();
		if (k >= len)
		{
			return arr;
		}

		if (k == 0)
		{
			return  vector<int>{};
		}
	
		//1.sort k nums[]
	
		msort(arr,0,k);
		

		//2.heap update
		for (int i = k; i < len; ++i)
		{
			if (arr[i] >= arr[k - 1])
				continue;
			else
			{
				/*arr[k - 1] = arr[i];*/
				/*msort(arr, 0, k);*/ //再次quick sort 超时,直接比较

				int d = k-1;
				while (d >= 0 && arr[i] < arr[d])
				{
					--d;
				}
				arr[d] = arr[i];
				

			}
			
		}

		//3.min heap 
		vector<int> ans;
		for (int i = 0; i < k; ++i)
		{
			ans.push_back(arr[i]);
		}
		return ans;

	}



	vector<int> getLeastNumbers2(vector<int>& arr, int k)
	{
		int len = arr.size();
		if (k >= len)
		{
			return arr;
		}

		if (k == 0)
		{
			return  vector<int>{};
		}

	
		vector<int> ans(k);
		for (int i = 0; i < k; ++i)
		{
			ans.push_back(arr[i]);
		}
		//1.sort k nums[]
		msort(ans, 0, k);


		//2.heap update
		for (int i = k; i < len; ++i)
		{
			if (arr[i] >= ans[k - 1])
				continue;
			else
			{
				/*arr[k - 1] = arr[i];*/
				/*msort(arr, 0, k);*/ //再次quick sort 超时,直接比较

				ans.pop_back();
				int d = k - 1;
				while (d >= 0 && arr[i] < ans[d])
				{
					--d;
				}
				ans.insert(ans.begin()+d+1,arr[i]);
				

			}

		}

		//3.min heap 
		return ans;

	}










	//3 function
	int get_left(vector<int>& ans, int num)
	{
		int left = 0;
		int right = ans.size() - 1;
		while (left < right)
		{
			int m = (left + right) >> 1;
			if (ans[m] < num)
			{
				left = m + 1;
			}
			else
			{
				right = m;
			}
		}
		return left;
	}


	vector<int> getLeastNumbers3(vector<int>& arr, int k)
	{
		int len = arr.size();
		if (k >= len)
		{
			return arr;
		}

		if (k == 0)
		{
			return  vector<int>{};
		}


		vector<int> ans;
		for (int i = 0; i < k; ++i)
		{
			ans.push_back(arr[i]);
		}
		//1.sort k nums[]
		msort(ans, 0, k);


		//2.heap update
		for (int i = k; i < len; ++i)
		{
			if (arr[i] >= ans[k - 1])
				continue;
			else
			{
				/*arr[k - 1] = arr[i];*/
				/*msort(arr, 0, k);*/ //再次quick sort 超时,直接比较

				ans.pop_back();

				if (arr[i] > ans[k - 2])
				{
					//无需二分插入
					ans.push_back(arr[i]);
				}
				else
				{
					int d = get_left(ans, arr[i]);
					ans.insert(ans.begin() + d, arr[i]);
				}



			}

		}

		//3.min heap 
		return ans;

	}


	vector<int> getLeastNumbers4(vector<int>& arr, int k)
	{
		sort(arr.begin(), arr.end());
		vector<int>ans;
		for (int i = 0; i < k; ++i)
			ans.insert(ans.begin(), arr[i]); //这里的IT自动向后递进，无需加index
		return ans;
	}


	vector<int> getLeastNumbers5(vector<int>& arr, int k)
	{
		sort(arr.begin(), arr.end());
		vector<int>ans;
		for (int i = 0; i < k; ++i)
			ans.emplace(ans.begin(), arr[i]); //这里的IT自动向后递进，无需加index
		return ans;
	}

	//最优
	vector<int> getLeastNumbers6(vector<int>& arr, int k)
	{
		sort(arr.begin(), arr.end());
		vector<int>ans;
		for (int i = 0; i < k; ++i)
			ans.push_back(arr[i]); 
		return ans;
	}


	void msort2(vector<int>&arr, int left, int right,int k)
	{
		if (left + 1 >= right)
			return;
		int L = left;
		std::cout << "hello  l" << L << endl;
		int r = right - 1;
		int key = arr[L];
		std::cout << "hello  container" << L << r << endl;
		while (L < r)
		{
			while (L < r && arr[r] >= key)
				--r;
			arr[L] = arr[r];

			while (L < r && arr[L] <= key)
				L++;
			arr[r] = arr[L];

		}

		arr[L] = key;
		std::cout << "hello 2 container" << L << r << endl;
		if (L == k)
		{
			return;
		}
		else if (L > k)
		{
			msort(arr, left, L);
		}
		else
		{
			msort(arr, L + 1, right);
		}
		
		
	}

	vector<int> getLeastNumbers7(vector<int>& arr, int k)
	{
		
		msort2(arr,0,arr.size(),k);
		vector<int>ans;
		for (int i = 0; i < k; ++i)
			ans.push_back(arr[i]);
		return ans;
	}
	
};
