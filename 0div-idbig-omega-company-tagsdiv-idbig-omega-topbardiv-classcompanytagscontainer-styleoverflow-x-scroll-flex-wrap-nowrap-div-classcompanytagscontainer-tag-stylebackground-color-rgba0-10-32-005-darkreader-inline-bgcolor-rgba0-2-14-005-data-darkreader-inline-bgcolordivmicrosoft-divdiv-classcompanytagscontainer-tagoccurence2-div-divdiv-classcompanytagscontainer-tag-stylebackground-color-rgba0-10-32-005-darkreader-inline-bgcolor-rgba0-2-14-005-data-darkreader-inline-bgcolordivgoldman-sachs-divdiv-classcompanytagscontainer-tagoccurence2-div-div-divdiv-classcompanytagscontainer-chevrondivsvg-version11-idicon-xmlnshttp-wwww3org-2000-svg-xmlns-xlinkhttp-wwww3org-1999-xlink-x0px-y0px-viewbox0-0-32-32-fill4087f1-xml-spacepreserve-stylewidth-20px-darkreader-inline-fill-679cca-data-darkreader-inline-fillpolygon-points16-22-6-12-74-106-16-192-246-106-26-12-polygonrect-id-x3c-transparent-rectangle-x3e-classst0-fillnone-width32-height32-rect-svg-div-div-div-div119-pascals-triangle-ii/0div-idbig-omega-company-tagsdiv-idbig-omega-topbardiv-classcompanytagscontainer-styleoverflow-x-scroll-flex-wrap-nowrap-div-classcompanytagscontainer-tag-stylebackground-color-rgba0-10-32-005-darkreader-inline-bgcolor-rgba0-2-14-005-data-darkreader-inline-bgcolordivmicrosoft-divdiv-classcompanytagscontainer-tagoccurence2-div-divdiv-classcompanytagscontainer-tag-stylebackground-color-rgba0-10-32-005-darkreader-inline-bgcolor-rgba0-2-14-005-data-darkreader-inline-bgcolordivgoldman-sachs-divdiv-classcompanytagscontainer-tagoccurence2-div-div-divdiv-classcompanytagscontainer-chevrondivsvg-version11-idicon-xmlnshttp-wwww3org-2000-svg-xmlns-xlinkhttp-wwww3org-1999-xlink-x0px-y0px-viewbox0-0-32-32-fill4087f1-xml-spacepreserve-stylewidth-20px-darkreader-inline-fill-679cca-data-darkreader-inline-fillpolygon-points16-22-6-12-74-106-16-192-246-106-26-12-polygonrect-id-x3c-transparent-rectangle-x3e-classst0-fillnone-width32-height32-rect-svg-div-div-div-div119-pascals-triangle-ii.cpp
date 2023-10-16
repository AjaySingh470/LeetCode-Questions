class Solution {
public:
    vector<vector<int>> dp;
    void solve()
    {
      dp.push_back({1});        
        for(int i=1;i<=33;i++)
        {
          vector<int> prev = dp[i-1] , curr;
          curr.push_back(1);
          for(int it=1;it<prev.size();it++)
          {
            int sm = prev[it] + prev[it-1] ;
            curr.push_back(sm);
          }
          curr.push_back(1);
          dp.push_back(curr);
        }
      cout<<dp.size();
    }
  
  
    vector<int> getRow(int rowIndex) {
      solve();
      return dp[rowIndex];
    }
};
//
// 1
// 1 1
// 1 3 3 1
// 1 4 6 4 1
// 