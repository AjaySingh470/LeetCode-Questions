class Solution {
public:
    map<int,int> st;
    bool recur(int idx,int k,vector<int> &stones,vector<vector<int>> &dp)
    {
        if(idx == stones.size()-1)
        {
            // cout<<"y";
            return true;
        }
        if(dp[idx][k]!=-1)
            return dp[idx][k];
        bool a = false;
        
        for(int i = k-1 ; i<=k+1;i++)
        {
            if(i>0 && st.find(stones[idx]+i)!=st.end())
                a |= recur(st[stones[idx]+i],i,stones,dp);
        }
        return dp[idx][k] = a;
    }
    
    bool canCross(vector<int>& stones) {
        sort(stones.begin(),stones.end());
        vector<vector<int>> dp(stones.size(),vector<int>(2001,-1));
        for(int i=0;i<stones.size();i++)
            st[stones[i]]=i;
        return recur(0,0,stones,dp);
    }
};