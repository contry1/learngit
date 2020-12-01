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



class Solution {
public:
    vector<string> ans;
    string path;
   void dfs(int left,int right,int n )
    {
       if(left == n &&right ==n)
       {
           ans.push_back(path);
           return;
       }
       if(right>left)
            return;
        for(int i = left;i<n;++i)
        {
            if(i>left &&path[i] == path[i-1])
            continue;
            path.push_back('(');
            dfs(left+1,right,n);
            path.pop_back();
        }
          for(int i = right;i<n;++i)
        {
             if(i>right &&path[i] == path[i-1])
            continue;
            path.push_back(')');
            dfs(left,right+1,n);
            path.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        dfs(0,0,n);
        return ans;
    }
};
