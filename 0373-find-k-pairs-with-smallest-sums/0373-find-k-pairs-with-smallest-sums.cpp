class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        set<pair<int,int>> st;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({nums1[0]+nums2[0],{0,0}});
        st.insert({0,0});
        int n=nums1.size() , m = nums2.size();
        while(k-- && !pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            ans.push_back({nums1[it.second.first] , nums2[it.second.second]});
            //
            int i = it.second.first , j = it.second.second;
            if(i+1<n and st.find({i+1,j}) == st.end())
            {
                pq.push({nums1[i+1] + nums2[j] , { i+1 , j }});
                st.insert({i+1,j});
            }
            if(j+1<m and st.find({i,j+1}) == st.end())
            {
                pq.push({nums1[i] + nums2[j+1] , {i,j+1}});
                st.insert({i,j+1});
            }
           
        }
        return ans;
    }
};