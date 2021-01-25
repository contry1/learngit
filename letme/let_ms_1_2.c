class Solution_ms_1_2 {
public:
	//fc1
	bool CheckPermutation1(string s1, string s2) 
	{
		sort(s1.begin(), s1.end());
		sort(s2.begin(), s2.end());
		return s1 == s2;

	}

	//fc2 stl map
	bool CheckPermutation2(string s1, string s2)
	{
		map<char, int>map1;
		map<char, int>map2;
		for (auto &ch : s1)
			++map1[ch];
		for (auto &ch : s2)
			++map2[ch];
	/*	if(map1.size() != map2.size())
			return false;*/
		
		return map1 == map2;

	}

	//fc2 stl map
	bool CheckPermutation22(string s1, string s2)
	{
		unordered_map<char, int>map1;
		unordered_map<char, int>map2;
		for (auto &ch : s1)
			++map1[ch];
		for (auto &ch : s2)
			++map2[ch];
		/*	if(map1.size() != map2.size())
				return false;*/

		return map1 == map2;

	}
};
