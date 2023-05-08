class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        long long int sm =0 ;
        for(int i=0;i<mat.size();i++)
        {
            sm += mat[i][i];
        }
        int j =0 , i=mat.size()-1;
        for(int i=mat.size()-1;i>=0;i--)
        {
            if(i == j) {j++;continue;}
            sm += mat[j][i];
            j++;
        }
        return sm;
    }
};