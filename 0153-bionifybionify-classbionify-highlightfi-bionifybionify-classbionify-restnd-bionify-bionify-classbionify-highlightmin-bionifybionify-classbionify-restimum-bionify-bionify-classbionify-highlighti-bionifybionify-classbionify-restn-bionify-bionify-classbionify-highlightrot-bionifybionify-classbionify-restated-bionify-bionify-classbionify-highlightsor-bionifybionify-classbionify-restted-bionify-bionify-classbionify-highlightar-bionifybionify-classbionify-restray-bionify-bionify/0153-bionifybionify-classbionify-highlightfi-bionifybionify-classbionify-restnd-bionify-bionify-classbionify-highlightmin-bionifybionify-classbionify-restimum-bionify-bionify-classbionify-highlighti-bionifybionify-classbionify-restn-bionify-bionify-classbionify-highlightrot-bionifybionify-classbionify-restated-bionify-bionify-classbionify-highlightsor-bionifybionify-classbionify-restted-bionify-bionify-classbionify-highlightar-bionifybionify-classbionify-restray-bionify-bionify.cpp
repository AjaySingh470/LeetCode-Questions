class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if( nums.size() == 1) return nums[0];
        int i=0,j=nums.size() - 1;
        if(nums[0] < nums[j]) return nums[0];
        while(i<=j)
        {
            int mid = (i+j)/2;
            if(mid > 0 and nums[mid] < nums[mid - 1])
                return nums[mid];
            if( mid < n-1 and nums[mid+1] < nums[mid] ) return nums[mid+1];
            
                if(nums[mid] > nums[0])
                    i = mid + 1;
                else
                {
                    j = mid-1;
                }
            
        }
        return INT_MAX-1;
    }
};