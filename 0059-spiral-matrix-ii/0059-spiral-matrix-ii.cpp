class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int sz = n;
        vector<vector<int>> mat(n,vector<int>(n,0));
        int cnt = (n+1)/2;
        int k = 1;
        int i,j;
        int num = 1;
        while(k<=cnt)
        {
             i=k-1;
            for(j=k-1;j<=n-k;j++)
            {
                mat[i][j] = num;
                num++;
            }
             j=n-k;
            for(i=k;i<=n-k;i++)
            {
                mat[i][j] = num;
                num++;
            }
            i=n-k;
            for( j=n-k-1;j>=k-1;j--)
            {
                mat[i][j] = num;
                num++;
            }
            j=k-1;
            for( i=n-k-1;i>=k;i--)
            {
                mat[i][j] = num;
                num++;
            }
            k++;
        }
        return mat;
    }
};