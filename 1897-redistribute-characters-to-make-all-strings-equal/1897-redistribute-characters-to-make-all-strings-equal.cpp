class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char,int> mp;
        for(auto it : words)
        {
            for(auto i : it)
                mp[i]++;
        }
        int n = words.size();
        for(auto it : mp)
        {
            if(it.second % n != 0) return false;
        }
        return true;
    }
};