class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt = n/3;
        map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        vector<int> ans;
        for(auto it : mp)
        {
            if(it.second > cnt)
            ans.push_back(it.first);
        }
        return ans;
    }
};