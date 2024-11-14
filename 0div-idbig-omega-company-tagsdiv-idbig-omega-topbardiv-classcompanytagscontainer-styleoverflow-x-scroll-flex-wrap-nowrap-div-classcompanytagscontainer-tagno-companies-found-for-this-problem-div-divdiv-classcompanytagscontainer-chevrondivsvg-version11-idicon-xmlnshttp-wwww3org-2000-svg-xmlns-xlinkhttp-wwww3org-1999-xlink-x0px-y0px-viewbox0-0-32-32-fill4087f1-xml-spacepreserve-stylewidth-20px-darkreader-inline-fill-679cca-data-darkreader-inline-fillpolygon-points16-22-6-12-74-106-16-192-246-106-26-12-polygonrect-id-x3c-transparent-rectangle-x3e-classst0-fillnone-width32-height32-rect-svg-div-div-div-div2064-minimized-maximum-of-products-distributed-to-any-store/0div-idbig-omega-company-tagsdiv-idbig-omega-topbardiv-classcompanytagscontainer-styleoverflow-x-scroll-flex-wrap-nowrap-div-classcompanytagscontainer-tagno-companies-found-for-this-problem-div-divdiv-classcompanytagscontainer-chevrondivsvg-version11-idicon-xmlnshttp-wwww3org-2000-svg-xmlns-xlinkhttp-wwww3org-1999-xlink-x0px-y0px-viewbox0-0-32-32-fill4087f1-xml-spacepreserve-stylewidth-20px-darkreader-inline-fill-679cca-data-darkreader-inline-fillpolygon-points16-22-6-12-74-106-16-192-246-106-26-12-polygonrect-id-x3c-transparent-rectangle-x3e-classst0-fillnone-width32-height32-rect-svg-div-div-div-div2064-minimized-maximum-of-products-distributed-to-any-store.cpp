class Solution {
public:
    
    int check(int mid,int n,vector<int> &temp)
    {
        for(auto it : temp)
        {
            n -= it/mid;
            
            if(it%mid)
            {
                n--;
            }
        }
        return n >= 0;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        // int sm = 0;
        // for(auto it : quantities)
        // {
        //     sm += it;
        // }
        // //
        
        int l = 1 , r = *max_element(quantities.begin(),quantities.end());
        while(l <= r)
        {
            int mid = (l+r)>>1;
            if(check(mid,n,quantities))
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
        
        
    }
};