class Solution {
public:
    long long putMarbles(vector<int>& w, int k) {
        vector<int> temp;
        int n = w.size();
        for(int i=1;i<n;i++)
        {
            temp.push_back(w[i]+w[i-1]);
        }
        sort(temp.begin(),temp.end());
        long long int mn=0,mx = 0;
        for(int i=0;i<k-1;i++)
        {
            mx += temp[n-i-2];
            mn += temp[i];
        }
        return mx - mn;
        
    }
};