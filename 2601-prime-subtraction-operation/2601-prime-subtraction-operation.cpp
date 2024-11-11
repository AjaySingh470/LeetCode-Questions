class Solution {
public:
    set<int> st;
  void seive()
  {
    int i=0;
    vector<bool> vis(1001,0);
    for(int i=2;i<1001;i++)
    {
      if(!vis[i])
      {
        vis[i] = 1;
        st.insert(i);
        for(int j=i;j<1001;j+=i)
          vis[j] = 1;
      }
    }
  }
  int lowerr(int n)
  {
    auto it= st.lower_bound(n);
    if(*it > n)
    {
      if(it == st.begin()) return 0;
      else return *(--it);
    }
    return *it;
  }
    bool primeSubOperation(vector<int>& nums) {
        seive();
        int n = nums.size();
        int prev = 0;
        for(int i=0;i<nums.size();i++)
        {
            int diff = nums[i] - prev - 1;
            int val = lowerr(diff);
            nums[i] -= val;
            prev = nums[i];
        }
        for(int i=1;i<n;i++) if(nums[i]<=nums[i-1]) return false;
        return true;
         
    }
};