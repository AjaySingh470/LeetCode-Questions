class Solution {
public:
    
    
    
    int minTaps(int n, vector<int>& ranges) {
        vector<int> v(n+1,0);
        for(int i=0;i<ranges.size();i++)
        {
            int ff = max(0,i-ranges[i]);
            int ss = min(n,i+ranges[i]);
            v[ff] = max(v[ff],ss);
        }
        // sort(v.begin(),v.end());
        int cnt = 0;
        int currEnd = 0;
        int nxtEnd = 0;
        for(int i=0;i<=n;i++)
        {
            if(i>nxtEnd) return -1;
            if(i>currEnd) {
                cnt++;
                currEnd = nxtEnd;
            }
            nxtEnd = max(nxtEnd,v[i]);
        }
        return cnt;
        
    }
};