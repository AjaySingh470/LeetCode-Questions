class Solution {
public:
    const int mod = 1e9 + 7;
    vector<vector<int>> dp;
    int solve(int idx,int steps , int len)
    {
        // if(idx > len) return 0;
        if(steps == 0)
        {
            if(idx == 0) return 1;
            return 0;
        }
        if(dp[idx][steps] != -1) return dp[idx][steps];
        int stay = solve(idx , steps-1 , len);
        if(idx >0)
        stay = (stay + solve(idx - 1 , steps-1 , len))%mod;
        if(idx < len - 1)
        stay = (stay + solve(idx+1 , steps-1 , len))%mod;
        return dp[idx][steps] =stay%mod;
    }
    
    int numWays(int steps, int arrLen) {
        arrLen = min(arrLen , steps);
        dp = vector<vector<int>>(arrLen , vector<int>(steps+1 , 0));
        // return solve(0,steps , arrLen);
        dp[0][0] = 1;
        for(int st = 1 ; st<=steps;st++)
        {
        for(int l = arrLen -1 ;l>=0;l--)
            {
                int stay = dp[l][st-1];
                if(l > 0)
                {
                    stay = (stay + dp[l-1][st-1])%mod;
                }
                if(l < arrLen - 1)
                {
                    stay = (stay + dp[l+1][st-1])%mod;
                }
                dp[l][st] = stay;
            }
        }
        return dp[0][steps];
    }
};