/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL)
            return head;

        
        ListNode* newhead = new ListNode;
         
         if(head->val == val)
         {
        //     head->next = head->next->next;
             newhead->next = head->next;
         }

      
        newhead->next = head;
        head = removeElements(head->next,val);
      

       
         return head;

    }
};
