class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n = matrix.size() , m = matrix[0].size();
        vector<vector<int>> v;
        for(int i=0;i<m;i++)
        {
            vector<int> t;
            for(int j=0;j<n;j++)
            {
                t.push_back(matrix[j][i]);
            }
            v.push_back(t);
        }
        return v;
    }
};