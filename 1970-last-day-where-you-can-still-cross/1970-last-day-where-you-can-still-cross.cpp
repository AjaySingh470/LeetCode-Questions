class Solution {
public:
    
    int dr[4] = {+1 , 0 , -1 , 0};
    int dc[4] = {0 , -1 , 0 , +1};
    
    bool check(int mid ,vector<vector<int>> &cells, vector<vector<int>> adj)
    {
        int n = adj.size() , m = adj[0].size();
        for(int i=0;i<=mid;i++)
        {
            adj[cells[i][0]-1][cells[i][1]-1] = 1;
        }
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++)
        {
            if(adj[0][i]!=1)
            q.push({0,i});
        }
        int dst = n-1;
        while(!q.empty())
        {
            auto it  = q.front();
            q.pop();
            int x = it.first , y = it.second;
            if(x == dst) return true;
            for(int i=0;i<4;i++)
            {
                int nx = x + dr[i] , ny = y + dc[i];
                if(nx >= 0 && ny >= 0 && nx < n && ny < m && adj[nx][ny]!=1)
                {
                    adj[nx][ny] = 1;
                    q.push({nx , ny});
                }
            }
        }
        return false;
    }
    
    
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        vector<vector<int>> adj(row,vector<int>(col , 0));
        int l = 0 , r = cells.size()-1;
        while(l<=r)
        {
            int mid = (l+r)>>1;
            if(check(mid , cells , adj)) {
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return l;
    }
};