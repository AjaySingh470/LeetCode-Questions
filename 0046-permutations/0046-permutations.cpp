class Solution {
    private:
       void recurrPerm(int index,vector<vector<int>> &ans,vector<int> &nums)
       {
           if(index == nums.size())
           {
               ans.push_back(nums);
               return;
           }
           for(int i = index;i<nums.size();i++)
           {
               swap(nums[i],nums[index]);
               recurrPerm(index+1,ans,nums);
               swap(nums[i],nums[index]);
           }
        
       }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        recurrPerm(0,ans,nums);
        return ans;
    }
};