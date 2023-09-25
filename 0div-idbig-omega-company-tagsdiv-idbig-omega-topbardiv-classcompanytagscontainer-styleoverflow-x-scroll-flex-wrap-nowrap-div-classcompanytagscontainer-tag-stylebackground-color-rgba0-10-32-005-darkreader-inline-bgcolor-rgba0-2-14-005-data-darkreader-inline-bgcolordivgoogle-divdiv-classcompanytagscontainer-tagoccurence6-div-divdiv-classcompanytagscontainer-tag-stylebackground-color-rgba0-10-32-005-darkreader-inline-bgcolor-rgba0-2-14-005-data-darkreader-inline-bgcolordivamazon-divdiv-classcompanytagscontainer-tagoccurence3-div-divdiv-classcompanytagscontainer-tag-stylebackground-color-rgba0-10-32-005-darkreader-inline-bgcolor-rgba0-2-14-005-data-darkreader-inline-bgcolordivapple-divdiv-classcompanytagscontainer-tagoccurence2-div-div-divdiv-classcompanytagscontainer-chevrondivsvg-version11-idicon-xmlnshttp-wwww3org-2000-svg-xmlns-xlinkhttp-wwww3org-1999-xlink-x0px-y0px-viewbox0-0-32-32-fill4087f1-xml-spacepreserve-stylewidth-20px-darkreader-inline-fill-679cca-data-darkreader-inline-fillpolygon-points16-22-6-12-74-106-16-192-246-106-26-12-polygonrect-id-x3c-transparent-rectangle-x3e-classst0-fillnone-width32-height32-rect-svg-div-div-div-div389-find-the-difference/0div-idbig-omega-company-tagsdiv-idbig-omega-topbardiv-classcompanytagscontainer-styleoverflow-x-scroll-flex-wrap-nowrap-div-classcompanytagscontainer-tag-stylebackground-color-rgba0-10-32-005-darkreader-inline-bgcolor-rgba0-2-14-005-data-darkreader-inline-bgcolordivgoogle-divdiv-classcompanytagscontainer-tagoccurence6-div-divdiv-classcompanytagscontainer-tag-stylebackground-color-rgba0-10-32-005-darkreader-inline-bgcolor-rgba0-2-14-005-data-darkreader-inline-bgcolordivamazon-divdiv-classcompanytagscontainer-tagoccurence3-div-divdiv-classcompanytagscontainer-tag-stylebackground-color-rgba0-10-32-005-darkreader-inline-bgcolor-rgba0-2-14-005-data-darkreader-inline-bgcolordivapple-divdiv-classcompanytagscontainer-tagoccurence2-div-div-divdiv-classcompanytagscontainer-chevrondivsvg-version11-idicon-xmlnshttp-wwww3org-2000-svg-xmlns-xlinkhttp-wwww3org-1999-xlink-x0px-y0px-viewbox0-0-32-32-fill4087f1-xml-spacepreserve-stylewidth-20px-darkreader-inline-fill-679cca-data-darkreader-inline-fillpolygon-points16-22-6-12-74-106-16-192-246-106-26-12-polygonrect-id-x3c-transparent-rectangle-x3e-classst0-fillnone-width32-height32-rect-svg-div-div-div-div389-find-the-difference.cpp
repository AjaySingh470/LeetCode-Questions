class Solution {
public:
    char findTheDifference(string s, string t) {
       // map<char,int> mp;
        /*sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        int i=0,j=0;
        map<char,int> mp;
        for(auto it: t)
        {
            mp[it]++;
        }
        for(auto it:s)
        {
            if(mp[it]>0)
                mp[it]--;
        }
        for(auto it:mp)
        {
            if(it.second>0)
                return it.first;
        }
       return t[0];*/
          char v = 0;
        for (char c: s) v ^= c;
        for (char c: t) v ^= c;
        return v;
    }
};