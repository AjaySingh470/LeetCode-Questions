class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<int> ans;
        map<int,int> mp;
        sort(items.begin(),items.end());
        int mxp = 0;
        for(auto it : items)
        {
           mxp = max(mxp , it[1]);
           mp[it[0]] = mxp; 
        }
        //
        // cout<<st.size();
    
        // cout<<endl;
        for(auto it : queries)
        {
            auto itr = mp.upper_bound(it);
            if(itr == mp.begin())
            {
                ans.push_back(0);
            }
            else{
                --itr;
                ans.push_back(itr->second);
            }
        }   
        return ans;
    }
};