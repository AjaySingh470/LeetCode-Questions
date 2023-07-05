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
    
    
    int stockBuyAndSell(int n, vector<int> &pr) {
        // code here
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        // dp[0][1] = pr[0];
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<2;j++)
            {
                int take = pr[i] , nottake = 0;
                if(j==1) take *= -1 ;
                take += dp[i+1][1-j];
                nottake = dp[i+1][j];
                dp[i][j] = max(take , nottake);
            }
        }
        return  dp[0][1];
        
        
        
        // return solve(0,true, n , prices,dp);
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