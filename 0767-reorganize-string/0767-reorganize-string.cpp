class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<char,int>,vector<pair<char,int>>,greater<pair<char,int>>> pq;
        vector<int> v(26,0);
        int mx = 0 ;
        char ch = 'a';
        for(auto it : s) {
        
            v[it-'a']++;
            if(v[it-'a']>mx)
            {
                mx = v[it-'a'];
                ch = it;
            }
        }
        cout<<ch<<endl;
        if(mx > (s.size()+1)/2)
            return "";
        int n = s.size();
        string ans(s.size(),' ');
        int i=0;
       while(v[ch-'a'] > 0)
       {
           s[i] = ch;
           i+=2;
           v[ch-'a']--;
       }
        
        for(int j=0;j<26;j++)
        {
            while( v[j]>0)
            {
                if(i >= n) i = 1;
                v[j]--;
                s[i] = char('a'+j);
                i += 2;
            }
        }
        return s;
    }
};