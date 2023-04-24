class Solution {
public:
    int lastStoneWeight(vector<int>& st) {
        sort(st.begin(),st.end());
        int n = st.size();
        for(int i=n-1;i>0;i--)
        {
        
                int mx = max(st[i],st[i-1]);
                int mn = min(st[i],st[i-1]);
                st[i-1] = mx - mn;
                st.erase(st.begin()+i);
                sort(st.begin(),st.end());
        }
        if(st.empty())
            return 0;
        return st[0];
    }
};