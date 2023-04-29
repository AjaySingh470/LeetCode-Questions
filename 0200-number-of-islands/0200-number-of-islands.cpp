class Solution {
public:
    
    int dr[4] = {+1 , 0 , -1 , 0};
    int dc[4] = {0 , -1 , 0 , +1};
    
    void dfs(int i,int j,int n,int m,vector<vector<int>> &vis , vector<vector<char>> &grid)
    {
        if( i == n || j == m || i < 0 || j < 0 || grid[i][j] == '0') return;
        if(vis[i][j] == 1) return ;
        vis[i][j] = 1;
        for(int k=0;k<4;k++)
        {
            int nr = i + dr[k];
            int nc = j + dc[k];
            dfs(nr , nc , n , m , vis , grid);
        }
        
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size() , m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j] == 0 && grid[i][j] == '1')
                {
                    dfs(i,j,n,m,vis,grid);
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};