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
    set<int> st;
    vector<TreeNode*> recur(int start,int end)
    {
        if(start > end) return {NULL};
        if(start == end) {
            TreeNode* root = new TreeNode(start);
            return {root};
        }
        vector<TreeNode*> result;
        for(int i=start;i<=end;i++)
        {
            vector<TreeNode*> left_tree = recur(start,i-1);
            vector<TreeNode*> right_tree = recur(i+1,end);
            for(auto il : left_tree)
            {
                for(auto ir : right_tree)
                {
                    TreeNode* node = new TreeNode(i);
                    node->left = il;
                    node->right = ir;
                    
                    result.push_back(node);
                }
            }
        }
        return result;
        
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return recur(1,n);
    }
};