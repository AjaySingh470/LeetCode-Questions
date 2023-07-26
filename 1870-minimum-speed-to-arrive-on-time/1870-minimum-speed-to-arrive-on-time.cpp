class Solution {
public:
    bool isPossible(int mid,double hour,vector<int> dist)
    {
        double cnt = 0.00;
        int n = dist.size();
        for(int i=0;i<n-1;i++)
        {
            if(dist[i]%mid != 0)
                cnt += dist[i]/mid + 1;
            else
                cnt += dist[i]/mid;
        }
        double tmp = (double)dist[n-1]/mid;
        cnt += tmp;
        return cnt<=hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l=1,r = 1e9+1;
        int res = INT_MAX;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(isPossible(mid,hour,dist))
            {
                res = min(mid,res);
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        if(res == INT_MAX)
            return -1;
        return res;
    }
};