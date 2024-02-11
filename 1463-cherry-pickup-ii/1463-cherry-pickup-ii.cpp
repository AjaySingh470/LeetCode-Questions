class Solution {
public:
    vector<vector<vector<int>>> dp;
    int solve(int r,int c1,int c2,vector<vector<int>> &grid,int n,int m)
    {
        if(r == n) return 0;
        if(dp[r][c1][c2] != -1)
            return dp[r][c1][c2];
        int ans = 0;
        for(int i=-1;i<=1;i++)
        {
            for(int j=-1;j<=1;j++)
            {
                int nc1 = c1 + i , nc2 = c2 + j;
                if(nc1 < 0 || nc2 < 0 || nc1 >= m || nc2 >= m)
                    continue;
                ans = max(ans , solve(r+1,nc1,nc2,grid,n,m));
            }
        }
        return dp[r][c1][c2] = (c1 == c2 ? grid[r][c1] : grid[r][c2] + grid[r][c1]) + ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        dp = vector<vector<vector<int>>>(grid.size() , vector<vector<int>>(grid[0].size(),vector<int>(grid[0].size(),-1)));
        return solve(0,0,grid[0].size()-1,grid,grid.size() , grid[0].size());
    }
};