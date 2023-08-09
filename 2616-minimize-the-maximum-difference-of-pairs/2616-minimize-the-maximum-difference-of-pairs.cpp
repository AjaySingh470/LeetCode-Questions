class Solution {
public:
    
    bool isValid(int mid,int p,vector<int> &v)
    {
        int cnt = 0,i=0;
        while(i<v.size()-1)
        {
            if(v[i+1]-v[i]<=mid)
            {
                cnt++;
                i+=2;
            }
            else{
                i++;
            }
        }
        if(cnt >= p) return true;
        return false;
    }
    
    
    int minimizeMax(vector<int>& nums, int p) {
        int l = 0 ,r = 1e9;
        sort(nums.begin(),nums.end());
        if(p == 0) return 0;
        while(l<r)
        {
            int mid = l + (r-l)/2;
            if(isValid(mid,p,nums))
            {
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        return l;
    }
};