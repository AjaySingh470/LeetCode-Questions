class Solution {
public:
     int findRoot(int n, vector<int>& left, vector<int>& right) {
        unordered_set<int> children;
        children.insert(left.begin(), left.end());
        children.insert(right.begin(), right.end());
        
        for (int i = 0; i < n; i++) {
            if (children.find(i) == children.end()) {
                return i;
            }
        }
        
        return -1;
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int root = findRoot(n,leftChild,rightChild);
        if(root == -1) return false;
        set<int> vis;
        queue<int> q;
        vis.insert(root);
        q.push(root);
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            int ch[] = {leftChild[node] , rightChild[node]};
            for(int c : ch)
            {
                if(c != -1)
                {
                    if(vis.find(c) != vis.end())
                    {
                        return false;
                    }
                    q.push(c);
                    vis.insert(c);
                }
            }
        }
        return vis.size() == n;
    }
};