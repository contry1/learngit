ListNode * del2(ListNode *head, int val)
{
	if (NULL == head)
		return head;

	if (head->val == val)
	{
		head = head->next;

	/*	if(head)
			head->next = del(head, val);
		else
			head = del(head, val);*/

		//above is debuging is equal
		head = del(head, val); 
	
	}

	
	/*if (NULL == head)
		return head;*/
	head->next = del(head->next, val);
	return head;
}


ListNode * del3(ListNode *head, int val)
{
	if (NULL == head)
		return head;

	if (head->val == val)
	{
		/*head = head->next;*/

		/*	if(head)
				head->next = del(head, val);
			else
				head = del(head, val);*/

				//above is debuging is equal
		head = del(head->next, val);

	}


	/*if (NULL == head)
		return head;*/
	head->next = del(head->next, val);
	return head;
}
