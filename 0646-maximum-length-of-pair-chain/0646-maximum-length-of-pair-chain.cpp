class Solution {
public:

    int findLongestChain(vector<vector<int>>& p) {
        sort(p.begin(),p.end());
        int n = p.size();
        vector<int> dp(n,1);
        //
        for(int i=0;i<n;i++)
        {
          for(int j=0;j<i;j++)
          {
            if(p[i][0] > p[j][1])
              dp[i] = max(dp[i] , dp[j] + 1);
          }
        }
      return dp[n-1];
        
    }
};