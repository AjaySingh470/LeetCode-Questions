class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size() , m = s.size();
        int i=0,j=0;
        int cnt = 0;
        sort(g.begin(),g.end());
        sort(s.begin() , s.end());
        while(i<n && j<m)
        {
            while(j<m && g[i] > s[j]) j++;

            if(j<m && g[i] <= s[j]){ 
                cnt++;
                j++;
                i++;
            }
    
        }
        return cnt;
        
    }
};