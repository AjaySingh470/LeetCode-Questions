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
    int ans = 0;
    void check(TreeNode* root,map<int,int> &mp)
    {
         if(root == NULL)
            return ;
        if(root->left == NULL && root->right == NULL)
        { 
            mp[root->val]++;
            int odd = 0;
            for(auto it:mp)
            {
                if(it.second%2==1)
                    odd++;
            }
            mp[root->val]--;
            if(odd<=1)
                ans++;
            return;
        }
       
        ////////////////////////////
        mp[root->val]++;
        check(root->left,mp);
        check(root->right,mp);
        mp[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        map<int,int> mp;
        check(root,mp);
        return ans;
    }
};