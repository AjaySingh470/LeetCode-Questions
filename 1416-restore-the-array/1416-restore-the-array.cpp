class Solution {
public:
    const int mod = 1e9 + 7;
    int recur(int i,string &s , int k , vector<int> &dp)
    {
        if(i == s.size()) return 1;
        if(s[i] == '0') return 0;
        int cnt = 0;
        if(dp[i]!=-1) return dp[i];
        for(int it = i;it<s.size();it++)
        {
            string tmp = s.substr(i,it-i+1);
            
            if(stoll(tmp) > k) break;
            cnt = (cnt+recur(it+1 , s,k,dp))%mod;
        }
        return dp[i] = cnt;
    }
    
    int numberOfArrays(string s, int k) {
        string tmp = "";
        vector<int> dp(s.size(),-1);
        return recur(0,s,k,dp);//
    }
};