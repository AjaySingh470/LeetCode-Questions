class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        int i=0,n=s.size();
        while(i<n)
        {
            if(s[i]!=t[i])
            {
                return false;
            }
            else{
                i++;
            }
        }
        return true;
    }
};