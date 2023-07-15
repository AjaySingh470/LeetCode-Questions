class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        
        int sm = 0 , tmp = 0;
        if(k == 1) return 1;
        int n= nums.size();
        for(int i=0;i<n;i++)
        {
            if(i>=k)
                tmp -= nums[i-k];
            nums[i] -= tmp;
            tmp += nums[i];
            if(nums[i] < 0) return false;
        }
        return nums[n-1] == 0;
    }
};