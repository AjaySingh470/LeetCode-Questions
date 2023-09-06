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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode* tmp = head;
        while(tmp)
        {
            n++;tmp = tmp->next;
        }
        int p = n/k,q = n%k;
        vector<ListNode*> v;
        int cnt = 0;
        while(head)
        {
            int tt = p;
            ListNode *temp = new ListNode();
            ListNode *t_head = temp;
            while(tt)
            {
                temp -> next = new ListNode(head->val);
                head = head->next;
                temp = temp->next;
                tt--;
            }
            
            if(q)
            {
                q--;
                temp -> next = new ListNode(head->val);
                    head = head->next;
            }
            v.push_back(t_head->next);
            // delete temp;
        }
        int sz = v.size();
        ListNode *temp = NULL;
        for(int i=sz;i<k;i++)
        {
            v.push_back(temp);
        }
        return v;
    }
};