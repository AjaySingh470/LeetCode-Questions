class Solution {
public:
    int ans = 0;
    
    void dfs(int idx ,int cnt, vector<vector<int>> &adj,vector<int> &tmp)
    {
        if(idx == adj.size())
        {
            for(auto it : tmp) if(it != 0) return;
            ans = max( cnt ,ans);
            return;
        }
        // nottake
        dfs(idx+1,cnt,adj,tmp);
        // take
        tmp[adj[idx][0]]--;
        tmp[adj[idx][1]]++;
        dfs(idx+1,cnt+1,adj,tmp);
        tmp[adj[idx][1]]--;
        tmp[adj[idx][0]]++;
        return;
    }
    
    int maximumRequests(int n, vector<vector<int>>& requests) {
        
        ans = 0;
        vector<int> tmp(n,0);
        dfs(0,0,requests,tmp);
        return ans;
        
    }
};