class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        map<char,int> m1;
        for(auto it : chars) m1[it]++;
        int ans = 0;
        for(auto it : words)
        {
            map<char,int> m2 = m1;
            bool flg = false;
            for(auto i : it)
            {
                if(m2[i] <=0) {
                    flg = true;
                    break;
                }
                m2[i]--;
            }
            if(!flg)
                ans += it.size();
        }
        return ans;
    }
};