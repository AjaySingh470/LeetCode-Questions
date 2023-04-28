class Solution {
public:
    bool samehai(string &s1 , string &s2)
    {
        int diff =0 ;
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i] != s2[i]) diff++;
        }
        return (diff == 0 || diff == 2);
    }    
        
    void dfs(int i,vector<vector<int>> &adj,vector<bool> &vis)
    {
        vis[i] = true;
        for(auto it : adj[i])
        {
            if(!vis[it])
            dfs(it , adj , vis);
        }
    }
        
    int numSimilarGroups(vector<string>& strs) {
        int ans = 0;
        vector<vector<int>> adj(strs.size());
        for(int i=0;i<strs.size();i++)
        {
            for(int j=i+1;j<strs.size();j++)
            {
                if(samehai(strs[i] , strs[j]))
                {
                    adj[i].push_back(j);                    
                    adj[j].push_back(i);
                }
            }
        }
        int cnt = 0;
        vector<bool> vis(strs.size(),false);
        for(int i=0;i<strs.size();i++)
        {
            if(!vis[i])
            {
                dfs(i,adj,vis);
                cnt++;
            }
        }
        return cnt;
    }
};