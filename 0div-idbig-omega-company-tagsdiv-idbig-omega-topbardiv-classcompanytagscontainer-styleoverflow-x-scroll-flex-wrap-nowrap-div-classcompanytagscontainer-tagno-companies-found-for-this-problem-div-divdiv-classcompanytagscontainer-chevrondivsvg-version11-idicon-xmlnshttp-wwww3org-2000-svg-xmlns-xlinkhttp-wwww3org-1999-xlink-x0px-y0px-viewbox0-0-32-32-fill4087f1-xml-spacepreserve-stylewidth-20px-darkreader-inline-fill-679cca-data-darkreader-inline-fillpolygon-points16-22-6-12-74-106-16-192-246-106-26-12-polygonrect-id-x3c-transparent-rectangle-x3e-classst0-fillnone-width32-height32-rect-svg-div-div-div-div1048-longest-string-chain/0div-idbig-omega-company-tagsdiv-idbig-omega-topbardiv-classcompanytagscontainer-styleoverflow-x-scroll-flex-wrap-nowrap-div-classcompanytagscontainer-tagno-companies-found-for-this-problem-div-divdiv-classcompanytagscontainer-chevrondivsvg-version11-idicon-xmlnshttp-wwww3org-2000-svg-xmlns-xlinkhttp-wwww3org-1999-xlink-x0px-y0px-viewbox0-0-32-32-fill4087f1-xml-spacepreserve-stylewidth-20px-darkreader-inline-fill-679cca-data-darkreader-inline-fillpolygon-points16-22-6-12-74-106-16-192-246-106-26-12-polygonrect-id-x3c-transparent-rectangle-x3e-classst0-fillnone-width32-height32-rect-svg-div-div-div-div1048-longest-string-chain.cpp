
class Solution {
public:
    bool compare(string s,string t)
    {
        int sz = s.size(),tz = t.size();
         if(abs(sz-tz) != 1)
            return false;
        int i=0,j=0;
       
        while(i<sz)
        {
            if(s[i] == t[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
        if(i==sz && j==tz)
        {
            return true;
        }
        else{
            return false;
        }
        
    }
    static bool compr(string &s1,string &s2)
    {
        return s1.size()<s2.size();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        int lastidx=0,maxi=1;
        sort(words.begin(),words.end(),compr);
        vector<int> dp(n,1);
        for(int i=0;i<n;i++)
        {
            
            for(int j=0;j<i;j++)
            {
                if(compare(words[i],words[j]) )
                {
                    dp[i] = max(dp[i],dp[j]+1);
                    
                }
            }
            if(maxi<dp[i])
            {
                maxi = dp[i];
            }
        }
        // vector<string> ans(maxi);
        // int ind = 1;
        // ans[0] = words[lastidx];
        // while(hash[lastidx] != lastidx)
        // {
        //     lastidx = hash[lastidx];
        //     ans[ind] = words[lastidx];
        // }
        return maxi;
    }
};