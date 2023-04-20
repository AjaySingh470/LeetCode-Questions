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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL)
             return 0;

        long long int ans = 0;
        queue<pair<TreeNode*,int>> q;
        if(root != NULL)
            q.push({root,0});
        while(!q.empty())
        {
            int sz = q.size();
            long long int mm = q.front().second;
            long long int ff=0,ll=0;
            for(int i=0;i<sz;i++)
            {
                 auto tp = q.front();
                q.pop();
                TreeNode* temp = tp.first;
                long long int lvl = tp.second - mm;
                if(i==0) ff = lvl;
                if(i==sz-1) ll = lvl;
                if(temp->left!=NULL)
                    q.push({temp->left,2*lvl + 1});
                if(temp->right!=NULL)
                    q.push({temp->right,2*lvl+2});
            }
            ans = max(ans,ll-ff+1);
        }
        return ans;
    }
};