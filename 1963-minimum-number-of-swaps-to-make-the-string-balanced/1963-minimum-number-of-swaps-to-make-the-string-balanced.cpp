class Solution {
public:
    int minSwaps(string s) {
        int o = 0 , c = 0;
        // ]]][[[
        // [][[]]
        //
        int ans = 0;
        int j = s.size()-1;
        while(j>=0)
        {
            if(s[j] == '[')
                break;
            j--;
        }
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == ']')
            {
                c++;
            }
            else 
                o++;
            if(c > o)
            {
                char ch = s[i];
                s[i] = s[j];
                s[j] = ch;
                ans++;
                o++;
                c--;
            }
        }
        return ans;
    }
};