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
    void parentofNodes(TreeNode* root,map<TreeNode*,TreeNode*> &mp,TreeNode* &tgt,int start)
    {
        if(root == NULL)
            return;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int sz = q.size();
            for(int i=0;i<sz;i++)
            {
                TreeNode* temp = q.front();
                q.pop();
                if(temp->val == start)
                    tgt = temp;
                if(temp->left!=NULL)
                {
                    q.push(temp->left);
                    mp[temp->left] = temp;
                }
                if(temp->right!=NULL)
                {
                    q.push(temp->right);
                    mp[temp->right] = temp;
                }
            }
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*,TreeNode*>  mp;
        TreeNode* tgt;
        parentofNodes(root,mp,tgt,start);
        cout<<tgt->val;
        queue<TreeNode*> q;
        map<TreeNode*,int> visited;
        int ans = 0;
        if(tgt!=NULL)
            q.push(tgt);
        
        while(!q.empty())
        {
            int sz = q.size();
            int flag = 0;
            for(int i=0;i<sz;i++)
            {
                TreeNode* temp = q.front();
                q.pop();
                visited[temp] = 1;
                if(temp->left && !visited[temp->left])
                {
                    flag = 1;
                    q.push(temp->left);
                }
                if(temp->right && !visited[temp->right])
                {
                    flag = 1;
                    q.push(temp->right);
                }
                if(mp[temp] && !visited[mp[temp]])
                {
                    flag = 1;
                    q.push(mp[temp]);
                }
            }
            if(flag==1)
                ans++;
        }
        return ans;
    }
};