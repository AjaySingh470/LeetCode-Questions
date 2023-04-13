class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int it = 0, j =0;
        int n = pushed.size();
        for(int i=0;i<n;i++)
        {
          st.push(pushed[i]);
          while(j<n and !st.empty() and popped[j] == st.top())
          {
            
            st.pop();
            j++;
          }
        
        }
      
    
      if(st.empty()) return true;
      return false;
    }
};