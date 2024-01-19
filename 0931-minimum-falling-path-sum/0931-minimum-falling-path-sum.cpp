class Solution {
public:
    
    int path(int i,int j,int n,vector<vector<int>> &mt , vector<vector<int>> &dp)
    {
        
        if(i<0 || j<0 || j>=n || i>=n) return 1e9;
        if(i == n-1) return mt[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        //
        int right = mt[i][j] + path(i+1,j+1,n,mt,dp);
        int down = mt[i][j] + path(i+1,j,n,mt,dp);
        int left = mt[i][j] + path(i+1,j-1,n,mt,dp);
        return dp[i][j] = min({left,right,down});
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int mn = INT_MAX;
        vector<vector<int>> dp(n,vector<int>(n,0)); 
        vector<int> prev(n,0),curr(n,0);
        for(int i=0;i<n;i++)
        {
            prev[i] = matrix[0][i];
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int right = 1e9,left = 1e9;
                if(j>0)
                 right = matrix[i][j] + prev[j-1];
                int down = matrix[i][j] + prev[j];
                if(j<n-1)
                left = matrix[i][j] + prev[j+1];
                curr[j] = min({right,down,left});
            }
            prev = curr;
        }
        
        for(int i=0;i<n;i++)
        {
            mn = min(mn,prev[i]);
        }
        return mn;
    }
};