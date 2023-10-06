class Solution {
public:
    vector<int> dp;
    int solve(int n)
    {
        if(n <= 3) return n;
        if(dp[n]!=-1) return dp[n];
        int ans = 0;
        for(int i=2;i<n;i++)
        {
            ans = max(ans , i * solve(n - i));
        }
        return dp[n] = ans;
    }
    
    int integerBreak(int n) {
        dp = vector<int>(n+1,-1);
        if(n <= 3) return n-1;

        int ans = solve(n);
        return ans;
    }
};