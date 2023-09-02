class Solution {
public:
    int recur(int idx,string s,vector<string> &dict,vector<int> &dp)
    {
        if(idx == s.size())
            return 0;
        if(dp[idx]!=-1) return dp[idx];
        int nottake = 1 + recur(idx+1,s,dict,dp);
        int take = INT_MAX;
        for(auto it: dict)
        {
            if(s.find(it,idx) == idx)
            {
                take = min(take,recur(idx+it.size(),s,dict,dp));
            }
        }
        return dp[idx] = min(take , nottake);
    }
    
    
    int minExtraChar(string s, vector<string>& dictionary) {
        vector<int> dp(s.size()+1,-1);
        return recur(0,s,dictionary,dp);
    }
};