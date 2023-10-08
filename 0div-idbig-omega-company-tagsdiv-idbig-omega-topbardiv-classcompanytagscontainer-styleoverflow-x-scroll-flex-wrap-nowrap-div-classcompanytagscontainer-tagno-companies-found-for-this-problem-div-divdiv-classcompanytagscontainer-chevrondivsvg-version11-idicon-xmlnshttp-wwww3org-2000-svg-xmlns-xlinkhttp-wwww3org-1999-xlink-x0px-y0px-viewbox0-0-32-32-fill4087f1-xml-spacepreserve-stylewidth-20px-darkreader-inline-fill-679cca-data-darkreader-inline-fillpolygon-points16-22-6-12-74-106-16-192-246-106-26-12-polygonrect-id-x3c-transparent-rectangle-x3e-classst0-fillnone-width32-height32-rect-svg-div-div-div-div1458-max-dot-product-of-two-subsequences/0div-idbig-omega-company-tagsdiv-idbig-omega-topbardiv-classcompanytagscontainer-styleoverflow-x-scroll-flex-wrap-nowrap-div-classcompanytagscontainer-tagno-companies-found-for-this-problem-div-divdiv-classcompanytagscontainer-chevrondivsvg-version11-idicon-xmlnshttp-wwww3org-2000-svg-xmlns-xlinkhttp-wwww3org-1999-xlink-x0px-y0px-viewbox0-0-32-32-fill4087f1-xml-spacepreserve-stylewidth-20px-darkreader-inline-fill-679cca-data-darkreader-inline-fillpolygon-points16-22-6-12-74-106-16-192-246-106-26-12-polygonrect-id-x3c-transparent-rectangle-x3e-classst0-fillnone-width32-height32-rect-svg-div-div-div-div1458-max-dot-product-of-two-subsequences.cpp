class Solution {
public:
    int ans = INT_MIN;
    vector<vector<int>> dp;
    int recur(int i,int j,vector<int>& nums1, vector<int>& nums2)
    {
        if(i == nums1.size() || j == nums2.size()) return 0;
        
        int takeBoth = nums1[i] * nums2[j] + recur(i+1,j+1,nums1,nums2);
        int take1 = recur(i+1,j,nums1,nums2);
        int take2 = recur(i,j+1,nums1,nums2);
        return max({ans , takeBoth , take1 , take2});
    } 
    
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int fmax = INT_MIN , smax = INT_MIN;
        int fmin = INT_MAX , smin = INT_MAX;
        
        for(auto it : nums1)
        {
            fmax = max(fmax , it);
            fmin = min(fmin , it);
        }
        
        for(auto it : nums2)
        {
            smax = max(smax , it);
            smin = min(smin,it);
        }
        if(fmax < 0 and smin > 0) return fmax * smin;
        if(fmin > 0 and smax < 0) return fmin * smax;
        // return recur(0,0,nums1,nums2);
        dp = vector<vector<int>>(nums1.size()+1 , vector<int>(nums2.size()+1 , 0));
        
        for(int i=nums1.size() - 1;i>=0;i--)
        {
            for(int j=nums2.size() - 1;j>=0;j--)
            {
                int takeBoth = nums1[i] * nums2[j] + dp[i+1][j+1];
                dp[i][j] = max({takeBoth , dp[i+1][j] , dp[i][j+1]});
            }
        }
        
        return dp[0][0];
        
    }
};