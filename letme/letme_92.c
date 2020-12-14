ListNode * m_node;
ListNode * n_node;
class solution {
public:
	ListNode * rev(ListNode * head, int m, int n)
	{
		if (head == NULL)
			return head;


		
		ListNode * head2 = head;
		int k = 1;
		do {
			if (k == m)
				 m_node = head;
			if (k == n)
			{
				n_node = head;
				break;
			}
			head = head->next;
			k++;
		} while (head);

		static ListNode * dummy1 = new ListNode;
		dummy1->next = head2;
		cout << "ANS->val 0:" << endl;
		while (dummy1->next != m_node)
		{
			cout << "ANS->val 5:" << endl;
			dummy1 = dummy1->next;
		}
		cout << "ANS->val 10:" << endl;
		dummy1->next = n_node;
		ListNode * cursor = m_node->next;

		m_node->next = n_node->next;
		cout << "ANS->val 20:" << cursor->val<< endl;

		ListNode * p;
		while (cursor != n_node)
		{
		//	m_node->next = NULL;
			p = cursor->next;
			cursor->next = m_node;
			m_node = cursor;
			cursor = p;
			cout << "ANS->val 220:" << cursor->val<<endl;
		}

		cursor->next = m_node;
		cout << "ANS->val 30:" << endl;

#if 0
		if (dummy1->next != head2)
		{
			cout << "ANS->val 40:" << endl;
			return dummy1->next;
		//	return head2;
		}
			
		else
		{

			cout << "ANS->val 50:" << endl;
			return dummy1->next;
		}
#endif
		return dummy1->next;

	}
};
