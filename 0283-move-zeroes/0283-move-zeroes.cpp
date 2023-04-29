class Solution {
public:
    void moveZeroes(vector<int>& v) {
        int n = v.size();
        int j = 0;
        // while(j<n and v[j]==0) j++;
        for(int i=0;i<n;i++)
        {
            if(v[i] != 0)
            {
                swap(v[j++] ,  v[i]);
            }
        }
    }
};