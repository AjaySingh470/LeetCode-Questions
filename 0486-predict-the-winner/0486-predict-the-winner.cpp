class Solution {
public:
    
    int solve(int i,int j,vector<int> &nums,bool ff)
    {
        if(i == j) return nums[i];
        if(i>j) return 0;
        int take = 0,nottake = 0;
        if(ff)
        {
            take = max(nums[i] + solve(i+1,j,nums,false) , nums[j] + solve(i,j-1,nums,false));
        }
        else{
            take = min(-nums[i] + solve(i+1,j,nums,true),-nums[j] + solve(i,j-1,nums,true));
        }
        return take;
        //
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        if(solve(0,nums.size()-1,nums,true) >= 0) return true;
        return false;
    }
};