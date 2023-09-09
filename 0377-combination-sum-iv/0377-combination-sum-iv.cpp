class Solution {
public:
    int calculate(int idx,int target, vector<int> nums)
    {
         if(target==0)
            return 1;
        if(idx==nums.size() ||  target<0)
            return 0;
        int take=0;
        for(int i=0;i<nums.size();i++)
        {
            if(target>=nums[i])
            take += calculate(i,target-nums[i],nums);   
        }
           
        return take;
        
    }
    int mod = 1e9+7;
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<long long int> dp(target+1,0);
        dp[0] = 1;
        for(long long int i=1;i<=target;i++)
        {
            for(long long int j=0;j<n;j++)
            {
                if(i>=nums[j])
                    dp[i] += dp[i-nums[j]]%mod; 
            }
        }
        
        
        return dp[target];
        
        
       // return calculate(0,target,nums);
    }
};