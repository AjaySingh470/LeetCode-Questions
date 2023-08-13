class Solution {
public:
    
    bool recur(int i,vector<int>&nums,vector<int> &dp)
    {
        if(i == nums.size())
            return true;
        if(dp[i]!=-1) return dp[i];
        if(i<nums.size()-1 && nums[i] == nums[i+1])
        {
            dp[i] = recur(i+2,nums,dp);
            if(dp[i]) return true;
        }
        if(i<nums.size()-2 && nums[i] == nums[i+1] && nums[i+1] == nums[i+2])
        {
            dp[i] = recur(i+3,nums,dp);
            if(dp[i]) return true;
        }
        if(i<nums.size()-2 && nums[i]+1 == nums[i+1] && nums[i+1]+1 == nums[i+2] )
        {
            dp[i] = recur(i+3,nums,dp);
            if(dp[i]) return true;
        }    
        return dp[i] = false;
        
    }
    
    
    bool validPartition(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        return recur(0,nums,dp);
    }
};