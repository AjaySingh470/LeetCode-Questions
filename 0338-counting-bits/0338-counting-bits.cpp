class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1,0);
        for(int i=1;i<=n;i++)
        {
            int sq = log2(i);
            cout<<sq<<" ";
            
            
                int idx = i - pow(2,sq);
                dp[i] = 1 + dp[idx];
            
        }
        return dp;
    }
};