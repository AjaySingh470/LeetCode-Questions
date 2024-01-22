class Solution {
public:
    vector<int> findErrorNums(vector<int>& v) {
        int n= v.size();
        int dup = -1;
        vector<int> vis(n+1,false);
        for(int i=0;i<n;i++)
        {
            if(vis[v[i]])
                dup = v[i];
            vis[v[i]] = true;
        }
    ////////////////////////////////////////////////
        int miss;
        for(int i=1;i<=n;i++)
        {
            if(vis[i] == false)
                miss = i;
        }
        return {dup,miss};
    }
};