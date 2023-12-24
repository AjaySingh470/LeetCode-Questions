class Solution {
public:
    
  const int mod = 1e9 + 7;
    
    int maximizeSquareArea(int m, int n, vector<int>& hf, vector<int>& vf) {
        unordered_map<int,int> h,v;
        hf.push_back(m);
        hf.insert(hf.begin() , 1);
        
        vf.push_back(n);
        vf.insert(vf.begin() , 1);
        
        for(int i=0;i<hf.size();i++)
        {
            for(int j=i+1;j<hf.size();j++)
                h[abs(hf[j] - hf[i])] = 1;
        }
        
        long long ans = -1;
        
        for(int i=0;i<vf.size();i++)
        {
            for(int j=i+1;j<vf.size();j++)
                if(h[abs(vf[i] - vf[j])])
                    ans = max(ans , (long long)abs(vf[i] - vf[j]));
        }
       
        if(ans == -1) return -1;
        return  (1LL * ans * ans) % 1000000007;
    }
};