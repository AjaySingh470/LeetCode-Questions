class Solution {
public:
    int dr[4] = {+1, 0 , -1 ,0};
    int dc[4] = {0, +1 , 0 , -1};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size() , m = image[0].size();
        vector<vector<int>> ans;
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int val = image[sr][sc];
        image[sr][sc] = color;
        if(val == color)
             return image;
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nr = it.first + dr[i];
                int nc = it.second + dc[i];
                if( nr < n && nc < m && nr >= 0 && nc >= 0 && image[nr][nc] == val)
                {
                    image[nr][nc] = color;
                    q.push({nr,nc});
                }
            }
            
        }
        return image;
    }
};