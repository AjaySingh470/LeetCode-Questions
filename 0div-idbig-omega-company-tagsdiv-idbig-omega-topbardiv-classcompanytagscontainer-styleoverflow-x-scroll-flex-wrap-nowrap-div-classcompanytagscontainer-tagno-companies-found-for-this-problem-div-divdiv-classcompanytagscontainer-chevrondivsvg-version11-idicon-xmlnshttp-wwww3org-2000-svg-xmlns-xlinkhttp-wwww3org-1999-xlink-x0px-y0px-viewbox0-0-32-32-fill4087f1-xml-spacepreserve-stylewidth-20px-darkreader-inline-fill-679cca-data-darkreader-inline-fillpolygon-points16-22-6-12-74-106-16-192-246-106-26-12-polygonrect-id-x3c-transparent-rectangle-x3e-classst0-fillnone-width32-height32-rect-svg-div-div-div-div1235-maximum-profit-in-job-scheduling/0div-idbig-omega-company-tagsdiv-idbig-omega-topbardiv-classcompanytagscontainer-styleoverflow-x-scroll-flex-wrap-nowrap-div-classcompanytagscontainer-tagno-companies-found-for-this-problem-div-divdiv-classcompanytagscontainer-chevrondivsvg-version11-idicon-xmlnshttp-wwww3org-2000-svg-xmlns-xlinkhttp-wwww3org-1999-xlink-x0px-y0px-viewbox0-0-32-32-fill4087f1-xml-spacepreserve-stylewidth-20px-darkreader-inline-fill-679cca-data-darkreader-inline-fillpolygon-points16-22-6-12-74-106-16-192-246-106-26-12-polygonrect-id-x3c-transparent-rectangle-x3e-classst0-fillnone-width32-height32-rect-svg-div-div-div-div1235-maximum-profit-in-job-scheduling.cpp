class Solution {
public:
      int bsrch(vector<vector<int>> &arr, int key, int r) {
        int l = 0;
        while(l<r) {
            int mid = (l+r+1)/2;
            if(arr[mid][0]<=key) l = mid;
            else r = mid -1;
        }
        return l;
    }
    int jobScheduling(vector<int>& st, vector<int>& et, vector<int>& p) {
        vector<vector<int>> store;
        int n = p.size();
        int size = 0;
        store.push_back({0,0,0});
        for(int i=0; i<n; i++) {
            vector<int> vect{ et[i], st[i], p[i] };
            size = max(size, et[i]);
            store.push_back(vect);
        }
        sort(store.begin(), store.end());
        vector<int> dp(n+1, 0);
        for(int i=1; i<=n; i++) {
            dp[i] = max(dp[i-1], dp[bsrch(store, store[i][1], i)]+store[i][2]);
        }
        return dp[n];
    }
};