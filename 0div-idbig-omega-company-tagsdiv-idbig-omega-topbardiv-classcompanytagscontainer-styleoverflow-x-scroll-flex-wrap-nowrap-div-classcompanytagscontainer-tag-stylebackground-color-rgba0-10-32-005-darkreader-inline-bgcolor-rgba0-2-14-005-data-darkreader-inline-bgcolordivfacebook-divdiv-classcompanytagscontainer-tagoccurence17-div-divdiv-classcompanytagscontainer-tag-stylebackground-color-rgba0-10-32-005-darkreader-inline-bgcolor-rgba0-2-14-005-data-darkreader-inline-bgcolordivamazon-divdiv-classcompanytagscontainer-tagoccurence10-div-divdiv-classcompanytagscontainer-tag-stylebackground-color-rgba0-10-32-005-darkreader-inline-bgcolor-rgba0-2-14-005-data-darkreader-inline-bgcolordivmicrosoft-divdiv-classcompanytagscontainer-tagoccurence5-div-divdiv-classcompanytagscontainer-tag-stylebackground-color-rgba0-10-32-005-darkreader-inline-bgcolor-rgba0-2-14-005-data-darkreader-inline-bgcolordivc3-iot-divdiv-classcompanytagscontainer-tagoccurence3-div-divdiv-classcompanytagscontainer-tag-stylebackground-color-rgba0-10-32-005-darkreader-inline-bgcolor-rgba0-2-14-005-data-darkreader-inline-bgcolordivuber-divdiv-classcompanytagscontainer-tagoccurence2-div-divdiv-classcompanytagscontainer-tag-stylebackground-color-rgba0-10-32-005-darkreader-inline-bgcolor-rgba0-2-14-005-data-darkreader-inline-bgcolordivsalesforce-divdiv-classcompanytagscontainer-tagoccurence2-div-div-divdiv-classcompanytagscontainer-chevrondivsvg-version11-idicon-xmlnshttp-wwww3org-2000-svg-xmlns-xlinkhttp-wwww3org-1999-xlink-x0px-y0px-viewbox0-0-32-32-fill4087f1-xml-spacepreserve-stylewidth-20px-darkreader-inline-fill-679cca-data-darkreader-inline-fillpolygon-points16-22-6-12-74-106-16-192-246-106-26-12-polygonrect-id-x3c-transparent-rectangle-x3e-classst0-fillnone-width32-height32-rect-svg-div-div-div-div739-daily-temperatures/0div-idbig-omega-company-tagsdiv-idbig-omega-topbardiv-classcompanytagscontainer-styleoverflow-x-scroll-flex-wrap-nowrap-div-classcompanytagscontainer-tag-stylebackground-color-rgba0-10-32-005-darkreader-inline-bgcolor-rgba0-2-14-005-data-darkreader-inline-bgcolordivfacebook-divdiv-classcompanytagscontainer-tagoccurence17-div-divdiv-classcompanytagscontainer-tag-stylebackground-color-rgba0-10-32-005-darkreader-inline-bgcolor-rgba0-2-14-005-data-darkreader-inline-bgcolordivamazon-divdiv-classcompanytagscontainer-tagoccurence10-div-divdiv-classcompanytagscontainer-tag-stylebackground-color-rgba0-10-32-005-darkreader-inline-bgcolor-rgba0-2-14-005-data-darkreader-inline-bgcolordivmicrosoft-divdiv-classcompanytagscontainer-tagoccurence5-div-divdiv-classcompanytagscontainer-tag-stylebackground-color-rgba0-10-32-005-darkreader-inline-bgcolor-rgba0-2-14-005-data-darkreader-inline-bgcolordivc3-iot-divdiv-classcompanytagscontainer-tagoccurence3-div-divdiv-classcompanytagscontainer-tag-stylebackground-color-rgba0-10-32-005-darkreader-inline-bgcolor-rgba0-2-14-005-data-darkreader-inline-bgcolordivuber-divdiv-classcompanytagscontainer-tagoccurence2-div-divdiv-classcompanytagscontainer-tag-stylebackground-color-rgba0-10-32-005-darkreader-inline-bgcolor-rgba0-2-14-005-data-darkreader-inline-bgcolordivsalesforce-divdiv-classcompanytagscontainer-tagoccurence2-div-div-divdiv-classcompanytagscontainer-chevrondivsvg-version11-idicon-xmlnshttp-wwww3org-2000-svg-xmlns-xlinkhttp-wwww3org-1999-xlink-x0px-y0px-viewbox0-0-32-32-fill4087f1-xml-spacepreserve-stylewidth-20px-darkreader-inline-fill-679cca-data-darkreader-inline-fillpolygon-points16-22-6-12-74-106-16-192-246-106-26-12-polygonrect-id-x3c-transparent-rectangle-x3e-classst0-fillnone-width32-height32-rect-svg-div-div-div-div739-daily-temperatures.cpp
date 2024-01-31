class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tmp) {
        int n = tmp.size();
        vector<int> ans(n,0);
        stack<pair<int,int>> st;
        st.push({tmp[0],0});
        for(int i=1;i<n;i++)
        {
            int nm = tmp[i];

                while(!st.empty() && st.top().first < nm)
                {
                    auto it = st.top();
                    st.pop();
                    int tnm = it.first;
                    int pos = it.second;
                    //
                    ans[pos] = i - pos;
                }
                st.push({nm,i});
            
        }
        return ans;
    }
};