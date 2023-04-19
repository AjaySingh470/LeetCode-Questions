class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         int n = nums.size();
      int chr = powl(2,n);
        sort(nums.begin() , nums.end());
      set<vector<int>> ans;
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
        ans.insert(tmp);
      }
    vector<vector<int>> str(ans.begin() , ans.end());
      return str;
    }
};