class Solution {
 
private : 
  static bool cmp(vector<int> &a,vector<int> &b)
  {
    return a[1] < b[1] || a[1] == b[1]  && a[0]<b[0];
  }
  
public:

    int findLongestChain(vector<vector<int>>& p) {
        sort(p.begin(),p.end(),cmp);
        int n = p.size();
        vector<int> dp(n,1);
        //
      int cnt = 0;
      int mx = p[0][1];
        for(int i=0;i<n;i++)
        {
          if(i==0 || mx < p[i][0]  )
          {
            mx = p[i][1];
            cnt++;
          }
        }
      return cnt;
        
    }
};