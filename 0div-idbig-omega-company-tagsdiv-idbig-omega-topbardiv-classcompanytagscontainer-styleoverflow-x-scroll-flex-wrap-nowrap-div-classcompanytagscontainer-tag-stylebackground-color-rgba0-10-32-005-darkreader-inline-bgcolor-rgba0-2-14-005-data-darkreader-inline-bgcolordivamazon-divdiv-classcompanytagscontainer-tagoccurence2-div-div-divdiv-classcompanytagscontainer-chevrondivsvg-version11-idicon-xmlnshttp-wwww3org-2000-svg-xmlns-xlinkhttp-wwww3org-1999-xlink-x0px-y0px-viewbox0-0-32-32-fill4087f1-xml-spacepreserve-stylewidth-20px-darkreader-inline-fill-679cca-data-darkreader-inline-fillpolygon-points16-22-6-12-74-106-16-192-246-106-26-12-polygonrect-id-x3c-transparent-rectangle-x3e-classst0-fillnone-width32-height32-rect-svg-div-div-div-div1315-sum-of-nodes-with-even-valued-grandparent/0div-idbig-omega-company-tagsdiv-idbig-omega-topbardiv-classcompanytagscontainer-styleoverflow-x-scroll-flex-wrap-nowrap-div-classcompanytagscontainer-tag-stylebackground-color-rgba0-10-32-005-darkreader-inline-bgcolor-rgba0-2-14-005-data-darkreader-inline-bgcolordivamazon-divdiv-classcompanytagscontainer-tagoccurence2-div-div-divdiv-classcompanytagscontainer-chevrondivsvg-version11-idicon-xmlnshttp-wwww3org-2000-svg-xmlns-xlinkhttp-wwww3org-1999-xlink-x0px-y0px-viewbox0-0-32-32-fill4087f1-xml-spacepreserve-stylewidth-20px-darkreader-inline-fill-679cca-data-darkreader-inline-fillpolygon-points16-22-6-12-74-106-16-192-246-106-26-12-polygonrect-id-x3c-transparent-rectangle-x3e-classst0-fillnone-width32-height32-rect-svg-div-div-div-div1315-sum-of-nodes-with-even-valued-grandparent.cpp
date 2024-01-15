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
    unordered_map<TreeNode*,TreeNode*> parent;
    void createmap(TreeNode* root)
    {
        if(!root) return;
        if(root->left)
        {
            parent[root->left] = root;
            createmap(root->left);
        }
        if(root->right)
        {
            parent[root->right] = root;
            createmap(root->right);
        }
    }
    int sumEvenGrandparent(TreeNode* root) {
        createmap(root);
        int lvl = 0,ans = 0;
        queue<TreeNode*> q;
        if(!root) return 0;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            for(int i=0;i<n;i++)
            {
                auto it = q.front();
                q.pop();
                if(it->left) q.push(it->left);
                if(it->right) q.push(it->right);
                if(lvl >= 2)
                {
                    if(parent[parent[it]]->val % 2 == 0) ans += it->val;
                }
            }
            lvl++;
        }
        return ans;
    }
};