class Solution {
public:
    int ans = 0,mx=0;
    map<int,int> mp;
    int dfs(int node,int n,int cst,vector<int> &cost)
    {
        if(node > n) {
            // mp[cst]++;
            // mx= max(mx , cst);
            return 0;
        }
       int l =dfs(2*node , n , cst + cost[node-1] , cost);
       int r= dfs(2*node + 1 , n , cst + cost[node-1] , cost );
        
        ans += abs(l-r);
        return cost[node-1] + max(l,r); 
    }
    int minIncrements(int n, vector<int>& cost) {
        dfs(1,n,0,cost);
        // return ans-cost[0]>0 ? ans - cost[0] : 0;
        // for(auto it:mp)
        // {
        //     ans += abs(it.first-mx)*it.second;
        // }
        return ans;
    }
};