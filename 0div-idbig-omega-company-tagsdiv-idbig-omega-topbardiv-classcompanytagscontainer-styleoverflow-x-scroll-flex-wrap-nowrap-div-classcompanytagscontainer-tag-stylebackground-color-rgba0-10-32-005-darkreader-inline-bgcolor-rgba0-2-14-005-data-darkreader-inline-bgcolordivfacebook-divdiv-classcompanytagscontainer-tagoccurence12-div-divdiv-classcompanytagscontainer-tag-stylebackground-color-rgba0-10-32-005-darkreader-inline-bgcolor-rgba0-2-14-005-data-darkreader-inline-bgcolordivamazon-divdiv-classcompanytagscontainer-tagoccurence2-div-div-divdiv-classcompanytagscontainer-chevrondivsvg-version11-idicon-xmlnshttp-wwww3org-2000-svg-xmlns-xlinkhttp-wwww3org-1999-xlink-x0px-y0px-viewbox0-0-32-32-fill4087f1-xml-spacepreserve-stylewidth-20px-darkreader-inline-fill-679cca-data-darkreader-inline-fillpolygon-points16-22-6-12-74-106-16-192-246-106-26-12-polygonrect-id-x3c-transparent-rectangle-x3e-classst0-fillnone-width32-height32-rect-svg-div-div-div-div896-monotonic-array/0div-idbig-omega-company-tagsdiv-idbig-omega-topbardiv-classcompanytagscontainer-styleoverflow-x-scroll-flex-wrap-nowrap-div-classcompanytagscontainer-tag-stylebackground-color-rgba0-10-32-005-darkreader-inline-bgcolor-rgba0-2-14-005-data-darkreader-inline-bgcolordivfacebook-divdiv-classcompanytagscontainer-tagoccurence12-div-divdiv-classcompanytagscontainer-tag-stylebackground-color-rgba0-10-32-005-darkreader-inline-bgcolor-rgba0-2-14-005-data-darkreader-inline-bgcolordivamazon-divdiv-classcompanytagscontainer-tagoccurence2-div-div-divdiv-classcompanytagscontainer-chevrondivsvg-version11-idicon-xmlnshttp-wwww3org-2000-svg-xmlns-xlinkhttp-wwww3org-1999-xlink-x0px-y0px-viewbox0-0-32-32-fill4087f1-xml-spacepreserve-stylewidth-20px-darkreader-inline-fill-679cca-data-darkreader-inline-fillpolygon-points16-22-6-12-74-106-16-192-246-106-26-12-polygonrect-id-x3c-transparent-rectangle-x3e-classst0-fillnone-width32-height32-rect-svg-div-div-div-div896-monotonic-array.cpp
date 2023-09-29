class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
    
        int n = nums.size();
        int i=0;
        if(nums[i] <= nums[n-1])
        {   
            for(int i=0;i<n-1;i++)
            {
                if(nums[i] > nums[i+1]) return false;
            }
        }
        else{
            for(int i=0;i<n-1;i++)
            {
                if(nums[i] < nums[i+1]) return false;
            }
        }
        return true;
    }
};