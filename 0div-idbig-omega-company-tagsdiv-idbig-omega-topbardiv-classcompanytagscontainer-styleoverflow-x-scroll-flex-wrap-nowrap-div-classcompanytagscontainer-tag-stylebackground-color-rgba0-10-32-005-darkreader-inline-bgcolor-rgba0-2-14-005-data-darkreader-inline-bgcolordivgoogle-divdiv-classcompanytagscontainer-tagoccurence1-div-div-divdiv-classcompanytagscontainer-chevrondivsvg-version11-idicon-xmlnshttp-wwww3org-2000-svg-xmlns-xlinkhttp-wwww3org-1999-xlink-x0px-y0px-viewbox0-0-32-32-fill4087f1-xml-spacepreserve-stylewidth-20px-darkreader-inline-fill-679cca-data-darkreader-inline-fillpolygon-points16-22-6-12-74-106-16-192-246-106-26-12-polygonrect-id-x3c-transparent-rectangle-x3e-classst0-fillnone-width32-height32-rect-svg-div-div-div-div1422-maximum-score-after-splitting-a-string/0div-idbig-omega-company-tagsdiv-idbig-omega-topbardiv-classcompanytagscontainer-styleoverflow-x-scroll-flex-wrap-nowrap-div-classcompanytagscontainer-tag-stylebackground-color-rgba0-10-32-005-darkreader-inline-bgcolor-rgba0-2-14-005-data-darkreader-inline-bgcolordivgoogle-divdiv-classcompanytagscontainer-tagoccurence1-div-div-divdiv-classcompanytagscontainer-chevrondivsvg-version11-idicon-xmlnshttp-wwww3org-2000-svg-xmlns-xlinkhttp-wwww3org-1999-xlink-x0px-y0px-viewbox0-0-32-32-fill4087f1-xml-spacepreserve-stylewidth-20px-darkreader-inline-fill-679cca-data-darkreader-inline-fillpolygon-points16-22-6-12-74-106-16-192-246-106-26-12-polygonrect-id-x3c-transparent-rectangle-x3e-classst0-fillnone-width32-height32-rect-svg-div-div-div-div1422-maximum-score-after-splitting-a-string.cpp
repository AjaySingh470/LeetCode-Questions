class Solution {
public:
    int maxScore(string s) {
        int zr = 0 , on = 0;
        for(auto it : s) if(it == '1') on++;
        int ans = 0;
        for(int i=0;i<s.size()-1;i++)
        {
            if(s[i] == '0') zr++;
            else on--;
            ans = max(ans , zr + on);
        }
        return ans;
    }
};