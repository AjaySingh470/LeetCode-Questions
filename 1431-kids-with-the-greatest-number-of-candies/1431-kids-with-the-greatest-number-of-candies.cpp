class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int ec) {
      int n = candies.size() , mx = *max_element(candies.begin(),candies.end());
      vector<bool> ans(n,false);   
      for(int i=0;i<candies.size();i++)
        {
          if(candies[i] + ec >= mx )
          {
            ans[i] = true;
          }
        }
      return ans;
    }
};