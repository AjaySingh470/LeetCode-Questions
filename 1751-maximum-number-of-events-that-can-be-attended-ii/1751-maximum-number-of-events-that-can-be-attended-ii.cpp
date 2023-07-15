class Solution {
public:
    int ans = 0;
    int search(int val , vector<vector<int>> &arr)
    {
        int l = 0 , r = arr.size();
        while(l<r)
        {
            int mid = (l+r)>>1;
            if(arr[mid][0] <= val)
                l = mid + 1;
            else
                r = mid ;
        }
        return l;
    }
    int solve(int idx ,  int k, vector<vector<int>> &events,vector<vector<int>> &dp)
    {
        if(idx == events.size() || k == 0) 
        {
            return 0;
        }
        if(dp[idx][k]!=-1) return dp[idx][k];
        // nottake
        
        int nottake = solve(idx + 1 , k , events,dp);
        // take 
        int take =  0;
        int it = search(events[idx][1] , events);
      
        
        take = events[idx][2] + solve(it , k-1 , events ,dp);
        
        return dp[idx][k] = max(take , nottake);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin() , events.end());
        vector<vector<int>> dp(events.size() , vector<int>(k+1,-1));
        return solve(0,k,events,dp);
       
    }
};