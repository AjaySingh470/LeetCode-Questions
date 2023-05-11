class Solution {
public:
    
    map<int,int> n1 , n2;
    int solve(int i,int j,vector<int> &nums1 , vector<int> &nums2 , vector<vector<int>> &dp)
    {
        if(i == nums1.size() || j == nums2.size() ) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(nums1[i] == nums2[j])
        {
            return dp[i][j] = 1 + solve(i+1, j+1 , nums1 , nums2 , dp);
        }
        int first = solve(i+1, j , nums1, nums2 , dp);
        int second = solve(i , j+1 , nums1 , nums2 , dp);
        return dp[i][j] = max(first , second);
        
    }
        
        
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        // for(auto it:nums1) n1[it]++;
        // for(auto it:nums2) n2[it]++;
        vector<vector<int>> dp(nums1.size() , vector<int>(nums2.size(),-1));
        return solve(0,0,nums1,nums2,dp);
    }
};