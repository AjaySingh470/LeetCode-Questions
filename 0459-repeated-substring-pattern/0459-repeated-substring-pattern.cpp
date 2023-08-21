class Solution {
public:
    int check(string &s,string &tmp)
    {
      int cnt = 0;
      int n = s.size();
      int m = tmp.size();
      for(int i=0;i<n;i+=m)
      {
        string t = s.substr(i,m);
        if(t!=tmp)
          return -1;
        cnt++;
      }
      return cnt;
    }
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
      for(int i=1;i<=n/2;i++)
      {
        string tmp = s.substr(0,i);
        int cnt = check(s,tmp);
        if(cnt*tmp.size() == n) return true;
      }
      return false;
    }
};