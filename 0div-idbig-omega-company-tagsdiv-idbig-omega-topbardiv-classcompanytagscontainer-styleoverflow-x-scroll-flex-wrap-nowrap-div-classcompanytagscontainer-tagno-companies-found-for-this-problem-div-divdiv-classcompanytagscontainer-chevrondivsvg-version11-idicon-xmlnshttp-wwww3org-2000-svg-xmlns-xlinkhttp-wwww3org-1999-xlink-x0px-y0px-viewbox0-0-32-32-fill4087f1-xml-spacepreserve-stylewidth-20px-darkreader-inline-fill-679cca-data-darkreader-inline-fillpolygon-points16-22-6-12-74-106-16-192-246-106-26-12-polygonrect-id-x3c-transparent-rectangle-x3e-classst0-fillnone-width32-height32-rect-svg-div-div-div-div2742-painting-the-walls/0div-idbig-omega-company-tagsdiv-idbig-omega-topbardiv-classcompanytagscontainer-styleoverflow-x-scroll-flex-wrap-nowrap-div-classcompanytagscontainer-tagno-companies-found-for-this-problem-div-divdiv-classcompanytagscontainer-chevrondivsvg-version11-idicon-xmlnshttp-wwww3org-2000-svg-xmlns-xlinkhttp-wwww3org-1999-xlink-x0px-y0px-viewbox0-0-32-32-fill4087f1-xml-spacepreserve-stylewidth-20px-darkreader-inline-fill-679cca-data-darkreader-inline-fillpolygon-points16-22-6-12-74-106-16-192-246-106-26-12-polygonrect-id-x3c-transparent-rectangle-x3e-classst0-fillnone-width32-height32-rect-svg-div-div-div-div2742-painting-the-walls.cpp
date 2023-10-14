class Solution {
public:
     int solve(int ind,int n,vector<int>& cost, vector<int>& time,vector<vector<int>>&dp){
        if(n<=0)return 0;
        if(ind>=cost.size())return 1e9;
        if(dp[ind][n]!=-1)return dp[ind][n];
        int Paint=cost[ind]+solve(ind+1,n-1-time[ind],cost,time,dp);
        int noPaint=solve(ind+1,n,cost,time,dp);
        return dp[ind][n]=min(Paint,noPaint);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        vector<vector<int>>dp(cost.size()+1,vector<int>(cost.size()+1,-1));
        return solve(0,cost.size(),cost,time,dp);
    }
};