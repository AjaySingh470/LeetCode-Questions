class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX,temp = 0;
        int l=0,r=0;
        int n = nums.size();
        while(r<n && l<n)
        {
            if(nums[r] == target)
                return 1;
            
            if(temp<target)
            {
                temp += nums[r];
                r++;
            }
            while(temp >= target)
            {
                ans = min(ans,r-l);
                
                temp -= nums[l];
                l++;
                
            }
            
        }
        if(ans == INT_MAX)
            return 0;
        return ans;
        
    }
};