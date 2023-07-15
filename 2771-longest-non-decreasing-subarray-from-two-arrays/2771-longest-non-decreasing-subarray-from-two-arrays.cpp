class Solution {
public:
    int mx  = 0;
    int lis(int idx , int ff ,vector<int> &n1,vector<int> &n2,vector<vector<int>> &dp)
    {
        if(idx == n1.size())
        {
            // mx = max(mx , len);
            return 0;
        }
        if(dp[idx][ff] != -1)
            return dp[idx][ff];
        int take1 = 0 , take2 = 0 , take3 = 0;
        // if true then n1 else n2;
        int prev = 0;
        //
        if(ff == 1)
        {
            if(n1[idx] >= n1[idx - 1])
            take1 = 1 + lis(idx + 1 , 1 , n1 , n2,dp);
            //
            if(n2[idx] >= n1[idx - 1])
            take2 = 1 + lis(idx + 1 , 2 , n1 , n2, dp);
        }
        else if(ff == 2){
            if(n1[idx] >= n2[idx - 1])
            take1 = 1 + lis(idx + 1 , 1 , n1 , n2, dp);
            //
            if(n2[idx] >= n2[idx - 1])
            take2 = 1 + lis(idx + 1 , 2 , n1 , n2, dp);
        }
        else{
             take1 = 1 + lis(idx + 1 , 1 , n1 , n2, dp);
            take2 = 1 + lis(idx + 1 , 2 , n1 , n2, dp);
            take3 = lis(idx + 1 , 0 , n1 , n2, dp);
        }
        
        
        
        return dp[idx][ff] = max(take1 , max(take3,take2));
    }
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        // vector<int> nums3;
        vector<vector<int>> dp(n,vector<int>(3,-1));
        return lis(0,0,nums1,nums2, dp);
    }
};