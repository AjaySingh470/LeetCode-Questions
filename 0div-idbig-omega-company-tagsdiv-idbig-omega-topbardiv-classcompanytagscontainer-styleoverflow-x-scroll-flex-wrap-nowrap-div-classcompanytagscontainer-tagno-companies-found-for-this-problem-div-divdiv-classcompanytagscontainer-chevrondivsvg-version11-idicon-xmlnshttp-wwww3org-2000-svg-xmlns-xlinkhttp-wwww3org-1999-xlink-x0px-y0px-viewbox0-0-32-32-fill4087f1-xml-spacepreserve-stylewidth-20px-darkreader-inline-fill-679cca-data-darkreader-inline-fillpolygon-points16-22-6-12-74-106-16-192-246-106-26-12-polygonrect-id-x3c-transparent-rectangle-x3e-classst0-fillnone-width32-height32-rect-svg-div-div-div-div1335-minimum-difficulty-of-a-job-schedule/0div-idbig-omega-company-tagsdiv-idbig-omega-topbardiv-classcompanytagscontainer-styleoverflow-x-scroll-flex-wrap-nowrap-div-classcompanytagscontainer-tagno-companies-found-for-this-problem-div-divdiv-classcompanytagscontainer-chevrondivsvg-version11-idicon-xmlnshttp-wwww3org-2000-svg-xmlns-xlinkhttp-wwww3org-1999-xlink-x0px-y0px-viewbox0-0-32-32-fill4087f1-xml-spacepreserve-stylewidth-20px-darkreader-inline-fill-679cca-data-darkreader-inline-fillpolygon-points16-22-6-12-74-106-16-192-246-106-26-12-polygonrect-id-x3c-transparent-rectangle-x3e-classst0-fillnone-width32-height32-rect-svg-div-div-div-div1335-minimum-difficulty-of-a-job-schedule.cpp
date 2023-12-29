class Solution {
public:
    vector<vector<int>> dp;
    long long int solve(int idx,int d,vector<int> &jd,vector<vector<int>> &dp)
    {
        if(d < 0) return INT_MAX; 
        if(idx == jd.size())
        {
            if(d > 0) return INT_MAX;
            return 0;
        }
        if(dp[idx][d]!= -1) return dp[idx][d];
        //////////////////////
        int m1 = 0;
        long long int ans = INT_MAX;
        for(int i=idx;i<jd.size();i++)
        {
            m1 = max(m1 , jd[i]);
            ans = min(ans ,m1 + solve(i+1,d-1,jd,dp));
        }
        return dp[idx][d] = ans;
        ////
    }
    
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        dp = vector<vector<int>>(jobDifficulty.size()+1 ,vector<int>(d+1,-1));
        int ans = solve(0,d,jobDifficulty,dp);
        if(ans >= INT_MAX)
            return -1;
        return ans;
    }
};