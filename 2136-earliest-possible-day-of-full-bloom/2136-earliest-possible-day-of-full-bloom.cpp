class Solution {
public:
    static bool sortt(pair<int,int>& a,pair<int,int>& b)
    {
        if(a.second == b.second)
            return a.first < b.first;
        return a.second > b.second ;
    }
    int earliestFullBloom(vector<int>& pt, vector<int>& gt) {
        vector<pair<int,int>> v;
        int n = pt.size();
        for(int i=0;i<n;i++)
        {
            v.push_back({pt[i],gt[i]});
        }
        sort(v.begin(),v.end(),sortt);
        int ans = 0;
        int mx_time = 0;
        for(int i=0;i<n;i++)
        {
            // cout<<v[i].first<<" "<<v[i].second<<endl;
            ans += v[i].first;
            mx_time = max(mx_time,ans + v[i].second);
        }
        if(mx_time<ans)
        ans += v[n-1].second;
        else
            return mx_time;
        return ans;
       
    }
};