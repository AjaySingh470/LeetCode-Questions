class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        long long sm = accumulate(nums.begin(),nums.end(),0);
        if(sm == x)
        {
            return nums.size();
        }
        long long target = sm - x;
        int len = 0;
        int n = nums.size();
        long long tsm = 0;
        int i=0 ,j = 0;
        bool flg = false;
        while(j<n)
        {
            tsm += nums[j];
            while(tsm > target and i<j)
            {
                tsm -= nums[i];
                i++;
            }
            if(tsm == target)
            {
                flg = true;
                len = max(j-i+1 , len);
            }
            j++;
        }
        if(!flg)
            return -1;
        return n - len;
    }
};