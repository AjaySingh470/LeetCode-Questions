class Solution {
public:
    
    bool isPos(long long mid , vector<int> &batteries,int n)
    {
        long long total_time = 0;
        for(auto it : batteries)
        {
            total_time += min((long long)it , mid);
        }
        return (total_time ) >= mid*n;
    }
    
    long long maxRunTime(int n, vector<int>& batteries) {
        long long l = 1 , r = accumulate(batteries.begin(),batteries.end(),0ll);
        long long ans =0 ;
        while(l<=r)
        {
            long long mid = (l+r)>>1;
            if(isPos(mid,batteries,n))
            {
                ans = l;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return r;
    }
};



// 7 1 1
// 
// - 7 1 1
// - 6 0 (1)
// - 5 0 (0)
// - 1 1 7
// - 5 2 2
// - 4 1 (2)
// - 3 0 (2)
// - 2 1 (0)
// - 1 0 (0)
