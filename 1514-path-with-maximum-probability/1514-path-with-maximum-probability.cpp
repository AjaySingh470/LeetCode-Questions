class Solution {
public:
    double tot = 0;
    void dfs(int node,double tmp,vector<int> &vis,vector<vector<pair<int,double>>> &adj,int end)
    {
        if(node == end)
        {
            
            tot = max(tot,tmp);
            return ;
        }
        // if(adj[node].empty()) return;
        if(vis[node]) return;
        vis[node] = 1;
        // cout<<tmp<<" ";
        for(auto it : adj[node])
        {
            if(!vis[it.first])
            dfs((it.first) , tmp*it.second ,vis, adj , end);
        }
    }
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
       
        vector<double> ans(n,0.0000);
        ans[start] = 1.0000;
        for(int i=0;i<n-1;i++)
        {
            bool hasChanged = false;
            for(int j=0;j<edges.size();j++)
            {
                int u = edges[j][0] , v = edges[j][1];
                double prob = succProb[j];
                if(ans[u] * prob > ans[v]) { ans[v] = ans[u]*prob; hasChanged = true;}
                if(ans[v] * prob > ans[u]) { ans[u] = ans[v]*prob; hasChanged = true;}
            }
            if(!hasChanged ) break;
        }
        return ans[end];
        
    }
};