class Solution {
public:
    vector<int> dr = {1,0,-1,0},dc={0,-1,0,+1};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> ans = mat;
        queue<pair<pair<int,int>,int>> q;
        int n=mat.size(),m = mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j] == 0)
                {
                    vis[i][j] = 1;
                    q.push({{i,j},0});
                }
                if(mat[i][j] == 1)
                {
                    vis[i][j] = 0;
                }
            }
        }
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int r = it.first.first;
            int c = it.first.second;
            int steps = it.second;
            
            ans[r][c] = steps;
            for(int k=0;k<4;k++)
            {
                int nr = r + dr[k];
                int nc = c + dc[k];
                if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==0)
                {
                    vis[nr][nc] = 1;
                    q.push({{nr,nc},steps+1});
                }
            }
        }
        return ans;    
    }
};