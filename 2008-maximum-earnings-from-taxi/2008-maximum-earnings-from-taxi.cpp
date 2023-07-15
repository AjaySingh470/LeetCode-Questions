class Solution {
public:
    int ans = 0;
    int search(int val , vector<vector<int>> &arr)
    {
        int l = 0 , r = arr.size()-1;
        int ans = arr.size();
        while(l<=r)
        {
            int mid = (l+r)>>1;
            if(arr[mid][0] >= val)
            {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return ans;
    }
    long long solve(int idx , vector<vector<int>> &events,vector<long long> &dp)
    {
        if(idx == events.size() ) 
        {
            return 0;
        }
        if(dp[events[idx][0]]!=-1) return dp[events[idx][0]];
        // nottake
        
        long long nottake = solve(idx + 1  , events,dp);
        // take 
        long long take =  0;
        int it = search(events[idx][1] , events);
        take = (events[idx][1] - events[idx][0]) + events[idx][2]+ solve(it  , events ,dp);
        
        return dp[events[idx][0]] = max(take , nottake);
    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin() , rides.end());
        vector<long long> dp(n+1,-1);
        return solve(0,rides,dp);
    }
};