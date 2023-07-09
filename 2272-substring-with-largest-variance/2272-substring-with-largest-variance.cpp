class Solution {
public:
 
    
    int largestVariance(string s) {
       int ans = 0;
        vector<int> freq(26,0);
        for(auto it : s)
        {
            freq[it-'a']++;
        }
        for(char c1='a';c1<='z';c1++)
        {
            for(char c2='a';c2<='z';c2++)
            {
                if(c1 == c2 || freq[c1-'a'] == 0 || freq[c2-'a']==0)
                    continue;
                for(int r=0;r<2;r++)
                {
                    int cnt1 = 0 ,cnt2 = 0;
                    for(auto &ch : s)
                    {
                        if(ch == c1) cnt1++;
                        if(ch == c2) cnt2++;
                        if(cnt1<cnt2)
                        {
                            cnt1 = cnt2 = 0;
                        }
                        if(cnt1 > 0 and cnt2 > 0)
                        {
                            ans = max(ans , cnt1 - cnt2);
                        }
                    }
                reverse(s.begin(),s.end());
                }
            }
        }
        return ans;
    }
};