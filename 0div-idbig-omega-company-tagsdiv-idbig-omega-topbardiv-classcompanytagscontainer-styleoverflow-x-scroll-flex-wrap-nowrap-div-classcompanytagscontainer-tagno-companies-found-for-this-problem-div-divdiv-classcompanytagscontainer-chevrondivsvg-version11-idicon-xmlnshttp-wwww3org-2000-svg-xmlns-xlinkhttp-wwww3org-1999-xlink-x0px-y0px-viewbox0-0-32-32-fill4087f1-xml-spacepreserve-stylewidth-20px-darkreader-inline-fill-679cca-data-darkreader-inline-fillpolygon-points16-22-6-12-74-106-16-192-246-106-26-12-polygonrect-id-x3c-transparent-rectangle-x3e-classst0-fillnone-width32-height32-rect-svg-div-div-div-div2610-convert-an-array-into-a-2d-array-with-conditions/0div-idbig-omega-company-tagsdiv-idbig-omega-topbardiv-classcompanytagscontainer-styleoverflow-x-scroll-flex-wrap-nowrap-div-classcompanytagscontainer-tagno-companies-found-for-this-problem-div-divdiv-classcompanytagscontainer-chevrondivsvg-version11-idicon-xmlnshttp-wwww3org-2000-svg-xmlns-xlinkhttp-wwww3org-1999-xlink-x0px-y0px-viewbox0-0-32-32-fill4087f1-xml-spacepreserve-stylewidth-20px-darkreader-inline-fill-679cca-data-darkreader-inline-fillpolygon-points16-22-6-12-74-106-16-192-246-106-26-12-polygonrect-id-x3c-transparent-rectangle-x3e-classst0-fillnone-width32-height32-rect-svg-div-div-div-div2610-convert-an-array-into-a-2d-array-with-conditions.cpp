class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
      map<int,int> mp;
      set<int> st;
        for(auto it:nums)
        {
          mp[it]++;
          st.insert(it);
        }
        while(!st.empty())
        {
            vector<int> tp;
            for(auto it:mp)
            {
              if(mp[it.first] == 0){ st.erase(it.first); continue;}
              tp.push_back(it.first);
              mp[it.first]--;
            }
            ans.push_back(tp);
        }
      ans.pop_back();
      return ans;
    }
};