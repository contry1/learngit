class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* head = nullptr;
		ListNode* tail = nullptr;
		int carry = 0;

		while (l1 || l2)
		{
			int a = l1 ? l1->val : 0;
			int b = l2 ? l2->val : 0;

			int sum = a + b + carry;
			if (!head)
			{
				head = tail = new ListNode(sum%10);
			}
			else
			{
				tail->next = new ListNode(sum % 10);
				tail = tail->next;
			}

			carry = sum / 10;

			if (!l1)
			{
				l2 = l2->next;
			}
			else if (!l2)
			{
				l1 = l1->next;
			}
			else
			{
				l1 = l1->next;
				l2 = l2->next;
			}
		}

		if (carry > 0)
		{
			tail->next = new ListNode(carry);
			tail = tail->next;
		}
		return head;
	}
};
