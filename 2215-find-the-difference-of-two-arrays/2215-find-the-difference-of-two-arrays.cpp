class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& num1, vector<int>& num2) {
        vector<vector<int>> m;
        vector<int> final1,final2;
        map<int,int> m1,m2;
        for(auto it:num1)
        {
            m1.insert({it,1});
        }
        for(auto it:num2)
        {
            m2.insert({it,1});
        }
        int vis = 0;
        for(auto it:m1)
        {
            
            if(m2[it.first] != 1)
            {
                vis++;
                final2.push_back(it.first);
            }
        }
        vis = 0;
        for(auto it:m2)
        {
            
            if(m1[it.first] != 1)
            {
                vis++;
                final1.push_back(it.first);
            }
        }
        m.push_back(final2);
        m.push_back(final1);
        return m;
    }
};