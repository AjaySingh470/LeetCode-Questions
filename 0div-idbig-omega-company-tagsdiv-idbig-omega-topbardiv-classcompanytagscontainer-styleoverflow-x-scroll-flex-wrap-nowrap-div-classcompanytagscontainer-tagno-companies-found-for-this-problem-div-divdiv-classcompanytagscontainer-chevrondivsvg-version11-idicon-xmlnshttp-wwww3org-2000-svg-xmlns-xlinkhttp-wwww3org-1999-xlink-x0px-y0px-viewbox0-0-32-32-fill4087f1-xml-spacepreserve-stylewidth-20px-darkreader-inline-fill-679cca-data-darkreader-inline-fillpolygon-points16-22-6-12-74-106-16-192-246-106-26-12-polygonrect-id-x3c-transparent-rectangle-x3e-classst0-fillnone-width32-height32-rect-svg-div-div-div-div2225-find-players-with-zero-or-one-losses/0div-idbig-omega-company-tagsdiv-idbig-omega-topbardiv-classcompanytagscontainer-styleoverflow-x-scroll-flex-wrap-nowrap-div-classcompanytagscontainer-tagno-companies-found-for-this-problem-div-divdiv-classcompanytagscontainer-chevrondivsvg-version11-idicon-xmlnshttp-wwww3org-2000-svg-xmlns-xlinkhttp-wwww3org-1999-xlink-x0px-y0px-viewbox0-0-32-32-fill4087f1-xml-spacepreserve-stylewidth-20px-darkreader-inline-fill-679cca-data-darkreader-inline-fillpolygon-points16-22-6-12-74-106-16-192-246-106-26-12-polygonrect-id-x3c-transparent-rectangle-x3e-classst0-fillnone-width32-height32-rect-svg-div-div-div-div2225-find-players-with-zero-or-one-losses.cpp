class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& v) {
        int n=v.size();
        map<int,int> m1,m2;
        for(int i=0;i<n;i++)
        {
            m1[v[i][0]]++;
            m2[v[i][1]]++;
        }
        vector<int> p1,p2;
        for(auto it:m1)
        {
            int vk = it.first;
            if(m2[vk] == 0)
            p1.push_back(vk);
        }
        for(auto it:m2)
        {
            if(it.second==1)
            {
                p2.push_back(it.first);
            }
        }
        vector<vector<int>> ans;
        ans.push_back(p1);
        ans.push_back(p2);
        return ans;
    }
};