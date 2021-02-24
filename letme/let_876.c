class Solution_876 {
public:
	ListNode* middleNode(ListNode* head)
	{
		ListNode* slow = head;
		ListNode* fast = head;

		while (fast)
		{
			
			if (fast->next)
				fast = fast->next->next;
			else
				break;
			slow = slow->next;
		}

		return slow;
	}
};
