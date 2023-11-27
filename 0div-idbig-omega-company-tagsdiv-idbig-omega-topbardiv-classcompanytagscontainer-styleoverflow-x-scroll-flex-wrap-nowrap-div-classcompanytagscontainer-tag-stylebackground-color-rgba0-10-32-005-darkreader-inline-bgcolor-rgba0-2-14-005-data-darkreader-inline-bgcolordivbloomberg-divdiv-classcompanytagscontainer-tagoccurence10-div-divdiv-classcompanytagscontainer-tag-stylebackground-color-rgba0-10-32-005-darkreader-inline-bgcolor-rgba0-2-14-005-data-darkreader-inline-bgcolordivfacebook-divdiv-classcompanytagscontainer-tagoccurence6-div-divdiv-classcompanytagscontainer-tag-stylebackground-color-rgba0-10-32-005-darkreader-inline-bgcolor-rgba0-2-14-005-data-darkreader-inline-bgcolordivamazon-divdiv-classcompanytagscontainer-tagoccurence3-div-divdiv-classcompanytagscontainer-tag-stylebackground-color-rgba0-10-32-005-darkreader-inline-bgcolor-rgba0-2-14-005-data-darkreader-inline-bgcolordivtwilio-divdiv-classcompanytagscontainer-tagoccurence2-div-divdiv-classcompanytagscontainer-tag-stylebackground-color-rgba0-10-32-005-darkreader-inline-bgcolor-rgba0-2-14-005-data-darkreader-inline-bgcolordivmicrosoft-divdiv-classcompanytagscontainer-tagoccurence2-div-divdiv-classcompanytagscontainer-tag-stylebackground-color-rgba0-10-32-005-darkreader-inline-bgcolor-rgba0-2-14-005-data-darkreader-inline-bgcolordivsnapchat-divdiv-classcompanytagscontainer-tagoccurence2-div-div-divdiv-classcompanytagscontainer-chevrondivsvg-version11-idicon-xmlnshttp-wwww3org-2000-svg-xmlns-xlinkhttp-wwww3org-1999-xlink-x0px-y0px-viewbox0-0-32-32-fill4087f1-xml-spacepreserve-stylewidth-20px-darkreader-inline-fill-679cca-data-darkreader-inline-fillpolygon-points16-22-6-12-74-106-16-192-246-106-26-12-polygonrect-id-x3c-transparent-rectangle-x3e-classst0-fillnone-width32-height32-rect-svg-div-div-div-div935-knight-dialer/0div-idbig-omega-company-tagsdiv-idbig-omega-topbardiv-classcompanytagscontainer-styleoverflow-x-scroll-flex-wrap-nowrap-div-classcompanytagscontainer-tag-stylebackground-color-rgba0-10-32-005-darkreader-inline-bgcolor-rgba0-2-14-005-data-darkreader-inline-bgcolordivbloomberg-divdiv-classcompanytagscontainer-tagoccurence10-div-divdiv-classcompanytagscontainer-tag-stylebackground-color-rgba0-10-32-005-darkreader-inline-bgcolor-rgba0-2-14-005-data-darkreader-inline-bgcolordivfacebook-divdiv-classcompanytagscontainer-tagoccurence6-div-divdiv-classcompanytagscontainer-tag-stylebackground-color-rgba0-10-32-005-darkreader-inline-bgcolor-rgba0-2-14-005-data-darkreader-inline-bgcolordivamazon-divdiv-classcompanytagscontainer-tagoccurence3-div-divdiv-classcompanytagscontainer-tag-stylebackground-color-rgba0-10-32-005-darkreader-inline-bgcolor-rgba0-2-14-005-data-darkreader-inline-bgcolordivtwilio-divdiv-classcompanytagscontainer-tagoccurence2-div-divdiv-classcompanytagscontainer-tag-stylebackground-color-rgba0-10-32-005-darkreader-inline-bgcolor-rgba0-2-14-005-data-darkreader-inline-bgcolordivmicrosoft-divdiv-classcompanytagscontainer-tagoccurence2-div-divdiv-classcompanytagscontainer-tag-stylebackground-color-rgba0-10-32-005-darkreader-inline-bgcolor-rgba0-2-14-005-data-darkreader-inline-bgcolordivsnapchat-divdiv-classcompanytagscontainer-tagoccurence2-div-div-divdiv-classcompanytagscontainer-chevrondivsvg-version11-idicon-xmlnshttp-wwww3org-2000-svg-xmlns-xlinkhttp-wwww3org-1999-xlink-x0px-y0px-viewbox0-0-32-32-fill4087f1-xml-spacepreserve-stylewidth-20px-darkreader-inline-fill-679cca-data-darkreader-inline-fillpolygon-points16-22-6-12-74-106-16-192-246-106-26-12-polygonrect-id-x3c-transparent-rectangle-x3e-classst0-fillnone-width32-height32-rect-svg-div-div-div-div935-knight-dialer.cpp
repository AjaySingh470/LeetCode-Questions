class Solution {
public:
    vector<vector<int>> dp;
    int n;
    int MOD = 1e9 + 7;
    vector<vector<int>> jumps = {
        {4, 6},
        {6, 8},
        {7, 9},
        {4, 8},
        {3, 9, 0},
        {},
        {1, 7, 0},
        {2, 6},
        {1, 3},
        {2, 4}
    };
    
    int solve(int num , int size)
    {
        if(size == 0)
        {
            return 1;
        }
        if(dp[size][num] != -1) return dp[size][num];
        
        int ans = 0;
        for(auto it : jumps[num])
        {
            ans = (ans + solve(it , size - 1))%MOD;
        }
        return dp[size][num] = ans;
        
    }
    
    
    int knightDialer(int n) {
        dp = vector<vector<int>>(n+1 , vector<int>(10 , -1));
        int ans = 0;
        for(int i=0;i<10;i++)
        {
            ans = (ans + solve(i , n - 1))%MOD;
        }
        return ans;
    }
};