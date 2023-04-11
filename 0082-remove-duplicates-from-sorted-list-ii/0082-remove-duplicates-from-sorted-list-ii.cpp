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
    ListNode* deleteDuplicates(ListNode* head) {
      ListNode* temp = new ListNode(0,head);
      ListNode* pred = temp;
      while(head)
      {
        if(head->next and head->val == head->next->val)
        {
          while(head->next and head->val == head->next->val)
          {
            head = head -> next;
          }
          // here we are skipping the repeated elements..
          pred->next = head->next;
        }
        else{
         // if above is false then just move forward..
          pred = pred->next;
        }
        // move forward
        head = head -> next;
      }
      return temp->next;
    }
};