class Solution {
public:
   
    // int findChampionss(vector<vector<int>>& grid) {
    //     int n = grid.size();
    //     vector<int> cnt(n,0);
    //     for(int i=0;i<n;i++)
    //     {
    //         for(int j=0;j<n;j++)
    //         {
    
    void trav(int node,int &cnt, vector<vector<int>> &adj,vector<int> &vis)
    {
       
        vis[node] = 1;
        if(adj[node].empty() ) return ;
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                cnt++;
            trav(it , cnt,adj , vis);
            }
        }
    }
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> ind(n,0);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            ind[edges[i][1]]++;
        }
        for(int i=0;i<n;i++)
        {
            int cnt = 0;
            vector<int> vis(n,0);
           
                trav(i ,cnt , adj , vis);
                if(cnt == n-1) return i;
                
            
        }
        return -1;
        
    }
};