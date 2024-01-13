class Solution {
public:
    int minSteps(string s, string t) {
//             l - 1
//             e - 3  -- 2
//             t - 1  -- 0
//             c - 1  -- 0
//             o - 1  
//             d - 1
//                 ////
//             p - 1 -- 1
//             r - 1 -- 1
//             a - 1 -- 1
//             c - 2 -- 1
//             t - 1 -- 0
//             i - 1 -- 1
//             e - 1 -- 0
                
        map<char,int> m1,m2;
        //
        for(int i=0;i<s.size();i++)
        {
            m1[s[i]]++;
            m2[t[i]]++;
        }
        ////
        for(auto it : m1)
        {
            if(m2[it.first])
            {
                m2[it.first] -= m1[it.first];
                m2[it.first] = max(m2[it.first] , 0);
            }
        }
        int ans = 0;
        for(auto it : m2)
        {
            ans += it.second;
        }
        return ans;
            
                
    }
};