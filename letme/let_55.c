class solution_55 {
public:

	bool get_left_index(vector<int> path)
	{
		int min1 = 0;
		for (int i = 0; i < path.size(); ++i)
		{
			min1 = max(min1, path[i]);
			if (min1 + i >= path.size()-1)
				return true;

		/*	min1 = max(min1, path[i]+i);
			if (min1 >= path.size()-1)
				return true;*/
		}
		return false;
	}
};
