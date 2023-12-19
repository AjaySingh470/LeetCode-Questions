class Solution {
public:
 
    int solve(int i,int j,int n , int m,vector<vector<int>> &img)
    {
        int cnt = 0;
        int tot = 0;
        for(int p=-1;p<=1;p++)
        {
            for(int q=-1;q<=1;q++)
            {
                
                if((i+p)>=0 and (j+q)>=0 and (j+q)<m and (i+p)<n)
                {
                    cnt++;
                    tot += img[i+p][j+q];
                }
            }
        }
        return round(tot/cnt);
    }
    
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size();
        int m = img[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        // 
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ans[i][j] = solve(i,j,n,m,img);
            }
        }
        return ans;
    }
};