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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        vector<double> ans;
        if(!root) return ans;
        q.push(root);
        // int lvl = 0 , sz = 1;
        while(!q.empty())
        {
            int n = q.size();
            double  tot = 0.00;
            double sz = 0;
            for(int i=0;i<n;i++)
            {
                auto it = q.front();
                tot += it->val;
                sz++;
                q.pop();
                if(it->left)
                {
                    q.push(it->left);
                }
                if(it -> right)
                {
                    q.push(it->right);
                }
            }
            ans.push_back(tot/sz);
        }
        return ans;
    }
    
};