class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int target) {
        int pos = 0;
        int m1 = m[0].size(),n=m.size();
        for(int i=n-1;i>=0;i--)
        {
            if(m[i][0] <= target)
            {
                pos = i;
                break;
            }
        }
        for(int i=0;i<m1;i++)
        {
            if(m[pos][i] == target)
                return true;
        }
        return false;
    }
};