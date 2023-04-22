class Solution {
public:
    int lcs(string text1, string text2) {
        int n = text1.size(),m = text2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
               if(text1[i-1] == text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                
               else dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                
            }
        }
        //return solve(n-1,m-1,text1,text2,dp);
        return dp[n][m];
    }
    int minInsertions(string s) {
        string t = s;
        int n = s.size();
        reverse(t.begin(),t.end());
        return (n - lcs(t,s));
    }
};