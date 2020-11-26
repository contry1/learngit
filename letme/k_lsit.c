ListNode * mergelist(vector<ListNode *> &lists)
{
	return merge(lists,0,lists.size()-1);
}

ListNode * merge(vector<ListNode *> &lists, int left, int right)
{
	if (left == right)
		return lists[left];
	if (left > right)
		return NULL;
	int mid = (left + right) >> 1;
	return merge_two(merge(lists,0,mid), merge(lists, mid+1, right));
}


ListNode * merge_two(ListNode *a, ListNode *b)
{
	ListNode * head;
//	ListNode * cur = head;

	if (a->value <= b->value)
	{
		head = a;
		head->next = merge_two(a->next,b);
	}
	else
	{
		head = b;
		head->next = merge_two(a, b->next);
	}
//	return cur;
	return head;
}
