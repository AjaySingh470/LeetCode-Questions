class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin() , nums.end());
        for(int i=0;i<n;i++)
        {
            if(i%3 == 2)
            {
                if(nums[i] - nums[i-2] > k) return {};
                ans.push_back({nums[i-2] , nums[i-1] , nums[i]});
            }
        
            
        }
        return ans;
    }
};