class Solution {
public:
    vector<int> fact,digits;
    void clc()
    {
        fact.push_back(1);
        int nm = 1;
        for(int i=1;i<=9;i++)
        {
            nm*=i;
            fact.push_back(nm);
        }
    }
    void recur(string &ans,int n,int k)
    {
        if(n==1)
        {
            ans += to_string(digits.back());
            return;
        }
            int ft = fact[n-1];
            int idx = k/ft;
            if(k%ft == 0) idx--;
            ans += to_string(digits[idx]);
            digits.erase(digits.begin()+idx);
            k -= ft*idx;
            recur(ans,n-1,k);
        
    }
    string getPermutation(int n, int k) {
        clc();
        for(int i=1;i<=n;i++)
            digits.push_back(i);
        ///
        string ans = "";
        recur(ans,n,k);
        return ans;
        
    }
};