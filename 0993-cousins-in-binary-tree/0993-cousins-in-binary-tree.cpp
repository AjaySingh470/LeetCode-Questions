/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
      if(x == root->val || y == root->val) return false;
      q.push(root);
      TreeNode* parx = NULL ;
      TreeNode* pary = NULL;
      while(!q.empty())
      {
        int n = q.size();
        bool xf = false , yf = false;
        for(int i=0;i<n;i++)
        {
          auto it = q.front(); q.pop();
          int node = it->val;
          if(it->left)
          {
            q.push(it->left);
            if(it->left->val == x) {
              xf = true;
              parx = it;
            }
            if(it->left->val == y)
            {
              yf = true;
              pary = it;
            }
          }
          if(it->right)
          {
            q.push(it->right);
            if(it->right->val == x)
            {
              xf = true;
              parx = it;
            }
            if(it->right->val == y)
            {
              yf = true;
              pary = it;
            }
          }
          
        }
        if(xf && yf && parx != pary) return true;
        if(xf || yf) return false;
      }
      return false;
    }
};