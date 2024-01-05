class Solution {
public:
    int solve(int idx,int prev,int n,vector<int> &nums)
    {
        if(idx == n)
            return 0;
        int len = 0;
        
        len = solve(idx+1,prev,n,nums);
        if(prev==-1 || nums[idx]>nums[prev])
            len = max(len,1 + solve(idx+1,idx,n,nums));
        return len ;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n  = nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);
        for(int i=1;i<n;i++)
        {
            if(nums[i] > temp.back())
                temp.push_back(nums[i]);
            else
            {
                int id = lower_bound(temp.begin(),temp.end(),nums[i]) - temp.begin();
                temp[id] = nums[i];
            }
        }
        return temp.size();
    }
//     binary search is most optimized solution
//     DP is also good but takes time
        
};