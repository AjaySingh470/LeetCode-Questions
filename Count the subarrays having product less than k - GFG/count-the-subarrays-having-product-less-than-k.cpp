//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        long long int mup = 1;
        if(k == 1) return 0;
        int cnt = 0;
        int j = 0;
        for(int i=0;i<n;i++)
        {
            mup *= a[i];
            while(mup >= k)
            {
                // j = i;
                mup /= a[j++];
            }
            cnt += (i-j+1);
            // cout<<cnt<<" ";
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends