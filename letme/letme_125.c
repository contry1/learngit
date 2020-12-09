class solution_125 {
public:
	bool is_str(string str)
	{
		if (str.length() == 0)
			return true;

		int  left = 0;
		int  right = str.length() - 1;

		while (left <= right)
		{

//one fnction
#if 0
			if (!(str[left] >= 'a' &&str[left] <= 'z' || str[left] >= 'A' &&str[left] <= 'Z' || str[left] >= '0' &&str[left] <= '9'))
			{
				cout << "fia left:\t" << str[left] << endl;
				left++;
				continue;
			}

			if (!(str[right] >= 'a' &&str[right] <= 'z' || str[right] >= 'A' &&str[right] <= 'Z' || str[right] >= '0' &&str[right] <= '9'))
			{
				cout << "fia right:\t" << str[right] << endl;
				right--;
				continue;
			}
			
			if ((str[left] >= 'a' &&str[left] <= 'z' || str[left] >= 'A' &&str[left] <= 'Z' || str[left] >= '0' &&str[left] <= '9')
				&& (str[right] >= 'a' &&str[right] <= 'z' || str[right] >= 'A' &&str[right] <= 'Z' || str[right] >= '0' &&str[right] <= '9'))
			{
				
				if (str[left] == str[right]
					|| (int)(str[left]) - int(str[right]) == 32
					|| (int)(str[right]) - int(str[left]) == 32)
				{
					cout << "str[left]:" << (str[left]) << "\tstr[right]:" << str[right] << endl;
					left++;
					right--;
					
				}
				else
				{
					cout << (int)('A') - int('a') << "\t0========str[left]:" << str[left] << "str[right]:" << str[right] << endl;
					return false;
				}
			}

#endif

//two function
			if ((str[left] >= 'a' &&str[left] <= 'z' || str[left] >= 'A' &&str[left] <= 'Z' || str[left] >= '0' &&str[left] <= '9')
				&& (str[right] >= 'a' &&str[right] <= 'z' || str[right] >= 'A' &&str[right] <= 'Z' || str[right] >= '0' &&str[right] <= '9'))
			{
				if (str[left] == str[right]
					|| (int)(str[left]) - int(str[right]) == 32
					|| (int)(str[right]) - int(str[left]) == 32)
				{
					left++;
					right--;
					cout <<"str[left]:"<< str[left]<<"\tstr[right]:"<< str[right]<<endl;
				}
				else
				{
					cout << (int)('A') - int('a')<< "\t0========str[left]:" << str[left] << "str[right]:" << str[right] << endl;
					return false;
				}
			}
			else
			{
				if (!(str[left] >= 'a' &&str[left] <= 'z' || str[left] >= 'A' &&str[left] <= 'Z' || str[left] >= '0' &&str[left] <= '9'))
				{
					cout << "fia left:\t"<<str[left] << endl;
					left++;
				}
			
				if (!(str[right] >= 'a' &&str[right] <= 'z' || str[right] >= 'A' &&str[right] <= 'Z' || str[right] >= '0' &&str[right] <= '9'))
				{
					cout << "fia right:\t" << str[right] << endl;
					right--;
				}
				continue;
			}
			
		}

		return true;

	}
};
