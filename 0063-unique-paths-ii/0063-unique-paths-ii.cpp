class Solution {
public:
    
    int path(int i,int j,int n,int m,vector<vector<int>> grid,vector<vector<int>> &dp)
    {
        if(i<0 || j<0 || j>=m || i>=n) return 0;
        if(grid[i][j] == 1) return 0;
        if(i==0 && j==0) return 1;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int down = path(i-1,j,n,m,grid,dp);
        int up = path(i,j-1,n,m,grid,dp);
        return dp[i][j] = up + down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1) dp[i][j] = 0;
                else if(i==0 && j==0) dp[i][j] = 1;
                else{
                    int down = 0,up = 0;
                    if(i>0)
                        down = dp[i-1][j];
                    if(j>0)
                        up = dp[i][j-1];
                    dp[i][j] = down + up;
                }
            }
        }
        return dp[n-1][m-1];
        // return path(n-1,m-1,n,m,grid,dp);
    }
};