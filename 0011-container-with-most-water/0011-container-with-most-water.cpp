#include<bits/stdc++.h>
class Solution {
public:
    int maxArea(vector<int>& v) {
        long long int mx = 0;
        long long int l = 0,r=v.size()-1;
        while(l<r)
        {
            long long int mn = min(v[l],v[r]);
            mx = max(mn * (r - l) ,mx);
            if(v[l]<v[r])
                l++;
            else if(v[l]>v[r])
                r--;
            else{
                l++;
                r--;
            }
        }
        return mx;
    }
};