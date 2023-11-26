class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& mat) {
        int n = mat.size() , m = mat[0].size();
        int ans = 0;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[i].size();j++)
            {
                if(mat[i][j] != 0 and i>0)
                {
                    mat[i][j] += mat[i-1][j];
                }
            }
            vector<int> v = mat[i];
            sort(v.rbegin() , v.rend());
            
            for(int r=0;r<v.size();r++)
            {
                ans = max(ans ,v[r]*(r + 1) );
            }
        
        }
        //
        return ans;
    }
};