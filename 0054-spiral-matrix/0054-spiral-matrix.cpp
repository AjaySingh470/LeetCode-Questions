class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left = 0,right = matrix[0].size()-1,top = 0,down = matrix.size()-1;
        int dir = 0;
        vector<int> itr;
        while(top<=down && left<=right)
        {
            if(dir == 0)
            {
                for(int i=left;i<=right;i++)
                {
                    itr.push_back(matrix[top][i]);
                }
                top++;
            }
            else if(dir == 1)
            {
                for(int i=top;i<=down;i++)
                {
                    itr.push_back(matrix[i][right]);
                }
                right--;
            }
            else if(dir == 2)
            {
                for(int i = right;i>=left;i--)
                {
                    itr.push_back(matrix[down][i]);
                }
                down--;
            }
            else{
                for(int i=down;i>=top;i--)
                {
                    itr.push_back(matrix[i][left]);
                }
                left++;
            }
                
            dir = (dir+1)%4;
        }
        return itr;
    }
};