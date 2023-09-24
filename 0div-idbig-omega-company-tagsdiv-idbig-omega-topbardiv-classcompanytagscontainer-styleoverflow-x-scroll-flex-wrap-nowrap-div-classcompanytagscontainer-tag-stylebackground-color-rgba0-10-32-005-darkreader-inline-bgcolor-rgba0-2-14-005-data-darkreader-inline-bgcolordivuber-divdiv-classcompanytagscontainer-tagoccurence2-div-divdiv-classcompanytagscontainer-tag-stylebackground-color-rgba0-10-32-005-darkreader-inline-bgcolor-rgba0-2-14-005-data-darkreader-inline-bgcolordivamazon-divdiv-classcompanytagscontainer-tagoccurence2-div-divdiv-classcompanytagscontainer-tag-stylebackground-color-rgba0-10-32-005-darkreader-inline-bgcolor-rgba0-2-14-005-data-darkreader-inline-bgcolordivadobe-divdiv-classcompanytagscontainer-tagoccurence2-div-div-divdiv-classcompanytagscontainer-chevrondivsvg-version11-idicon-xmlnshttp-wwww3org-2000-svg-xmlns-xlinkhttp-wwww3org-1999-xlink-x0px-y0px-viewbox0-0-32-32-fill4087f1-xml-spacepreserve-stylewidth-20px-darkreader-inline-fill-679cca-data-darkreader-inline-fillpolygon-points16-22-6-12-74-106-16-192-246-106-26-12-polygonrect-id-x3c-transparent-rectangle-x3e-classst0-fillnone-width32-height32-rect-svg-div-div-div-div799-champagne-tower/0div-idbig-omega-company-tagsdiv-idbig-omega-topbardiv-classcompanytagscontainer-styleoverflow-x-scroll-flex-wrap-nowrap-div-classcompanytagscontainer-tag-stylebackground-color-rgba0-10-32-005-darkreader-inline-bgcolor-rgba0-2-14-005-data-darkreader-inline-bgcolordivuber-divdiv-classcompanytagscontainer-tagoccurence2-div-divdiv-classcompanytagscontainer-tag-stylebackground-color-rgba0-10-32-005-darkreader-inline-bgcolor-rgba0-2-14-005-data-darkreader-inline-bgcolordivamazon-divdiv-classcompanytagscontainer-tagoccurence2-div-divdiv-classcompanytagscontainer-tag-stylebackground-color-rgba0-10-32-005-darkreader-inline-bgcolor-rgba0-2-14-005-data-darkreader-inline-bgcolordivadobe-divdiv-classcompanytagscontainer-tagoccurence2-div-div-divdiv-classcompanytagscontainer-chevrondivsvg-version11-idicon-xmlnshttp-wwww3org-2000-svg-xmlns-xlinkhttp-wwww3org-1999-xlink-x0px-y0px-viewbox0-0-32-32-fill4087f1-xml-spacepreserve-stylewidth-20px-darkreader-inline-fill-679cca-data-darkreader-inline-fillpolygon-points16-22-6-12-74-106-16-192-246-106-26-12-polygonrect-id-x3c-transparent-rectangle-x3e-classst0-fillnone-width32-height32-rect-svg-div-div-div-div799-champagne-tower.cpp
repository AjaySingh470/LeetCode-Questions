class Solution {
public:
    double champagneTower(int poured, int row, int col) {
        vector<vector<double>> dp(102,vector<double>(102,0.000));
        dp[0][0] = (double)poured;
        for(int i=0;i<=row;i++)
        {
            for(int j=0;j<=i;j++)
            {
                double tmp = (dp[i][j] - 1.00)/2.0;
                if(tmp > 0)
                {
                    dp[i+1][j] += tmp;
                    dp[i+1][j+1] += tmp;
                }
                
            }
        }
        return min(1.0000 , dp[row][col]);
    }
};