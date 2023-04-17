class Solution {
public:
  void recur(int i,int n,int k,vector<int> &tmp,vector<vector<int>> &ans)
  {
    if(tmp.size() == k) {
      ans.push_back(tmp);
      return;
    }
    if(i>n) return;
    tmp.push_back(i);
    recur(i+1,n,k,tmp,ans);
    tmp.pop_back();
    recur(i+1,n,k,tmp,ans);
  }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
      vector<int> tmp;
        recur(1,n,k,tmp,ans);
      return ans;
    }
};