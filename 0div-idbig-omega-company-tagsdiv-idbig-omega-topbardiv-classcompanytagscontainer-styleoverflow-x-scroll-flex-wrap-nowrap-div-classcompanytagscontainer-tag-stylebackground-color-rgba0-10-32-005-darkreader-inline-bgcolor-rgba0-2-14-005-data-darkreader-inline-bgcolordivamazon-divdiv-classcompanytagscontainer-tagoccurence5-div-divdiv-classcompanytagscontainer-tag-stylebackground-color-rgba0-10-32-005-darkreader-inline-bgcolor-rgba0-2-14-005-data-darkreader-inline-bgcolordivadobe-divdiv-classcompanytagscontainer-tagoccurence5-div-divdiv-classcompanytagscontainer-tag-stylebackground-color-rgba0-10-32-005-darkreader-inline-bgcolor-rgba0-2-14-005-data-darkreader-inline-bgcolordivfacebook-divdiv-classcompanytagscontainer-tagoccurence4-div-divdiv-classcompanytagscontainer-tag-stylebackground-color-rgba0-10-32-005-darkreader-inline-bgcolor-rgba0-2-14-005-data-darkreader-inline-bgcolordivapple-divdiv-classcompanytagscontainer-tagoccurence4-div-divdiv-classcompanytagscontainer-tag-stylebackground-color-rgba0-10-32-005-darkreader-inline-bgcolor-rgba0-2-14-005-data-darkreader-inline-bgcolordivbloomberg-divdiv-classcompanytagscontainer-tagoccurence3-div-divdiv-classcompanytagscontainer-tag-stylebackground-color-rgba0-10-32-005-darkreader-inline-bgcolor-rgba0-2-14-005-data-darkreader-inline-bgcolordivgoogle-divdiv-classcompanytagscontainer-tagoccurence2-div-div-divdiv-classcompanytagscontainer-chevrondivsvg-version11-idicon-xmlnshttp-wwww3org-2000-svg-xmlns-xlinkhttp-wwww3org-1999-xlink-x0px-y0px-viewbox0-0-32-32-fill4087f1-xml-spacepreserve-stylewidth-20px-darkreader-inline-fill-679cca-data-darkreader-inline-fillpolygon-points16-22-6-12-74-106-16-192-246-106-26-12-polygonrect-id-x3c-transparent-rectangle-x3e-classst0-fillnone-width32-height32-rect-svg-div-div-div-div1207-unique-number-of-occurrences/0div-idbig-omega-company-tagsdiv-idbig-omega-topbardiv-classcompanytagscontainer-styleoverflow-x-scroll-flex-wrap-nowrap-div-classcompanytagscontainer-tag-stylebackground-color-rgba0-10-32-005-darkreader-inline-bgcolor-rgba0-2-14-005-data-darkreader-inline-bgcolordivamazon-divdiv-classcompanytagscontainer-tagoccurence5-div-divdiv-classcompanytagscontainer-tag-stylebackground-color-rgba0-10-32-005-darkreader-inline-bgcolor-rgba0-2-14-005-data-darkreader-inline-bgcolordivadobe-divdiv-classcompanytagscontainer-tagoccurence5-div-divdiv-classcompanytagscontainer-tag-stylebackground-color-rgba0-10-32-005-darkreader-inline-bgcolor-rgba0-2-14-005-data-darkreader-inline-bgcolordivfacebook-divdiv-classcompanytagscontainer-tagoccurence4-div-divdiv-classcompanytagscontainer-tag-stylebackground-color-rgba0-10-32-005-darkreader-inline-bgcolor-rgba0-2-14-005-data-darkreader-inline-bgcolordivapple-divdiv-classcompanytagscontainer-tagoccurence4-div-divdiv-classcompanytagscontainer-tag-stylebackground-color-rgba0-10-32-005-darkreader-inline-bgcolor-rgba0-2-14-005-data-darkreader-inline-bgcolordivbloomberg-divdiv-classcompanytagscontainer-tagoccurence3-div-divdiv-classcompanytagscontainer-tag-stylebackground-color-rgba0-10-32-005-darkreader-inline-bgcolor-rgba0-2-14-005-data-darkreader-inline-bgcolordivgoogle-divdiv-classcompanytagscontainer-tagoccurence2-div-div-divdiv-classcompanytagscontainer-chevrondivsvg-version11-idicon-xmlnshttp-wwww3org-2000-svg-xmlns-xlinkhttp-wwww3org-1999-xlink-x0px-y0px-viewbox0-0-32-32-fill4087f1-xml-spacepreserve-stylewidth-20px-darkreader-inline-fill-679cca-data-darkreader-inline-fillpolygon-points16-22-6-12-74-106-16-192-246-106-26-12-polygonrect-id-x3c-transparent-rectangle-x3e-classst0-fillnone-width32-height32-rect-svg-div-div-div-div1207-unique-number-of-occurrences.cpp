class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_set<int> st;
        unordered_map<int,int> mp;
        int n = arr.size();
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        for(auto it:mp)
        {
            if(st.find(it.second)!=st.end())
                return false;
            st.insert(it.second);
        }
        return true;
    }
};