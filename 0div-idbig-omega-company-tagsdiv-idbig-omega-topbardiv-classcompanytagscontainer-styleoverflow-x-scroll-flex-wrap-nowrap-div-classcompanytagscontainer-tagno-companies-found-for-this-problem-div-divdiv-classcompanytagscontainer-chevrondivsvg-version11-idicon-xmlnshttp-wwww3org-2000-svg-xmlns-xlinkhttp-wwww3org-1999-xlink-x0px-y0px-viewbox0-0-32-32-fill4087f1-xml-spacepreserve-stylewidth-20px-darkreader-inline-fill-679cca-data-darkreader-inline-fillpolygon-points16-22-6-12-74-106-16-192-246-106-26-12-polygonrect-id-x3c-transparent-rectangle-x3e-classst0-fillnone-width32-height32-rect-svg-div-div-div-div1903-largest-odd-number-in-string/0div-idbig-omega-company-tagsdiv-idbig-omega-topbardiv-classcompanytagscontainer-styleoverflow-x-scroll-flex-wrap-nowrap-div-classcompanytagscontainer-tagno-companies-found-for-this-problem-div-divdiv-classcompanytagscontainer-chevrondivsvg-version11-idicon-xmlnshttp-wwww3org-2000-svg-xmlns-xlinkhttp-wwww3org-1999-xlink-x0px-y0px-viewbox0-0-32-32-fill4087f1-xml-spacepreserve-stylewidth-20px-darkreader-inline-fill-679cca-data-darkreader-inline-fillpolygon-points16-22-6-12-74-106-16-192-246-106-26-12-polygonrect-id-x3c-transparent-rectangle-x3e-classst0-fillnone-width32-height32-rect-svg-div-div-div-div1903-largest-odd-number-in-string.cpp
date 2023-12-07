class Solution {
public:
    string largestOddNumber(string num) {
        string ans="";
        int n = num.length();
        int pos = -1;
        for(int i=n-1;i>=0;i--)
        {
            int temp = num[i] - '0';
            if(temp%2==1)
            {
                pos = i;
                break;
            }
        }
        if(pos == -1)
        {
            return "";
        }
        ans = num.substr(0,pos+1);
        return ans;
    }
};