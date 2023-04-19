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
    
    int maxSizedWindowInString(string nums , int k , char ch)
    {
        int i = 0, j = 0;
      int zeroCount = 0;
        int ans = 0;
      for(int s = 0;s<nums.size();s++)
      {
          if(nums[s] == ch) zeroCount++;
          while(zeroCount > k)
          {
            if(nums[i] ==ch) zeroCount--;
            i++;
          }
        ans = max(ans , s - i + 1);
      }
      return ans;
    }
    
    int maxConsecutiveAnswers(string nums, int k) {
      return max(maxSizedWindowInString(nums,k,'T') , maxSizedWindowInString(nums,k,'F'));
    }
};



