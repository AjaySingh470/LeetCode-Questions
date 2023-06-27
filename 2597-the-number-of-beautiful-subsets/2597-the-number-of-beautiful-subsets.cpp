class Solution {
public:
    map<int,int> mp;
    int ans = 0;
    void dfs(int i,vector<int> &nm,int &k,int &ans)
    {
        if(i == nm.size()) {
               ans++; return;
        }else
        {
            if(!mp[nm[i]-k] and !mp[nm[i]+k])
            {
                mp[nm[i]]++;
                dfs(i+1,nm,k,ans);
                mp[nm[i]]--;
            }
            dfs(i+1,nm,k,ans);
        }
    }
    int beautifulSubsets(vector<int>& nums, int k) {
     
      sort(nums.begin(),nums.end());
      vector<int> dp;
        int ans = 0;
    dfs(0,nums,k,ans);
      return ans-1;
    }
};