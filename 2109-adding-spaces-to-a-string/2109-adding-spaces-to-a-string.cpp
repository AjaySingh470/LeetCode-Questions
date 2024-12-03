class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        int k = 0;
        for(int i=0;i<s.size();i++)
        {
            if(k<spaces.size() and i == spaces[k])
            {
                k++;
                ans += " ";
            }
                ans += s[i];
            
        }
        return ans;
    }
};