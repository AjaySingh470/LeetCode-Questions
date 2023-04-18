class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
      int n = nums.size();
      int chr = powl(2,n);
      vector<vector<int>> ans;
      for(int i=0;i<chr;i++)
      {
        vector<int> tmp;
        for(int k=0;k<n;k++)
        {
          if(((i>>k)&1) == 1 )
          {
            tmp.push_back(nums[k]);
          }
        }
        ans.push_back(tmp);
      }
      return ans;
    }
};