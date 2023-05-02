class Solution {
public:
    int arraySign(vector<int>& nums) {
        long long mup = 1ll;
        for(auto it:nums) {
            if(it < 0) mup *= -1;
            if(it > 0) mup *= 1;
            if(it == 0) return 0;
        }
        if(mup == 0) return 0;
        else if(mup < 0) return -1;
        return 1;
    }
};