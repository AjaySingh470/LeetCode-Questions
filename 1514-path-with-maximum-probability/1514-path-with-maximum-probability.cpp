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
        vector<vector<pair<int,double>>> adj(n);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});            
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        vector<double> ans(n,0.0000);
        ans[start] = 1.0000;
        queue<pair<int,double>> pq;
        pq.push({start , 1.0000});
        
        while(!pq.empty())
        {
            int n = pq.size();
            auto it = pq.front();
            pq.pop();
            for(auto i : adj[it.first])
            {
                if(ans[it.first] * i.second > ans[i.first])
                {
                    ans[i.first] = ans[it.first]*i.second;
                    pq.push({i.first,i.second});
                }
            }
        }
        
        
        return ans[end];
        
    }
};