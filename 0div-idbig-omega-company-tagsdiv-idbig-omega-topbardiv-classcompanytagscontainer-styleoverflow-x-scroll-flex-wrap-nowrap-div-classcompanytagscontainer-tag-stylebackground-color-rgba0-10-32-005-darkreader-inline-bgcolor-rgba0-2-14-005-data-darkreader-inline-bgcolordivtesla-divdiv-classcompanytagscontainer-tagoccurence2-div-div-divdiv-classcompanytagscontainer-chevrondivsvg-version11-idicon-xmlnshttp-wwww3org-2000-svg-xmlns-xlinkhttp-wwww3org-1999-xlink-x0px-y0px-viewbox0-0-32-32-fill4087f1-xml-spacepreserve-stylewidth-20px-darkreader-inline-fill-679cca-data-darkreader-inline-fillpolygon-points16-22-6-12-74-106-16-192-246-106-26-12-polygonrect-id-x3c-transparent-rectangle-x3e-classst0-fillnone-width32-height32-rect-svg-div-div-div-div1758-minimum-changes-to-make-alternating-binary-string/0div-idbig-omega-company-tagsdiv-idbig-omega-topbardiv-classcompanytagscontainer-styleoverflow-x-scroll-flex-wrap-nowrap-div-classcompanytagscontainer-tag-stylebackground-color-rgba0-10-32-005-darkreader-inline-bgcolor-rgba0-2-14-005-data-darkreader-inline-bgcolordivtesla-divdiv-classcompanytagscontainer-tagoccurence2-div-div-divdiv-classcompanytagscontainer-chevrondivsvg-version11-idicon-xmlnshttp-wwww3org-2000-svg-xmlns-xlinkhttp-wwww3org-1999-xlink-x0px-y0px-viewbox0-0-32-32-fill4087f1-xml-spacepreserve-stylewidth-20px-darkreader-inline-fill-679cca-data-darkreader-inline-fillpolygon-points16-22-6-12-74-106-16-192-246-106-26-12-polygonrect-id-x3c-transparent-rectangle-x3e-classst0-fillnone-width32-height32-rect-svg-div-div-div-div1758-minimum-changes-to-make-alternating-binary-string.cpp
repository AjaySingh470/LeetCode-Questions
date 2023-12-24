class Solution {
public:
    int minOperations(string s) {
        int s0 = 0 , s1 = 0;
        for(int i=0;i<s.size();i++)
        {
            if(i%2)
            {
                s0 += (s[i] == '1');
            }
            else 
                s0 += (s[i] == '0');
        }
        for(int i=0;i<s.size();i++)
        {
            if(i%2 == 0)
            {
                s1 += (s[i] == '1');
            }
            else 
                s1 += (s[i] == '0');
        }
        return min(s0 , s1);
    }
};