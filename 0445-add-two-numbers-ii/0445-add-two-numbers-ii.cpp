/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1,s2;
        ListNode* h1 = l1 ;
        ListNode* h2 = l2;
        while(h1)
        {
            s1.push(h1->val);
            h1 = h1->next;
        }
        while(h2)
        {
            s2.push(h2->val);
            h2 = h2->next;
        }
        stack<int> fn;
        int  carry = 0;
        ListNode* ans = new ListNode();
        while(!s1.empty() and !s2.empty())
        {
            int x = s1.top() , y = s2.top();
            s1.pop() ; s2.pop();
            int tot =(x + y + carry)%10 ;
            ListNode* tmp = new ListNode(tot);
            carry = (x+y + carry)/10;
            tmp->next = ans->next;
            ans->next = tmp;
        }
        while(!s1.empty())
        {
            int x = s1.top();
            s1.pop();
            ListNode* tmp = new ListNode((x+carry)%10);
            carry = (x+carry)/10;
            tmp->next = ans->next;
            ans->next = tmp;
        }
         while(!s2.empty())
        {
            int x = s2.top();
            s2.pop();
            ListNode* tmp = new ListNode((x+carry)%10);
            carry = (x+carry)/10;
            tmp->next = ans->next;
            ans->next = tmp;
        }
        if(carry)
        {
            int x = carry;
            ListNode* tmp = new ListNode((x)%10);
            carry = (x)/10;
            tmp->next = ans->next;
            ans->next = tmp;
        }
        ans = ans->next;
        return ans;
    }
};