class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n = arr.size();
        map<int,int> mp;
        unordered_set<int> st;
        for(auto it : arr) {
            mp[it]++;
            // st.insert(it);
        }
        ///
        vector<pair<int,int>> v;
        for(auto it : mp)
        {
            v.push_back({it.second,it.first});
        }
        sort(v.begin() , v.end());
        //
        int it = 0;
        for(it=0;it<v.size();it++)
        {
            // cout<<v[it].second<<" "<<k<<" ";
            if(k - v[it].first < 0) break;
            
            k -= v[it].first;
            mp.erase(v[it].second);
            
        }
        return mp.size();
    } 
};