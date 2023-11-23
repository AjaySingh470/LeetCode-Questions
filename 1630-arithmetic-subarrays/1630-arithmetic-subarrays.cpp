class Solution {
public:
    bool check(vector<int> &nums,int l , int r)
    {
        bool flg = false;
        vector<int> t(nums.begin() + l , nums.begin() + r + 1);
        sort(t.begin() , t.end());
        if(t.size() == 1) return true;
        int diff = t[1] - t[0];
        for(int i=1;i<t.size()-1;i++)
        {
            if(diff != t[i+1] - t[i])
                return false;
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for(int i=0;i<l.size();i++)
        {
            ans.push_back(check(nums,l[i],r[i]));
        }
        return ans;
    }
};