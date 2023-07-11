class Solution {
public:
    
    // int recur(int i,bool f,int mup,vector<int> &nums)
    // {
    //     if(i == nums.size()) return f ? 1 : 0;
    //     if(f)
    //         return nums[i]*recur(i+1 , true , nums);
    //     return max(nums[i]*recur(i+1,true , nums) , recur(i+1,false,nums));
    // }
    
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int m1 = INT_MIN;
        int pd = 1;
        for(int i=0;i<n;i++)
        {
            pd *= nums[i];
            m1 = max(m1 , pd);
            if(pd == 0) pd = 1;
        }
        pd = 1;
        for(int i=n-1;i>=0;i--)
        {
            pd *= nums[i];
            m1 = max(m1 , pd);
            if(pd == 0) pd = 1;
        }
        return m1;
    }
};