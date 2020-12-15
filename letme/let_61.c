class solution_61 {
public:
	ListNode * rev(ListNode * head, int k)
	{
		//static ListNode * dummy1 = new ListNode;
		ListNode * head1 = head;

		if (NULL == head || head && NULL == head->next)
			return head;
		int len = 1;
		while (head1)
		{

			cout << "ANS->val  :" << endl;
			head1 = head1->next;
			len++;
		}
		len--;
		cout << "ANS->val leb :" << len<< endl;
		if (k == len)
			return head;

		k = k < len ? k : k % len;

		cout << "ANS->val k :" << k << endl;

		ListNode * slow = head;
		ListNode * fast = head;
		ListNode * second_next = head;
		ListNode * prev = NULL;
		
		int num = k;
		while (num--)
		{
			
			fast = fast->next;
			
		}

		int cnt = k;
		while (fast)
		{
		/*	cout << "ANS->val 0 slow:" << slow->val << endl;*/
			prev = slow;
			slow = slow->next;
			cout << "ANS->val slow:" << slow->val<< endl;
			while (cnt--)
			{
				second_next = fast;
				fast = fast->next;
				if (NULL == fast)
				{
					break;
				}
			}
			cnt = k;
		}

		ListNode * first_next = prev->next;
	
		prev->next = NULL;

		second_next->next = head;

		return first_next;
	}
};

class solution_61_2 {
public:
	ListNode * rev(ListNode * head, int k)
	{
		
	

		if (NULL == head || head && NULL == head->next)
			return head;
		int len = 1;
		ListNode * head1 = head;
		while (head1->next)
		{

			cout << "ANS->val  :" << endl;
			head1 = head1->next;
			len++;
		}
		
		cout << "ANS->val leb :" << len << endl;
		if (k == len)
			return head;

		k = k < len ? k : k % len;

		cout << "ANS->val k :" << k << endl;

		ListNode * slow = head;
		ListNode * fast = head;
		//ListNode * second_next = head;
		//ListNode * prev = NULL;

		int num = k;
		while (num--)
		{

			fast = fast->next;

		}
		cout << "ANS->val fast:" << fast->val << endl;
		int cnt = k;
		while (fast->next)
		{
			/*	cout << "ANS->val 0 slow:" << slow->val << endl;*/
			slow = slow->next;
			cout << "ANS->val slow:" << slow->val << endl;
			while (cnt--)
			{
				cout << "ANS->val fast1:" << fast->val << endl;
				fast = fast->next;
				cout << "ANS->val fast2:" << fast->val << endl;
				if (NULL == fast)
				{
					break;
				}
				if (NULL == fast->next)
				{
					slow = slow->next;
					break;
				}
			}
			cnt = k;
		}

		ListNode * first_next = slow->next;

		slow->next = NULL;

		fast->next = head;

		return first_next;
	}
};
