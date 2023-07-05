//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    
    int solve(int idx,bool buy,int n,vector<int> &pr,vector<vector<int>> &dp)
    {
        if(idx == n) return 0;
        int take = 0 , nottake = 0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        if(buy)
        {
            nottake = solve(idx + 1 , buy , n , pr,dp);
            take = -pr[idx] + solve(idx+1 , !buy , n , pr,dp);
        }
        else{
            nottake = solve(idx + 1 , buy , n , pr,dp);
            take = pr[idx] + solve(idx+1 , !buy , n , pr,dp);
        }
        return dp[idx][buy] = max(take , nottake);
    }
    
    
    int stockBuyAndSell(int n, vector<int> &prices) {
        // code here
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(0,true, n , prices,dp);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> prices(n);
        Array::input(prices,n);
        
        Solution obj;
        int res = obj.stockBuyAndSell(n, prices);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends