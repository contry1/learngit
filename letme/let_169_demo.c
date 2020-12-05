class solution_169 {
public:

	int get_many(vector<int> nums)
	{
		int len = nums.size();
		/*遇到不同的数减一，相同的加一。 值为0，换一个数继续这样彼此消耗最后那一个就是众数*/
	/*	while (1)
		{*/
			int many ;
			int cnt = 0;
			for (int i = 0; i < len; ++i)
			{
				if(cnt == 0)
					many = nums[i];
				if (nums[i] == many)
				{
					cnt++;
				}
				else
				{
					cnt--;
				}


			}

		

			
	/*	}*/
		
			return many;
	}
};
