class Solution {
public:
    // set<int> st;
    bool prime[1000001];
    void SieveOfEratosthenes(int n)
{
   
    memset(prime, true, sizeof(prime));
  
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
  
    // for (int p = 2; p <= n; p++)
        // if (prime[p])
            // st.insert(p);
}
    vector<vector<int>> findPrimePairs(int n) {
        SieveOfEratosthenes(n);
        vector<vector<int>> v;
        
        for(int i=2;i<=n/2;i++)
        {
            if(prime[i] && prime[n-i])
            {
                v.push_back({i,n-i});
            }
        }
        return v;
    }
};