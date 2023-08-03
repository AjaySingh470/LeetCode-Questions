class Solution {
  
public:
    vector<string> v = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void dfs(int i,int n,string tmp,string digits,vector<string> &ans)
    {
      if(i == n ){
        if(!tmp.empty());
        ans.push_back(tmp);
        return;
      }
      int itr = digits[i] - '0';
      for(auto it:v[itr])
      {
        tmp += it;
        dfs(i+1,n,tmp,digits,ans);
        tmp.pop_back();
      }
        // cout<<tmp<<" ";
    }
  
    vector<string> letterCombinations(string digits) {
      vector<string> ans;
      string tmp = "";
      if(digits.empty()) return {};
        dfs(0,digits.size(),tmp,digits,ans);
      return ans;
    }
};