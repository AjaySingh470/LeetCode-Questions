class Solution {
public:
    
    int calc(int nm)
    {
        if(nm%3 == 1)
        {
            return nm/3 + 1;
        }
        if(nm%3 == 2)
        {
            return nm/3 + 1;
        }
        return nm/3 ;
    }
    
    int minOperations(vector<int>& nums) {
        int ans = 0;
        map<int,int> mp;
        for(auto it : nums)
        {
            mp[it]++;
            ///
        }
        for(auto it : mp)
        {
            if(it.second == 1) return -1;
            int cnt = calc(it.second);
            ans += cnt;
        }
        return ans;
    }
};