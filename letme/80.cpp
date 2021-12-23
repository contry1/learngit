letcood 80

class solution {

public:
	int removenum(std::vector<int>& nums)
	{
		if (nums.size() <= 2)
			return nums.size();
		std::deque<int>cursor{nums[0],nums[1]};

		int ret = 0;
		for (auto it = nums.begin()+2; it !=nums.end();) {
			if (cursor.back() == *cursor.begin()) {
				if (*it == cursor.back()) {
					it = nums.erase(it);
				}
				else {
					cursor.pop_front();
					cursor.emplace_back(*it);
					it++;
				}
			}
			else {
				cursor.pop_front();
				cursor.emplace_back(*it);
				it++;
			}
			
		}
		ret = nums.size();
		return ret;

	}

};
