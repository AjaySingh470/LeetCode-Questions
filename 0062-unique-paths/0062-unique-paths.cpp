class Solution {
public:
    
    int path(int i,int j,int m,int n,vector<vector<int>> &dp)
    {
        if(i==0 && j==0) return 1;
        
        if(i<0 || j<0 || i>=m || j>=n) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int down = path(i-1,j,m,n,dp);
        int left = path(i,j-1,m,n,dp);
        return dp[i][j] = left + down;
    }
    
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i == 0 && j == 0)
                {
                    dp[i][j] = 1;
                }
                else{
                    int up = 0,left = 0;
                    if(i>0)
                    up = dp[i-1][j];
                    if(j>0)
                     left = dp[i][j-1];
                    
                    dp[i][j] = left + up;
                }
            }
        }
        return dp[m-1][n-1];
    }
};