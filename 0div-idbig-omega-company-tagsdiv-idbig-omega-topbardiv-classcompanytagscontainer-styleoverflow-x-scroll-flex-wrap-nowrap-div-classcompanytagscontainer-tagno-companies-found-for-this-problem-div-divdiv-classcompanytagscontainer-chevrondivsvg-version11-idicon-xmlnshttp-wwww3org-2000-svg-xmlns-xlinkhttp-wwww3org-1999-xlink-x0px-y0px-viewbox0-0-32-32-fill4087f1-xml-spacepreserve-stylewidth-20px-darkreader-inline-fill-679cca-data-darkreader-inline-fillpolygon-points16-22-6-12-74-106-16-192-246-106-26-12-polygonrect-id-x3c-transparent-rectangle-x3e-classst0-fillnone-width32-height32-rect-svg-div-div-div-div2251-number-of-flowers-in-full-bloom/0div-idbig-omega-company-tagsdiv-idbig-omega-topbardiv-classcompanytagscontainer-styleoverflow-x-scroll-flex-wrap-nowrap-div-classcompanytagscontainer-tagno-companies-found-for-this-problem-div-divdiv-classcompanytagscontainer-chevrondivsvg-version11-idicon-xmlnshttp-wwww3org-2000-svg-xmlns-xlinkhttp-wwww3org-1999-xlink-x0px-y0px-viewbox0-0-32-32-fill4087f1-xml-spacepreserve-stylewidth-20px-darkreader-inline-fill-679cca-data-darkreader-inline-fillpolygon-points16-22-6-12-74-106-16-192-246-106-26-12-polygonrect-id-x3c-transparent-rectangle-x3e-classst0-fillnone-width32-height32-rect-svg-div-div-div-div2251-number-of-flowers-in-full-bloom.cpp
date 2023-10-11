class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> start , end;
        for(auto it : flowers)
        {
            start.push_back(it[0]);
            end.push_back(it[1]);
        }
                sort(start.begin(),start.end());
        sort(end.begin() , end.end());
        /////
        vector<int> ans;
        for(auto it : people)
        {
            int i = upper_bound(start.begin() , start.end() , it) - start.begin();
            int j = lower_bound(end.begin() , end.end() , it)-end.begin();
            ////
            ans.push_back(abs(j-i));
        }
        return ans;
    }
};