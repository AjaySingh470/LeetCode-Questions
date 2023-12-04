class Solution {
public:
    string largestGoodInteger(string num) {
        string s = "";
        for(int i=0;i<num.size()-2;i++)
        {
            if(num[i] == num[i+1] && num[i+1] == num[i+2])
            {
                string tp = "";
                tp += num[i];
                tp +=   num[i+1];
                tp += num[i+2];
                s = max(tp , s);
            }
        }
        return s;
    }
};