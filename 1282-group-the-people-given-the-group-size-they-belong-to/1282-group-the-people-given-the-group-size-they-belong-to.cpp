class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& gs) {
        vector<vector<int>> ans;
        vector<int> samp;
        unordered_map<int,vector<int>> m;
        for(int i=0;i<gs.size();i++)
        {
            m[gs[i]].push_back(i);
        }
        for(auto it:m)
        {
            int sz = it.first ;
            vector<int> tp = it.second;
            vector<int> tmp;
            for(int i=0;i<tp.size();i++)
            {
                if(i%sz == 0) {if(tmp.size())ans.push_back(tmp);tmp = vector<int>();}
                tmp.push_back(tp[i]);
            }
                if(tmp.size())ans.push_back(tmp);
        }
        return ans;
        
    }
};