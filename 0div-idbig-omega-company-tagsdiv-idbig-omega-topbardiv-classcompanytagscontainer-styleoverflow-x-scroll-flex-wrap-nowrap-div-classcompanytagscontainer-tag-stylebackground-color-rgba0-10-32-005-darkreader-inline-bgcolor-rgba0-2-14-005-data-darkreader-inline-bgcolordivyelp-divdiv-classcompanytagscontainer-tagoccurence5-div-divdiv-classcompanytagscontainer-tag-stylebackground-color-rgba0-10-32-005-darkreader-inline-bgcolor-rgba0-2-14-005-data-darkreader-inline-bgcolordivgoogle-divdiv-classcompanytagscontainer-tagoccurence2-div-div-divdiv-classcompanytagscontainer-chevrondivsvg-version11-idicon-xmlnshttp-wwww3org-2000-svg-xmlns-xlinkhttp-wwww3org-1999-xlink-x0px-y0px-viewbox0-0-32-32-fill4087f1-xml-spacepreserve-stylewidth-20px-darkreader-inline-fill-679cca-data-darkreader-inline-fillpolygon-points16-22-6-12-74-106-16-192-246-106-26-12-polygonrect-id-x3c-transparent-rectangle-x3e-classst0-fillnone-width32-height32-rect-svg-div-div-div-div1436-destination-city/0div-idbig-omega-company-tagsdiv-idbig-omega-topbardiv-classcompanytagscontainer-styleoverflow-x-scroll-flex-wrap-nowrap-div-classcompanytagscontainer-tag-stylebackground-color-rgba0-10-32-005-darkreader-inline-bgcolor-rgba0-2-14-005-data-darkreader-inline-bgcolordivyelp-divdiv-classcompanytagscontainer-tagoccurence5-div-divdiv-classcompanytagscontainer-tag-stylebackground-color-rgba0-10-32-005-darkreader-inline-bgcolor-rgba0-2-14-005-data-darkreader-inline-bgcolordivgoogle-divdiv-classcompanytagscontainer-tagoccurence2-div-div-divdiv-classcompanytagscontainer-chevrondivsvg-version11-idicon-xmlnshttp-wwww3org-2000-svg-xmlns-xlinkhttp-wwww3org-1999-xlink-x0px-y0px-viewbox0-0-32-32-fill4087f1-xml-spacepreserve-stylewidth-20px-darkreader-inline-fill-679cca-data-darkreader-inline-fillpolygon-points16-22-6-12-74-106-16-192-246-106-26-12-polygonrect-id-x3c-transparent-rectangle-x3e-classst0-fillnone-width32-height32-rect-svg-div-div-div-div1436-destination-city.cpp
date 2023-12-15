class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string,int> mp;
        set<string> st;
        for(auto it : paths)
        {
            mp[it[0]] = 1;
            // cout<<it[0];
            st.insert(it[1]);
        }
        for(auto it : st) 
        {
            if(mp.find(it) == mp.end()) return it;
        }    
            
            return "";
    }
};