class Solution {
public:
    
    int cnt = 0 , mod = 1e9 + 7;
    int dp[101][101][101];
    int recur(int i,int sm , int people, int minp,vector<int> &group , vector<int> &profit)
    {
        if( i == group.size()) {
            if(sm >= minp && people>=0)
            return 1;
            return 0;
        }
        if(dp[i][sm][people] !=-1)
             return dp[i][sm][people];
        int nottake = recur(i+1,sm,people,minp,group,profit);
        int take = 0;
        if(people - group[i] >= 0)
        take = recur(i+1,min(minp,sm + profit[i]) , people-group[i] ,minp,group , profit);
        return dp[i][sm][people] = (nottake + take)%mod;
        
    }
    
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        
        memset(dp, -1,sizeof(dp));
        //
        return recur(0,0,n,minProfit , group , profit);

    }
};