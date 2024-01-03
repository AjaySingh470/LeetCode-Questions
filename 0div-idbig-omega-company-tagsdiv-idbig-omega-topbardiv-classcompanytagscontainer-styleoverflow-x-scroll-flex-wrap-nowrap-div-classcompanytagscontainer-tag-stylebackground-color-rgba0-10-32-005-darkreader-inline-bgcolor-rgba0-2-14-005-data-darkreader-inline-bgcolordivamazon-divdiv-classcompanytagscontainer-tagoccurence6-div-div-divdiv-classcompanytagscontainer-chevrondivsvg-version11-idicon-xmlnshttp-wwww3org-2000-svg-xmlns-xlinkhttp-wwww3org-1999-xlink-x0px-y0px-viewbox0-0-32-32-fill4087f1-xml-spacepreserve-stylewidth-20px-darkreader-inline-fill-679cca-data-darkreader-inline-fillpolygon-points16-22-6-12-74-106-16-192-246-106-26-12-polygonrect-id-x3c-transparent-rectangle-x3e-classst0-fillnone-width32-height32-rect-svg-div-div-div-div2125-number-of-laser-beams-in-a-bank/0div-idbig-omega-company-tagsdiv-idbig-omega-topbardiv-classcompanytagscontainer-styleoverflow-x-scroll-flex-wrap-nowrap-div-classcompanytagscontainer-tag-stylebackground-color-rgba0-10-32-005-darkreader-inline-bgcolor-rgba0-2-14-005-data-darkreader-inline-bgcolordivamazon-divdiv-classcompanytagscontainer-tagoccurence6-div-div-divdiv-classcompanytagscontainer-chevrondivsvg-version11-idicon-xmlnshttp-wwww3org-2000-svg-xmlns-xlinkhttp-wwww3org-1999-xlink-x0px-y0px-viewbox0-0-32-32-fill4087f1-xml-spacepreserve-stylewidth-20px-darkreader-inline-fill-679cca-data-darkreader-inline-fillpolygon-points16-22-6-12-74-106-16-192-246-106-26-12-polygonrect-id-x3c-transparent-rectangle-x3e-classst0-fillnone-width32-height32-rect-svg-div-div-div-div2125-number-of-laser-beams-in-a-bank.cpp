class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> v;
      int p = -1,c = 0;
      for(auto &it:bank)
      {
         int cnt = count(it.begin(),it.end(),'1');
          if(cnt > 0) 
          {
              if(p == -1)
              {
                  p = cnt;
              }
              else{
                c += cnt*p;
                p = cnt;
              }
          }
      }
      
      if(c == -1) return 0;
      return c;
    }
};