class Solution {
public:
    int dr[4] = {+1, -1 , 0 , 0};
    int dc[4] = {0 , 0 , -1 , +1};
    
    vector<int> dfs(int i,int j,vector<vector<int>> &land)
    {
        int n = land.size() , m = land[0].size();
        int mx = i , my = j;
        queue<pair<int,int>> q;
        q.push({i,j});
        land[i][j] = 0;
        while(!q.empty())
        {
            auto it  = q.front();
            q.pop();
            int x = it.first , y = it.second;
            for(int i=0;i<4;i++)
            {
                int nx = x + dr[i];
                int ny = y + dc[i];
                if(nx >= 0 && ny>=0 && nx < n && ny < m && land[nx][ny] == 1)
                {
                    land[nx][ny] = 0;
                    q.push({nx,ny});
                    mx = max(mx , nx);
                    my = max(my , ny);
                }
                
            }
        }
        return {mx,my};
    }
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
    ////////////////////////////////////
        int n = land.size() , m = land[0].size();
        vector<vector<int>> v;
        //
        // int n = land.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(land[i][j] == 1)
                {
                    vector<int> pts = {i,j};
                    int mx = i , my = j;
                    vector<int> mpt = dfs(i,j,land);
                    pts.push_back(mpt[0]);
                    pts.push_back(mpt[1]);
                v.push_back(pts);
                }
            }
        }
        return v;
        
        
    }
};