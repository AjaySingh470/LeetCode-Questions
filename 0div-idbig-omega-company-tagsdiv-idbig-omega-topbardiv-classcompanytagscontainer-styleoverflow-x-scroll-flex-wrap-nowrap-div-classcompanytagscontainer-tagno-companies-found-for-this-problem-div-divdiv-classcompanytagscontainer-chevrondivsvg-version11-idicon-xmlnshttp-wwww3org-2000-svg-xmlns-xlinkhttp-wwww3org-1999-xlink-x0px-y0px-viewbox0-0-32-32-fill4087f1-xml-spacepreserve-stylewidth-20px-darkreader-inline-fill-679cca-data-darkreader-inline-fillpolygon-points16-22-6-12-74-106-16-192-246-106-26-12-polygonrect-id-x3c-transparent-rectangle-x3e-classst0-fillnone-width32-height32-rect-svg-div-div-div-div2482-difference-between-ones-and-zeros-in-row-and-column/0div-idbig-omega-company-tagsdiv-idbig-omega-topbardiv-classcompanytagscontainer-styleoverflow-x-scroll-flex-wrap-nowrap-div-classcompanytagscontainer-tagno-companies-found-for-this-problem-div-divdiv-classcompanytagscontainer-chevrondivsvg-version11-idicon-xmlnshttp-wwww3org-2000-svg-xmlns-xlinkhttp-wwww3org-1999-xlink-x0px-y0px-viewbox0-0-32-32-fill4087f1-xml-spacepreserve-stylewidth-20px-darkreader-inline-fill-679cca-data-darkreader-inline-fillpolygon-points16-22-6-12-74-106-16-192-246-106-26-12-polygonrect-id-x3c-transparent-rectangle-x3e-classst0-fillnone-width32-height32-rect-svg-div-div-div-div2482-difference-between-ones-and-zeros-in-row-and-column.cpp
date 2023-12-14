class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        vector<int> oi(n,0),oj(m,0);
        ///
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                oi[i] += grid[i][j];
                oj[j] += grid[i][j];
            }
        }
        vector<vector<int>> ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ans[i][j] = oi[i] + oj[j] - (n - oi[i]) - (m - oj[j]);
            }
        }
        return ans;
    }
};