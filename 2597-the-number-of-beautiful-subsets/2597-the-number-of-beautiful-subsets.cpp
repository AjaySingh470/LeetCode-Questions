class Solution {
public:
    map<int,int> mp;
    int ans = 0;
    int dfs(int i,vector<pair<int,int>> num,int k,vector<int> &cnt)
    {
        if(i == num.size()) return 1;
        if(cnt[i]!=-1) return cnt[i];
        int nottake = dfs(i+1,num,k,cnt);
        int take = (1<<num[i].second) - 1;
        if(i+1<num.size() and num[i+1].first - num[i].first == k)
        {
            take *= dfs(i+2,num,k,cnt);
        }
        else{
            take *= dfs(i+1,num,k,cnt);
        }
        
        return cnt[i] = take + nottake;

    }
    int beautifulSubsets(vector<int>& nums, int k) {
        map<int,map<int,int>> freq;
        int ans = 1;
        for(auto it : nums)
        {
            freq[it%k][it]++;
        }
        for(auto it : freq)
        {
            int nm = it.first;
            // map<int,int> fp;
            vector<pair<int,int>> vt(it.second.begin() , it.second.end());
            //
            vector<int> v(vt.size(),-1);
            int tn = dfs(0,vt ,k,v);
            ans *= tn;
        }
        
        return ans-1;
    }
};