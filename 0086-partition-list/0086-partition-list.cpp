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
    ListNode* partition(ListNode* head, int x) {
        
        ListNode* less = new ListNode(0);
        ListNode* more = new ListNode(0);
        ListNode* temp = head;
        ListNode* less_head = less ;
        ListNode* more_head = more;
        while(temp != NULL)
        {
            if(temp->val < x)
            {
                less->next = temp;
                less = less->next;
            }
            else if(temp->val >= x)
            {
                more->next = temp;
                more = more->next;
            }
            temp = temp->next;
        }
        
        more->next = NULL;
        less->next = more_head->next;
        return less_head->next;
    }
};