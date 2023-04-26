class Solution {
public:
    int addAll(string s)
    {
        // int nm = stoi(s);
        int smp = 0;
        for(auto i:s){
            smp += i-'0';
        }
        return smp;
    }
    int addDigits(int num) {
        string s = to_string(num);
        while(s.size()>1)
        {
            int smr = addAll(s);
            s = to_string(smr);
        }
        return stoi(s);
    }
};