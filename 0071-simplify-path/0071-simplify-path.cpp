class Solution {
public:
    string simplifyPath(string s) {
        bool flg = false;
        vector<string> st;
      int n = s.size();
      string ans ;
        for(int i=0;i<s.size();)
        {
          if(s[i] == '/')
             {
               while(i<n and s[i] == '/')
               {
                 i++;
               }
          
            }
            else{
              string tmp ;
              while(i<n and s[i]!='/')
              {
                tmp += s[i];
                i++;
              }
              
              if(tmp == "..")
              {
                if(!st.empty()) st.pop_back();
              }
              else if(tmp == ".")
              {
                continue;
              }
              else {
                st.push_back(tmp);
                // 
              }
            }
        }
      for(auto i:st){
        ans += "/" + i;
      }
      if(ans == "") return "/";
      
      return ans;
    }
};