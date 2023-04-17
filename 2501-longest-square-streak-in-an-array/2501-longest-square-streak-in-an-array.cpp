class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        vector<int> dp(1e5+1,0);
        int it = 2;
        for(auto it:nums)
        {
          dp[it] = 1;
        }
      int ans = 0;
        for(int i=2;i<320;i++)
        {
          int cnt = 0;
          if(dp[i] == 1)
          {
            long long int it = i;
            while(dp[it] == 1)
            {
              it *= it;
              cnt++;
              if(it > 1e5) break;
            }
          }
          ans = max(ans , cnt);
            
        }
      if(ans > 1) return ans;
      
      return -1;
    }
};