class Solution {
public:
    int solve(int idx,vector<int> p,int buy,int n)
    {
        if(idx==n)
            return 0;
        long long profit = 0;
        if(buy)
        {
            profit = max((-p[idx] + solve(idx+1,p,0,n)),0 + solve(idx+1,p,1,n));
        }
        else{
            profit = max(p[idx] + solve(idx+1,p,1,n) , 0 + solve(idx+1,p,0,n));
        }
        return profit;
    }
    int maxProfit(vector<int>& p) {
        int price = 0;
        int n = p.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        dp[n][0] = 0 ; dp[n][1] = 0;
        for(int i=n-1;i>=0;i--)
        {
            for(int buy = 0;buy<=1;buy++)
            {
                if(buy)
                {
                    dp[i][buy] = max((dp[i+1][0] - p[i]),dp[i+1][1] + 0);
                }
                else{
                    dp[i][buy] = max(dp[i+1][1] + p[i] , 0 + dp[i+1][0]);
                }
            }
        }
        // for(int i=0;i<n-1;i++)
        // {
        //     if(p[i]<p[i+1])
        //     {
        //         price += p[i+1] - p[i];
        //     }
        // }
       // return solve(0,p,1,n);
        return dp[0][1];
    }
};