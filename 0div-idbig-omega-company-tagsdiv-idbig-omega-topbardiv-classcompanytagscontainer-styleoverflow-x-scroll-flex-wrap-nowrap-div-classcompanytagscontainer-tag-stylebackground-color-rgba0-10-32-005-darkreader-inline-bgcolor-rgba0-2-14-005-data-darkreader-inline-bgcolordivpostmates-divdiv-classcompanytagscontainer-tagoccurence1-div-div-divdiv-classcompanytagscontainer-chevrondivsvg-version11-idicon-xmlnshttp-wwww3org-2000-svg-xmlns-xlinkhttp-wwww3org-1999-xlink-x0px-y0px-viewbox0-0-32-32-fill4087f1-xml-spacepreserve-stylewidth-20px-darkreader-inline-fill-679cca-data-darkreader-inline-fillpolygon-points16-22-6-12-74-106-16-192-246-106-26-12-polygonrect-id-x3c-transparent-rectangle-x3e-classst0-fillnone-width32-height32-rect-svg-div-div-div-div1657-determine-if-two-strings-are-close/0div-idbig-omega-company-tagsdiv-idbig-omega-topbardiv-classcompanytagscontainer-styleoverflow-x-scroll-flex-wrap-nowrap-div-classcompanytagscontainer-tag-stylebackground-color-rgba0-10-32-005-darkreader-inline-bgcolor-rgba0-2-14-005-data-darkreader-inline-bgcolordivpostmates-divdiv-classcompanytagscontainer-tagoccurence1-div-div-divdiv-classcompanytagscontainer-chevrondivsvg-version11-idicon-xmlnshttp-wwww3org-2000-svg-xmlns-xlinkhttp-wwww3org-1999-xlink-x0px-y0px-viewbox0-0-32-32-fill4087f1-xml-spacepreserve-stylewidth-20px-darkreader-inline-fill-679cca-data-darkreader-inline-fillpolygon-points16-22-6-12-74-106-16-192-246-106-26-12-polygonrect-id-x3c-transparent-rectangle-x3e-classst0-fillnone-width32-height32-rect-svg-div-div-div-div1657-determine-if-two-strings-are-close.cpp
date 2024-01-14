class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.size() , m = word2.size();
        vector<int> v1(26,0),v2(26,0);
        set<char> st1,st2;
        if(n!=m) return false;
        for(int i=0;i<min(n,m);i++)
        {
            v1[word1[i] - 'a']++;
            st1.insert(word1[i]);
            v2[word2[i] - 'a']++;
            st2.insert(word2[i]);

        }
        sort(v1.begin(),v1.end());        
        sort(v2.begin(),v2.end());
        return v1 == v2 && st1 == st2;
    }
};