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
    int calc(TreeNode* root , bool flg , int height)
    {
        if(root == NULL) {
            return 0;
        }
            ans = max(height  , ans);
        int l = 0 , r = 0;
        if(flg)
        {
            l = max(calc(root->left , false , height + 1) , calc(root->right , true , 1 ));
        }
        else{
            r = max(calc(root->right , true , height + 1) , calc(root->left , false , 1 ) );
        }
        return max(l , r );
    }
    
    int longestZigZag(TreeNode* root) {
        int left = calc(root, true , 0);
        int right = calc(root , false , 0);
        return ans;
    }
};