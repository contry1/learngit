class solution_443_3{
public:
	int is_str(vector<string> &str)
	{
		if (str.size() == 0)
			return 0;

		int cnt = 0;
		string c = str[0];
		int p = 0;
		int i;
		int new_len = 0;
		int flag = 0;
		for (i = 0; i < str.size(); ++i)
		{
			if (str[i] == c)
			{
				cnt++;
				cout << "c:" << c << cnt << endl;
			}
			else
			{

				if (cnt == 1)
				{
					c = str[i];
					str[p + 1] = c;
					p = p + 1;
					
					cnt = 1;
					cout << "l00:" << c << p << cnt << endl;
					continue;
				}
				else if (cnt < 3)
				{
					
					str[p+1] = to_string(cnt);
					p = p + 1;//i;
					str[p + 1] = str[i];
					p = p + 1;//i;
					cout << "200:" << i << p << cnt << endl;
				}
				else if (3<= cnt && cnt< 10)
				{
					
					str[p + 1] = to_string(cnt);
					p = p + 1;//i;
					str[p + 1] = str[i];
					p = p + 1;//i;

					cout << "300:" << i << p << cnt << endl;
				}
				else
				{
					cout << "400:" << i << p << cnt << endl;
					string cur = to_string(cnt);
					for (int j = 0; j < cur.length(); ++j)
					{
						str[p + 1] = cur[j];
						p++;
					}
					str[p + 1] = str[i];
					p = p + 1;//i;

				}

				c = str[i];
				cnt = 1;

			}

		}


		cout << "ff:" << i << p << cnt << endl;
		
		if (cnt>1 && cnt < 3)
		{

			str[p+1] = to_string(cnt);
			p = p + 1;//i;
			cout << "2300:" << i << p << cnt << endl;
		}
		else if (3 <= cnt && cnt < 10)
		{

			str[p + 1] = to_string(cnt);
			p = p + 1;//i;
			

			cout << "3300:" << i << p << cnt << endl;
		}
		else
		{
			cout << "ll:" << i << p << cnt << endl;
			
			string cur = to_string(cnt);
			for (int i = 0; i < cur.length(); ++i)
			{
				str[p + 1] = cur[i];
				p++;
			}
			p--;
			


		}
		
		str.resize(p+1);
		new_len = p+1;



		cout << str.size() << new_len << cnt << endl;

		return new_len;
	}
};




//function 2 ,some question exist

class solution_443 {
public:
	int is_str(vector<string> &str)
	{
		if (str.size() == 0)
			return 0;

		int cnt = 0;
		string c = str[0];
		int p = 0;
		int i;
		int new_len = 0;
		int flag = 0;
		for ( i = 0; i < str.size(); ++i)
		{
			if (str[i] == c)
			{
				//if (flag == 1)
				//{
				//	//cnt = 0;
				//	flag = 0;
				//}
				//else
					cnt++;
				cout << "c:" << c << cnt << endl;
			}
			else
			{
				
				if (cnt == 1)
				{
					p++;
					c = str[i];
					cnt = 1;
					cout << "l00:" << c<< p << cnt << endl;
					continue;
				}
				
				else if (cnt < 10)
				{
					str[p + 1] = to_string(cnt);
					if (i - p - 2 > 0)
					{
						for (int j = p + 2; j + i - p - 2 < str.size(); ++j)
						{
							str[j] = str[j + i - p - 2];
						}

						if (i - p - 2 == 1)
						{
							//cnt = 0;//teshu,ex {"c","d","a","a","a","d","c" };
							cout << "2000:" << i << p << cnt << endl;
							flag = 1;
						}
					}
					
					p = p + 2;//i;
					
					cout << "200:" << i<< p << cnt << endl;
				}
				else
				{
					cout << "ll:" << i << p << cnt << endl;
					string cur = to_string(cnt);
					for (int i = 0; i < cur.length(); ++i)
					{
						str[p + 1] = cur[i];
						p++;
					}
					//p--;
					cout << "22:" << i << p << cnt << endl;
					//if (i - p - 1 > 0)//p-1?
					{
						for (int j = p+1 ; j + i - p-1  < str.size(); ++j)
						{
							str[j] = str[j + i - p-1];
						}
					}
					p = p+1;
				//	i = p;//''''''''''''''
					
				}
			
				c = str[i];
			
				cnt = 1;

			}

		}


		cout << "ff:"<<i << p << cnt << endl;
		i--;

		//last string
		if (cnt == 1)
		{
			/*str[p + 1] = c;*/
			cout << "l00:" << c << p << cnt << endl;
			str.resize(p +1);
			new_len = p +1 ;
		}
			
		else if (cnt < 10)
		{
			str[p + 1] = to_string(cnt);
			str.resize(p+2);
			new_len = p + 2;
		}
		else
		{
			string cur2 = to_string(cnt);
			for (int i = 0; i < cur2.length(); ++i)
			{
				str[p + 1] = cur2[i];
				p++;
			}
			
			str.resize(p);
			new_len = p;
		
		}


		cout << str.size() << new_len << cnt<<endl;
	
		return new_len;
	}
};
