class Solution {
public:
  
    int recur(int i,int j,vector<vector<int>> &piles,int k,  vector<vector<vector<int>>> &dp)
    {
      if(i == piles.size()) return 0;
      if(j == piles[i].size()) return 0;
      if(k == 0) return 0;
      if(dp[k][i][j] != -1) return dp[k][i][j];
      int take = piles[i][j] + max(recur(i,j+1,piles,k-1,dp) , recur(i+1,0,piles, k - 1 , dp));
      int nottake = recur(i+1,0,piles , k , dp);
      return dp[k][i][j] = max(take, nottake);
      ///
    }
  
  
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size() , m = 0;
        for(auto it:piles)
        {
          m = max(m , (int)it.size());
        }
        vector<vector<vector<int>>> dp(k+1,vector<vector<int>>(n,vector<int>(m,-1)));
        return recur(0,0,piles,k,dp);
    }
};