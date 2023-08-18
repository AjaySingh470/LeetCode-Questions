class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> deg(n,0);
        map<vector<int>,int> mp;
        for(auto it : roads)
        {
            deg[it[0]]++;
            deg[it[1]]++;
            mp[{it[0],it[1]}]++;
            mp[{it[1],it[0]}]++;
        }
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int temp = deg[i] + deg[j];
                if(mp[{i,j}] > 0) temp--;
                ans = max(ans , temp);
            }
        }
        return ans;
    }
};