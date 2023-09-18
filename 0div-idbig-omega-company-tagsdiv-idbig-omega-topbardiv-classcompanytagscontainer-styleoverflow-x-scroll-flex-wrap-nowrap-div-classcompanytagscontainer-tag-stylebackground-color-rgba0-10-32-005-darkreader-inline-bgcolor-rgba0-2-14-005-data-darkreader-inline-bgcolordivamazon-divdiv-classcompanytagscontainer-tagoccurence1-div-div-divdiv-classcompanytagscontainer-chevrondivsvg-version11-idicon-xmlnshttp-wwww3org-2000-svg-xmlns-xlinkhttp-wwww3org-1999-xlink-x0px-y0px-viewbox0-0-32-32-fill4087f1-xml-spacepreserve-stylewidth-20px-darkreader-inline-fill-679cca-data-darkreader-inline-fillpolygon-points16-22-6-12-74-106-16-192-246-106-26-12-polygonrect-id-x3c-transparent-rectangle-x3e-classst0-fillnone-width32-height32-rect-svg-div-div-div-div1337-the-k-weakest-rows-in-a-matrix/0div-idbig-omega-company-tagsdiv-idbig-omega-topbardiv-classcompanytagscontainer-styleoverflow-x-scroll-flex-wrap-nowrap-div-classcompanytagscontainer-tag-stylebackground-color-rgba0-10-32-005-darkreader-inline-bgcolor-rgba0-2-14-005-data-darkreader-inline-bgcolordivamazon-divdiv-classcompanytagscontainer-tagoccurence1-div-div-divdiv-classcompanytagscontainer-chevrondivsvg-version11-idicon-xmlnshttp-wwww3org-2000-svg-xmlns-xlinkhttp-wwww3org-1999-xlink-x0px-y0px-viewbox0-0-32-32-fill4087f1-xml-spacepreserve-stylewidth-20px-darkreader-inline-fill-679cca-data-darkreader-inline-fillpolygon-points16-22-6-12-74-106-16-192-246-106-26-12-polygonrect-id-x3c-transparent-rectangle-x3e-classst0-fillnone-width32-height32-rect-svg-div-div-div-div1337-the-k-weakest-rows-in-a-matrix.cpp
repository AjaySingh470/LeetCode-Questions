class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> vt;
        for(int i=0;i<mat.size();i++)
        {
            int count = 0;
            for(auto it:mat[i])
            {
                if( it==1)
                    count++;
            }
            vt.push_back({count,i});
            
        }
        vector<int> ans;
        sort(vt.begin(),vt.end());
        for(auto it:vt)
        {
            k--;
            if(k<0)
                break;
            ans.push_back(it.second);
        }
        return ans;
    }
    
};