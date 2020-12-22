class solution_61_5 {
public:
	ListNode * rev(ListNode * head)
	{
		//FUNCTION1 
		//ListNode * head1 = head;
		//if (head == NULL|| head->next == NULL)
		//	return head;
		//ListNode * node = rev(head->next); //head->next;

		//ListNode * p = head->next;
		//p->next = head;
		//head->next = NULL;
		//return  node;
		
		return rev2(head,NULL);
	}

	//FUNCTION 2
	ListNode * rev2(ListNode * head, ListNode *prev)
	{
		if (head == NULL)
			return prev;
	
		ListNode * node = head->next;
		head->next = prev;

		return  rev2(node,head);

	}

	ListNode * rev3(ListNode * head)
	{
		ListNode * prev = NULL;
		ListNode * next;

		//while (head->next)
		//{
		//
		//	next = head->next;
		//	head->next = prev;
		//	prev = head; 
		//	head = next;
		//	
		//}
		//head->next = prev;
		//return  head;

		//line796 - line 806 is equal to the below
		while (head)
		{

			next = head->next;
			head->next = prev;
			prev = head;
			head = next;

		}
		return  prev;

	}

	ListNode * rev4(ListNode * head)
	{
		if (head == NULL|| head&&head->next == NULL)
			return head;
		if (head && head->next && head->next->next == NULL)
		{
			ListNode *node = head->next;
			head = head->next->next;
			node->next = head;
			return node;

		}
	
		ListNode * p = head->next;
		ListNode * next = head->next->next;

		int i = 0;
		while (p)
		{
			if (i == 0)
				head->next = NULL;
			p->next = head ;
			
			if (next == NULL)
				break;
			head = p;
			p = next;
			
			next = next->next;
			i++;
		}
		//head->next = NULL;
	/*	p->next = head;*/
		return  p;

	}
};
