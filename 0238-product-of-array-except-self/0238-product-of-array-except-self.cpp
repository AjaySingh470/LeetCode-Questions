class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prev(n,1);
        prev[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            prev[i] = nums[i] * prev[i+1]; 
        }
        for(int i=1;i<nums.size();i++)
        {
            nums[i] *= nums[i-1];
        }
        vector<int> ans(n,0);
        //
        for(int i=0;i<n;i++)
        {
            int p = 1 , a = 1;
            if(i>0) p = nums[i-1];
            if(i<n-1) a = prev[i+1];
            
            ans[i]  = p*a;
        }
        return ans;
    }
};