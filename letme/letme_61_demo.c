class solution_61_3 {
public:
	ListNode * rev(ListNode * head, int k)
	{
		ListNode * head1 = head;

		if (NULL == head || head && NULL == head->next)
			return head;
		int len = 1;
		ListNode * tail = NULL;
		while (head1)
		{
			tail = head1;
			head1 = head1->next;
			len++;
		}
		len--;
		cout << "ANS->val len :" << len << endl;
		if (k % len == 0)
			return head;

		k = k < len ? k : k % len;

		cout << "ANS->val k :" << k << endl;

		ListNode * slow = head;
		ListNode * prev = NULL;

		int slow_index = len - k;
		while (slow_index--)
		{
			prev = slow;
			slow = slow->next;

		}

		

		ListNode * first_next;
		first_next = prev->next;
		prev->next = NULL;
		tail->next = head;
		return first_next;
	}
};


class solution_61_4 {
public:
	ListNode * rev(ListNode * head, int k)
	{
	

		if (NULL == head || head && NULL == head->next)
			return head;
		int len = 1;

		ListNode * tail = head;
		while (tail->next)
		{
			len++;
			tail = tail->next;	
		}

	/*	line 664 -669 is equal to the below
		ListNode * tail = NULL;
		while (head1)
		{
			tail = head1;
			head1 = head1->next;
			len++;
		}
		len--;*/
	
		if (k % len == 0)
			return head;

		k = k < len ? k : k % len;


		ListNode * prev = head;
		int prev_index = len - k;
		while (--prev_index)
		{
			prev = prev->next;

		}

		//line 696 -line 702  is equal the below
	/*	ListNode * slow = head;

		ListNode * prev = NULL;

		int slow_index = len - k;
		while (slow_index--)
		{
			prev = slow;
			slow = slow->next;

		}*/

		ListNode * first_next;
		first_next = prev->next;
		prev->next = NULL;
		tail->next = head;
		return first_next;
	
	}
};
