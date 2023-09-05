/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
     
        
        Node* temp = head;
        map<Node*,Node*> mp;
        while(temp)
        {
            Node *tp = new Node(temp->val);
            mp[temp] = tp;
            temp = temp->next;
        }
        
        temp = head;
        Node* first = mp[temp];
        Node* ans = first;
        while(temp)
        {
            first->next = mp[temp->next];
            first->random = mp[temp->random];
            first = first->next;
            temp = temp->next;
        }
            
        return ans;
            
            
            
            
    }
};