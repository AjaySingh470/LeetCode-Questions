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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *ans = new ListNode(0);
        ListNode *temp = ans ;
        ans->next = head;
        if(right - left == 0) return head;
        int diff = right - left;
        while(left > 1)
        {
            temp = temp->next;
            left--;
        }
        ListNode *ffrg = temp->next;
        ListNode *prev = temp , *curr = temp->next;
        while(diff >= 0)
        {
            ListNode* nxt = curr->next;
         
            curr->next = prev;
            prev = curr;
            curr = nxt;
            diff--;
        }
        temp->next = prev;
        // prev = 
        ffrg->next = curr;
        
        return ans->next;
        
    }
};