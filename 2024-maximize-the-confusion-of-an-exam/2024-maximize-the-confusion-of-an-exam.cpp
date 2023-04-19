class Solution {
public:
    bool check(int len , string &anst , int k)
    {
        if(len == 0) return true;
        int max_val = 0;
        map<char,int> mp;
        for(int i=0;i<len;i++)
        {
            mp[anst[i]]++;
        }
        max_val = max(mp['T'] , mp['F']) + min({mp['T'] , mp['F'] , k}); 
        for(int i=len;i<anst.size();i++)
        {
            
            mp[anst[i-len]]--;
            mp[anst[i]]++;
            max_val =max(max_val, max(mp['T'] , mp['F']) + min({mp['T'] , mp['F'] , k})); 

        }
        return max_val >= len;
        
    }
    int maxConsecutiveAnswers(string anst, int k) {
        int i=0 , j = anst.size();
        int ans = -1;
        while(i<=j)
        {
            int mid = (i+j)>>1;
            if(check(mid , anst , k))
            {
            // cout<<mid<<" ";
                ans = i;
                i = mid + 1;
            }
            else{
                j = mid - 1;
            }
        }
        return j;
    }
};