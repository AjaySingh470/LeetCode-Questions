class Solution {
public:
    
    int ans = 0;
    
    bool hasunique(string &s)
    {
        map<char,int> mp;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
            if(mp[s[i]]>1) return false;
        }
        return true;
    }
    
    void recur(int i,vector<string>& arr,string s)
    {
        if(i == arr.size())
        {
        
                ans = max(ans , (int)s.size());
            
            return;
        }
        // nottake
        recur(i+1, arr, s);
        s += arr[i];
        if(hasunique(s))
        {
            recur(i+1,arr,s);
        }
        
    }    
        
    
    int maxLength(vector<string>& arr) {
        ans = 0;
        recur(0,arr,"");
        return ans;
    }
};