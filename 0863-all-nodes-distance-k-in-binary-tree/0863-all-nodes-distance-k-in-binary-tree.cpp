/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void parentNodes(TreeNode* root,TreeNode* target,map<TreeNode*,TreeNode*> &parent,TreeNode* &tgt)
    {
        if(root == NULL) return;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int sz = q.size();
           
            for(int i=0;i<sz;i++)
            {
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left!=NULL)
                {
                    q.push(temp->left);
                    parent[temp->left] = temp;
                }
                    
                if(temp->right!=NULL)
                {
                    q.push(temp->right);
                    parent[temp->right] = temp;
                }
                 if(target == temp)
                tgt = temp;
            }
        }
        
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode* , TreeNode*> parent;
        TreeNode* tgt; 
        parentNodes(root,target,parent,tgt);
        map<TreeNode*,int> visited;
        queue<TreeNode*> q;
        if(tgt!=NULL)
        q.push(tgt);
        int dis = 0;
        cout<<tgt->val;
        while(!q.empty())
        {
            int sz = q.size();
            if(dis == k)
                break;
            for(int i=0;i<sz;i++)
            {
                TreeNode* temp = q.front();
                q.pop();
                visited[temp] = 1;
                if(temp->left!=NULL && !visited[temp->left])
                {
                    q.push(temp->left);
                    
                }
                if(temp->right!=NULL && !visited[temp->right])
                    q.push(temp->right);
                if(parent[temp] && !visited[parent[temp]])
                    q.push(parent[temp]);
            }
            dis++;
        }
        vector<int> ans;
        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};