class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        /*
         010
         011
         100
         ---
         101
         ---
         111
         001
         
         
         110
        */
        vector<int> ans;
        long long pw = powl(2,maximumBit)-1;
        int xr = 0;
        for(int i=0;i<nums.size();i++)
        {
            xr ^= nums[i];
            ans.push_back(pw^xr);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};