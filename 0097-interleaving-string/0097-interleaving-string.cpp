class Solution {
public:
    
    bool recur(int i1,int i2,int i3 , string &s1,string &s2,string &s3, vector<vector<vector<int>>> &dp)
    {
        
        if(i3 == 0 && i1 == 0 && i2 == 0) return true;
        if(dp[i1][i2][i3] != -1) return dp[i1][i2][i3];

        //
        // cout<<i1<<i2<<i3<<endl;
        bool ff = false , ss = false;
        if(i1 > 0 && i3>0 && s1[i1-1] == s3[i3-1])
        {
           ff =  recur(i1-1,i2,i3-1,s1,s2,s3,dp);
        }
        if(i2>0 && i3>0 && s2[i2-1] == s3[i3-1])
        {
           ss = recur(i1 , i2-1,i3-1,s1,s2,s3,dp);
        }
        return dp[i1][i2][i3] = ff | ss ;
        
    }
    
    
    bool isInterleave(string s1, string s2, string s3) {
        
        vector<vector<vector<int>>> dp(s1.size()+1,vector<vector<int>>(s2.size()+1,vector<int>(s3.size()+1,-1)));
        
        return recur(s1.size(),s2.size(),s3.size(),s1,s2,s3,dp);
    }
};