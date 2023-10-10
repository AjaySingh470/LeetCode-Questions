class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> v;
        int n = nums.size();
        set<int> uq(nums.begin() , nums.end());
        for(auto it : uq)
        {
            v.push_back(it);
        }
        int j=0;
        int ans = n;
        for(int i=0;i<v.size();i++)
        {
            int l = v[i] ;
            int r = l + n - 1;
            int j = upper_bound(v.begin() , v.end() , r) - v.begin();
            int count = j-i;
            ans = min(ans ,n- count);
        }
        return ans;
    }
};