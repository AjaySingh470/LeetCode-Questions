class Solution {
public:
    

    
    long long continuousSubarrays(vector<int>& nums) {
        long long n = nums.size() , cnt = 0;
        multiset<int> st;
        int r = 0;
        for(int i=0;i<n;i++)
        {
             st.insert(nums[i]);
            while(st.size()>1 && abs(*st.begin() - *st.rbegin())>2)
            {
                st.erase(st.find(nums[r++]));
            }
            cnt += i - r + 1;
            
        }
        return cnt;
        // return dfs(0,nums,st);
    }
};