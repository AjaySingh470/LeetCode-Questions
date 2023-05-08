class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> v(n+1,0);
        vector<int> ans(queries.size(),0);
        int cnt = 0;
        for(int i=0;i<queries.size();i++)
        {
            int idx = queries[i][0];
            int color = queries[i][1];
            // v[idx] = color;
            if(idx > 0 and v[idx] != 0 and  v[idx] == v[idx-1]) cnt--;
            if(idx < n-1 and v[idx] != 0 and v[idx] == v[idx+1]) cnt--;
            v[idx] = color;
            if(idx > 0 and v[idx] != 0 and  v[idx] == v[idx-1]) cnt++;
            if(idx < n-1 and v[idx] != 0 and v[idx] == v[idx+1]) cnt++;
            
            ans[i] = cnt;
            
        }
        return ans;
    }
};