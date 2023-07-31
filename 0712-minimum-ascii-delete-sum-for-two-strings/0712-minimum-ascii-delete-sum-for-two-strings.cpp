class Solution {
public:
    
    int recur(int i,int j,string s1,string s2,vector<vector<int>> &dp)
    {
        if(i == s1.size() || j == s2.size())
        {
            int tsm = 0;
            for(int k=i;k<s1.size();k++)
            {
                tsm += (int)s1[k];
            }
            for(int k=j;k<s2.size();k++)
            {
                tsm += (int)s2[k];
            }
            
            return tsm;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int ff = INT_MAX , ss = INT_MAX;
        if(s1[i] == s2[j])
        {
            return dp[i][j] = recur(i+1,j+1,s1,s2,dp);
        }
        return dp[i][j] = min((int)s1[i] + recur(i+1,j,s1,s2,dp) , (int)s2[j] + recur(i,j+1,s1,s2,dp));
        
    }
    
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size() , m = s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        // return recur(0,0,s1,s2,dp);
        for(int i=n-1;i>=0;i--)
        {
            dp[i][m] += (int)s1[i] + dp[i+1][m];
        }
        for(int i=m-1;i>=0;i--)
        {
            dp[n][i] += (int)s2[i] + dp[n][i+1];
        }
        ///
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(s1[i] == s2[j])
                {
                    dp[i][j] = dp[i+1][j+1];
                }
                else{
                    dp[i][j] = min((int)s1[i] + dp[i+1][j] , (int)s2[j] + dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
};