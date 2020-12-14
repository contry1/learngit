class solution_22 {
public:
	ListNode * rev(ListNode * head1, ListNode * head2)
	{
		static ListNode * dummy1 = new ListNode;
		ListNode * head = dummy1;
		int skip = 0;
		while (head1 || head2 || skip) //还有可能存在一种情况，链表已经访问完成，但是有一个进位skip，所以需要重新添加一个节点
		{
			if (head1 && head2)
			{
				cout << "ANS->val 0:" << endl;
				dummy1->val = head1->val + head2->val + skip;
				if (head1->val + head2->val + skip > 9)
				{
					dummy1->val = (head1->val + head2->val + skip) % 10; //为何要加上skip，可能会存在多个连续进位情况
					skip = (head1->val + head2->val+skip) / 10;
				}
				dummy1->next = new ListNode;
				dummy1 = dummy1->next;

				head1 = head1->next;
				head2 = head2->next;
			}
			else if (head1 &&NULL == head2)
			{
				dummy1->val = head1->val + skip;

				if (head1->val  + skip > 9)
				{
					dummy1->val = (head1->val  + skip) % 10; //为何要加上skip，可能会存在多个连续进位情况
					skip = head1->val + skip / 10;
				}
				
				dummy1->next = new ListNode;
				dummy1 = dummy1->next;

				head1 = head1->next;
			}
			else if (head2 &&NULL == head1)
			{
				dummy1->val = head2->val + skip;

				if (head2->val + skip > 9)
				{
					dummy1->val = (head2->val + skip) % 10; //为何要加上skip，可能会存在多个连续进位情况
					skip = head2->val + skip / 10;
				}

				
				dummy1->next = new ListNode;
				dummy1 = dummy1->next;

				head2 = head2->next;
			}
			else if (NULL == head1 && NULL == head1 && skip)
			{
				cout << "ANS->val 4:" << endl;
				dummy1->val = skip;
				dummy1->next = NULL;
				break;
			}

		}

		dummy1 = NULL; //此时是DUMMY1 NEXT node ,so it be null

		return head;
	}
};


class solution_222 {
public:
	ListNode * rev(ListNode * head1, ListNode * head2)
	{
		static ListNode * dummy1 = new ListNode;
		ListNode * head = dummy1;
		int skip = 0;
		while (head1 || head2) //还有可能存在一种情况，链表已经访问完成，但是有一个进位skip，所以需要重新添加一个节点
		{
			if (head1 && head2)
			{
				cout << "ANS->val 0:" << endl;
				dummy1->val = head1->val + head2->val + skip;
				if (head1->val + head2->val + skip > 9)
				{
					dummy1->val = (head1->val + head2->val + skip) % 10; //为何要加上skip，可能会存在多个连续进位情况
					skip = (head1->val + head2->val + skip) / 10;
				}
				dummy1->next = new ListNode;
				dummy1 = dummy1->next;

				head1 = head1->next;
				head2 = head2->next;
			}
			else if (head1 &&NULL == head2)
			{
				dummy1->val = head1->val + skip;

				if (head1->val + skip > 9)
				{
					dummy1->val = (head1->val + skip) % 10; //为何要加上skip，可能会存在多个连续进位情况
					skip = head1->val + skip / 10;
				}

				dummy1->next = new ListNode;
				dummy1 = dummy1->next;

				head1 = head1->next;
			}
			else if (head2 &&NULL == head1)
			{
				dummy1->val = head2->val + skip;

				if (head2->val + skip > 9)
				{
					dummy1->val = (head2->val + skip) % 10; //为何要加上skip，可能会存在多个连续进位情况
					skip = head2->val + skip / 10;
				}


				dummy1->next = new ListNode;
				dummy1 = dummy1->next;

				head2 = head2->next;
			}
			

		}
	 if (NULL == head1 && NULL == head1 && skip)
		{
			cout << "ANS->val 4:" << skip<< endl;
			dummy1->val = skip;
			dummy1->next = NULL;
		}else
			dummy1 = NULL;//此时是DUMMY1 NEXT node ,so it be null

		return head;
	}
};
