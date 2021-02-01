class Solution_888 {
public:
	//1.暴力线性，timeout
	vector<int> fairCandySwap(vector<int>& A, vector<int>& B) 
	{
		int suma = 0;
		int sumb = 0;

		for (auto &a : A)
		{
			suma += a;
		}

		for (auto &b : B)
		{
			sumb += b;
		}

		vector<int>ans;
		int ex = (suma + sumb) >> 1;
		if (ex >= suma)
		{
			for (int i = 0; i < A.size(); ++i)
			{
				
				for (int j = 0; j < B.size(); ++j)
				{
					if (B[j] == A[i] + ex - suma)
					{
						ans.push_back(A[i]);
						ans.push_back(B[j]);
						return ans;
					}
				}
			}
			
		
		}

		else //if (ex >= sumb)
		{
			for (int i = 0; i < B.size(); ++i)
			{
				for (int j = 0; j < A.size(); ++j)
				{
					if (A[j] == B[i] + ex - sumb)
					{
						ans.push_back(A[j]);
						ans.push_back(B[i]);
						
						return ans;
					}
				}
			}
		}

		return ans;
	

	}




	//2.A,B sort，then  binary search
	vector<int> fairCandySwap(vector<int>& A, vector<int>& B)
	{
		int suma = 0;
		int sumb = 0;
		sort(A.begin(),A.end());
		sort(B.begin(), B.end());
		for (auto &a : A)
		{
			suma += a;
		}

		for (auto &b : B)
		{
			sumb += b;
		}

		vector<int>ans;
		int ex = (suma + sumb) >> 1;
		if (ex >= suma)
		{
			for (int i = 0; i < A.size(); ++i)
			{
				int left = 0;
				int right = B.size();
				while(left <right)
				//for (int j = 0; j < B.size(); ++j)
				{
					int mid = (left + right) >> 1;
					if (B[mid] == A[i] + ex - suma)
					{
						ans.push_back(A[i]);
						ans.push_back(B[mid]);
						return ans;
					}
					else if (B[mid] > A[i] + ex - suma)
					{
						right = mid-1;
					}
					else if (B[mid] < A[i] + ex - suma)
					{
						left = mid + 1;
					}

				}
				if (B[left] == A[i] + ex - suma)
				{
					ans.push_back(A[i]);
					ans.push_back(B[left]);
					return ans;
				}
			}


		}

		else //if (ex >= sumb)
		{
			for (int i = 0; i < B.size(); ++i)
			{
				int left = 0;
				int right = A.size();
				while (left < right)
			/*	for (int j = 0; j < A.size(); ++j)*/
				{
					int mid = (left + right) >> 1;
					if (A[mid] == B[i] + ex - sumb)
					{
						ans.push_back(A[mid]);
						ans.push_back(B[i]);

						return ans;
					}
					else if (A[mid] > B[i] + ex - sumb)
					{
						right = mid - 1;
					}
					else if (A[mid] < B[i] + ex - sumb)
					{
						left = mid + 1;
					}
				}

				if (A[left] == B[i] + ex - sumb)
				{
					ans.push_back(A[left]);
					ans.push_back(B[i]);
					return ans;
				}
			}
		}

		return ans;


	}

	//3 闭区间
	vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
		int suma = 0;
		int sumb = 0;

		sort(A.begin(), A.end());
		sort(B.begin(), B.end());
		for (auto &a : A)
		{
			suma += a;
		}

		for (auto &b : B)
		{
			sumb += b;
		}

		vector<int>ans;
		int ex = (suma + sumb) >> 1;
		if (ex >= suma)
		{

			for (int i = 0; i < A.size(); ++i)
			{
				int left = 0;
				int right = B.size();
				while (left <= right)
					//for (int j = 0; j < B.size(); ++j)
				{
					int mid = (left + right) >> 1;
					if (B[mid] == A[i] + ex - suma)
					{
						ans.push_back(A[i]);
						ans.push_back(B[mid]);
						return ans;
					}
					else if (B[mid] > A[i] + ex - suma)
					{
						right = mid - 1;
					}
					else if (B[mid] < A[i] + ex - suma)
					{
						left = mid + 1;
					}

				}

			}


		}

		else //if (ex >= sumb)
		{

			for (int i = 0; i < B.size(); ++i)
			{
				int left = 0;
				int right = A.size();
				while (left <= right)
					/*	for (int j = 0; j < A.size(); ++j)*/
				{
					int mid = (left + right) >> 1;
					if (A[mid] == B[i] + ex - sumb)
					{
						ans.push_back(A[mid]);
						ans.push_back(B[i]);

						return ans;
					}
					else if (A[mid] > B[i] + ex - sumb)
					{
						right = mid - 1;
					}
					else if (A[mid] < B[i] + ex - sumb)
					{
						left = mid + 1;
					}
				}


			}
		}

		return ans;


	}
	
	}
};
