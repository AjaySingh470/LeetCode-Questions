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
            if(it.first == it.second.size())
            {
                ans.push_back(it.second);
            }
            else
            {
                while(it.second.size()>0)
                {    
                    vector<int> samp;
                    samp.insert(samp.begin(),it.second.begin(), it.second.begin()+it.first);
                    it.second.erase(it.second.begin(),it.second.begin()+it.first);
                    ans.push_back(samp);
                }    
            }
                
        }
        return ans;
        
    }
};