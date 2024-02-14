class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos,neg;
        for(auto it : nums)
        {
            if(it < 0) neg.push_back(it);
            else pos.push_back(it);
        }
        vector<int> ans;
        for(int i=0;i<neg.size();i++)
        {
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
        }
        return ans;
    }
};