class Solution {
public:
    string convertToTitle(int c) {
        string ans = "";
        c--;
        while(c >= 0)
        {
            int rem = c%26;
            c /= 26;
            ans += (char)('A' + rem);
            c--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};