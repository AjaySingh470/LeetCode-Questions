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
    int dfs(TreeNode* root,int mx,int mn)
    {
        if(root == NULL)
        return abs(mx-mn);

        mx = max(mx,root->val);
        mn = min(mn,root->val);
        return max(dfs(root->left,mx,mn) , dfs(root->right,mx,mn));
    }

    int maxAncestorDiff(TreeNode* root) {
        if(root == NULL)
        return 0;
        int mx = -1;
        int mn = 10000000;
        return dfs(root,mx,mn);
    }
};