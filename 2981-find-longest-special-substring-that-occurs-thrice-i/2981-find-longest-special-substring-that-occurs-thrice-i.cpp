class Solution {
public:
    bool check(string tmp)
    {
        char ch = tmp[0];
        for(auto it : tmp)
        {
            if(it != ch)
                return true;
        }
        return false;
    }
    int maximumLength(string s) {
        map<string,int> mp;
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                string tmp = s.substr(i , j-i+1);
                if(!check(tmp))
                mp[tmp] += 1;
            }
        }
        string ans = "";
        int len = -1;
        for(auto it : mp)
        {
            // cout<<it.first <<" "
            if(it.second >= 3)
            {
                len = max(len , (int)it.first.size());
            }
        }
        return len;
    }
};