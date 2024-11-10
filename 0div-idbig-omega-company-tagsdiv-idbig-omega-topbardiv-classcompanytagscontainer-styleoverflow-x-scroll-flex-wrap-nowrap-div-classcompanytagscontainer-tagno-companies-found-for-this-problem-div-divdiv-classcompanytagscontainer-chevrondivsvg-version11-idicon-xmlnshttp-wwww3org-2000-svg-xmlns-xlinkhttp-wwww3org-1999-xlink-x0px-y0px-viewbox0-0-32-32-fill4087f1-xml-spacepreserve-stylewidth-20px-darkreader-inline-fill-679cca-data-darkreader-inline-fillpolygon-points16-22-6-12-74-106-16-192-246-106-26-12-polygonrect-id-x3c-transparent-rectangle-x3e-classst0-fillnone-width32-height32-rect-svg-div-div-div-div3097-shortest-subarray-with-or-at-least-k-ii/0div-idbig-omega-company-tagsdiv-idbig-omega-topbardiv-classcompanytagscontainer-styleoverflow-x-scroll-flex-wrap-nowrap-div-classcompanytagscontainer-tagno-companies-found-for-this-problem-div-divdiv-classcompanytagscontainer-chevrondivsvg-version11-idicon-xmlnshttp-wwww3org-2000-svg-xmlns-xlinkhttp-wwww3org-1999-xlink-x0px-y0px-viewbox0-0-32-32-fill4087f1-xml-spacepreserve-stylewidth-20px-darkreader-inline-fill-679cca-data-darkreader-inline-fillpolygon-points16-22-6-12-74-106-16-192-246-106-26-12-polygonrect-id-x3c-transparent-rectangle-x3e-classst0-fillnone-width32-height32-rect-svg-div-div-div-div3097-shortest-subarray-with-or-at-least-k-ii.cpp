class Solution {
public:
    
    void updateVec(vector<int> &xr,int num,int dec)
    {
        for(int i=0;i<32;i++)
        {
            if((num >> i) & 1)
            {
                xr[i] += dec;
            }
        }
    }
    
    int cvtBits(vector<int> &xr)
    {
        int res = 0;
        for(int i=0;i<32;i++)
        {
            if(xr[i] != 0)
            {
                res |= (1 << i);
            }
        }
        return res;
    }
    
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int ans = INT_MAX;
        // sort(nums.begin(),nums.end());
        vector<int> xr(32,0);
        
        int i=0,j=0;
        int n = nums.size();
        while(j<n)
        {
            updateVec(xr,nums[j],1);
            while(j>=i and cvtBits(xr) >= k)
            {
                ans = min(ans , (j - i + 1));
                updateVec(xr,nums[i],-1);
                i++;
            }
            j++;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};