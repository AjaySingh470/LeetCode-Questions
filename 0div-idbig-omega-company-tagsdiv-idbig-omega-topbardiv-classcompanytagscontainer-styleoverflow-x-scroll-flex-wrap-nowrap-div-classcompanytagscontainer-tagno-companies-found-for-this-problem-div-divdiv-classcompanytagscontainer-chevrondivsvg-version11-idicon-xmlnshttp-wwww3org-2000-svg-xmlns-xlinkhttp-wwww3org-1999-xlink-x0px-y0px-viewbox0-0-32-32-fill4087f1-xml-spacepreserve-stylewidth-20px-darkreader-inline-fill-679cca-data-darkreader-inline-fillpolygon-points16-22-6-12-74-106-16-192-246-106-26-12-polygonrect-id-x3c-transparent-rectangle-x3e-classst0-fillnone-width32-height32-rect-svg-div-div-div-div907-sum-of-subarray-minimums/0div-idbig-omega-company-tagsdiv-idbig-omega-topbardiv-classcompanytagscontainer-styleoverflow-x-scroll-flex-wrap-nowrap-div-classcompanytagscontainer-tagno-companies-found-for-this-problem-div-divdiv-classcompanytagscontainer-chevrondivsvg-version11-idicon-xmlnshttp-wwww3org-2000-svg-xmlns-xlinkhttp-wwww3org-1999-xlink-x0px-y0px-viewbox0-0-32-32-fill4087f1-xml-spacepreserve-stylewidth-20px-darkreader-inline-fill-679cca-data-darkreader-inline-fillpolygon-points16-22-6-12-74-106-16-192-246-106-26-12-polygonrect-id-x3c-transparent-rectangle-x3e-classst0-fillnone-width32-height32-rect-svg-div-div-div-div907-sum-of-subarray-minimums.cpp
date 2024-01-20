class Solution {
public:
    int MOD = 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> left(n,-1),right(n,n);
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && arr[i]<arr[st.top()]) st.pop();
            if(st.size()) left[i] = i-st.top();
            else left[i] = i+1;
            st.push(i);
        }
        while(st.size()) st.pop();
        //right
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && arr[i]<=arr[st.top()]) st.pop();
            if(st.size()) right[i] = st.top()-i;
            else right[i] = n-i;
            st.push(i);
        }
        long long sum = 0;
        for(int i=0;i<n;i++)
        {
           long long prod = (left[i]*right[i])%MOD;
            prod = (prod*arr[i])%MOD;
            sum = (sum + prod)%MOD;
        }
        return sum;
    }
};