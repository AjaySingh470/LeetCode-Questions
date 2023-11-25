class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int t1 = accumulate(nums.begin() , nums.end(),0);
        int t2 = 0;
        int n = nums.size();
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            t2 += nums[i];
            t1 -= nums[i];
            int tp = (((i+1)*nums[i]) - t2) + (t1 - (n-i-1)*nums[i]);
            ans.push_back(tp);
        }
        return ans;
    }
};