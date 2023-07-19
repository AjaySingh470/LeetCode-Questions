class Solution {
public:
    
    static bool cmp(vector<int>& a ,vector<int> &b) {return a[1] < b[1];}
    
    int eraseOverlapIntervals(vector<vector<int>>& itl) {
        sort(itl.begin() , itl.end(),cmp);
        //
        int cnt = 0;
        int p = INT_MIN;
        for(int i=0;i<itl.size();i++)
        {
            if(itl[i][0]>=p)
            {
                p = itl[i][1];
            }
            else{
                cnt++;
            }
        }
        return cnt;
    }
};