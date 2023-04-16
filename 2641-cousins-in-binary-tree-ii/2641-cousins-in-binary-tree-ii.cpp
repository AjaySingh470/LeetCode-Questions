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
    TreeNode* replaceValueInTree(TreeNode* root) {
        map<long long int,long long int> v;
      queue<TreeNode*> q;
      q.push(root);
      int ht =0;
      while(!q.empty())
      {
        int curr = 0;
        int n = q.size();
        for(int i=0;i<n;i++)
        {
          auto it = q.front();
          q.pop();
          curr += it->val;
          if(it->left) q.push(it->left);
          if(it->right) q.push(it->right);
          //
        }
        v[ht] = curr;
        ht++;
      }
      int height = 0;
      q = queue<TreeNode*>();
      q.push(root);
      root->val = 0;
      // for(auto it:v) cout<<it<<" "; cout<<endl;
      while(!q.empty())
      {
        int n = q.size();
        for(int i=0;i<n;i++)
        {
          auto it = q.front();
          q.pop();
          int csum = 0;
          if(it->left)
          {  
            q.push(it->left);
            csum += it->left->val;
          }
          if(it->right)
          {
            q.push(it->right);
            csum += it->right->val;
          }
          // cout<<csum<<" ";
          int rem = v[height + 1] - csum;
          if(it->left)
          it->left->val = rem;
          if(it->right)
          it->right->val = rem;
        }
        height++;
      }
      return root;
    }
};