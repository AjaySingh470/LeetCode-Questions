class Solution {
public:
    int ans = 0;
    int recur(int idx,int tmp , int diff, vector<int> &arr,map<int,int> &dp)
    {
        if(idx == arr.size())
        {
            return 0;
        }
        if(dp[idx]!=-1) return dp[idx];
        
        int nottake = recur(idx + 1, tmp , diff , arr,dp);
        int take = 0;
        if(tmp == -10000 || (arr[idx] - tmp == diff) )
        {
            tmp = arr[idx];
            take = 1 + recur(idx+1,tmp,diff,arr,dp);
            
        }
        return dp[arr[idx]] = max(take , nottake);
    }
    int longestSubsequence(vector<int>& arr, int difference) {
        ans = 0;
        map<int,int> mp;
        int maxvl = 0;
        for(int i=0;i<arr.size();i++)
        {
            int sz = 1;
            if(mp.find(arr[i] - difference) != mp.end()) mp[arr[i]] = 1 + mp[arr[i] - difference];
            else mp[arr[i]] = 1;
            maxvl = max(maxvl , mp[arr[i]]);
        }
        return maxvl;
    }
};