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
    
    bool isLeaf(TreeNode* root)
    {
        return (!root->left and !root->right);
    }
    // int tSum = 0;
    void dfs(TreeNode* root , int targetSum , int tSum,vector<vector<int>> &ans,vector<int> tmp)
    {
        
        if(root == NULL) return;
        if(targetSum == tSum + root->val)
        {
            if(root->left == NULL and root->right == NULL) {
            tmp.push_back(root->val);
                ans.push_back(tmp);
                return;
            }
        
        }
        //
        tmp.push_back(root->val);
        dfs(root->left , targetSum  ,tSum + root->val, ans , tmp);
        dfs(root->right , targetSum  ,tSum + root->val, ans , tmp);
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> tmp;
        int tsm =0 ;
        dfs(root,targetSum ,tsm, ans , tmp);
        return ans;
    }
};