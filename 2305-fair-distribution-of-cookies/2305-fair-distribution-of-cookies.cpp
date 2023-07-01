class Solution {
public:
    int ans = INT_MAX;
    int dfs(int idx,vector<int> &ck,vector<int> &cookies)
    {
        if(idx == cookies.size()) {
            int mx = *max_element(ck.begin() , ck.end());
            // return mx == 0 ? INT_MAX : mx;
            // cout<<mx<<" ";
            ans = min(ans , mx);
            return mx;
        }
        ///
        // int nottake = dfs(idx,ck,cookies);
        int take =0 ;
        for(int i=0;i<ck.size();i++)
        {
            ck[i] += cookies[idx];
            take = min(take , dfs(idx+1 , ck , cookies));
            ck[i] -= cookies[idx];
        }
        return take;
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> ck(k,0);
        ans = INT_MAX;
     dfs(0,ck,cookies);
        return ans;
    }
};