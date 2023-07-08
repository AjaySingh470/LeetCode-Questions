//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        // Your code here
        // sort(arr,arr+n);
        vector<int> v(arr,arr+n);
        sort(v.begin(),v.end());
        int it = lower_bound(v.begin(),v.end(),1) - v.begin();
        // if(it == v.end()) return 1;
        // if(arr[it] <= 0) it++;
        int p = 1;
        // cout<<it<<" ";
        for(int i=it;i<n;)
        {
            if(v[i] == p)
            {
                while(i<n and v[i] == p)
                i++;
                p++;
            }
            else{
                return p;
            }
        }
        return p;
    } 
};

//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
} 
// } Driver Code Ends