class Solution {
public:
    int fc(string s)
    {
        sort(s.begin(),s.end());
        int ans = 0;
        for(int i=0;i<s.size();i++)
            if(s[i] == s[0]) ans++;
        return ans;
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int n = words.size();
        vector<int> cnt;
        for(auto it : words)
        {
            cnt.push_back(fc(it));
        }
        sort(cnt.begin(),cnt.end());
        vector<int> ans;
        for(auto it : queries)
        {
            int itr = upper_bound(cnt.begin(),cnt.end(),fc(it))-cnt.begin();
            ans.push_back(n-itr);
        }
        return ans;
    }
};