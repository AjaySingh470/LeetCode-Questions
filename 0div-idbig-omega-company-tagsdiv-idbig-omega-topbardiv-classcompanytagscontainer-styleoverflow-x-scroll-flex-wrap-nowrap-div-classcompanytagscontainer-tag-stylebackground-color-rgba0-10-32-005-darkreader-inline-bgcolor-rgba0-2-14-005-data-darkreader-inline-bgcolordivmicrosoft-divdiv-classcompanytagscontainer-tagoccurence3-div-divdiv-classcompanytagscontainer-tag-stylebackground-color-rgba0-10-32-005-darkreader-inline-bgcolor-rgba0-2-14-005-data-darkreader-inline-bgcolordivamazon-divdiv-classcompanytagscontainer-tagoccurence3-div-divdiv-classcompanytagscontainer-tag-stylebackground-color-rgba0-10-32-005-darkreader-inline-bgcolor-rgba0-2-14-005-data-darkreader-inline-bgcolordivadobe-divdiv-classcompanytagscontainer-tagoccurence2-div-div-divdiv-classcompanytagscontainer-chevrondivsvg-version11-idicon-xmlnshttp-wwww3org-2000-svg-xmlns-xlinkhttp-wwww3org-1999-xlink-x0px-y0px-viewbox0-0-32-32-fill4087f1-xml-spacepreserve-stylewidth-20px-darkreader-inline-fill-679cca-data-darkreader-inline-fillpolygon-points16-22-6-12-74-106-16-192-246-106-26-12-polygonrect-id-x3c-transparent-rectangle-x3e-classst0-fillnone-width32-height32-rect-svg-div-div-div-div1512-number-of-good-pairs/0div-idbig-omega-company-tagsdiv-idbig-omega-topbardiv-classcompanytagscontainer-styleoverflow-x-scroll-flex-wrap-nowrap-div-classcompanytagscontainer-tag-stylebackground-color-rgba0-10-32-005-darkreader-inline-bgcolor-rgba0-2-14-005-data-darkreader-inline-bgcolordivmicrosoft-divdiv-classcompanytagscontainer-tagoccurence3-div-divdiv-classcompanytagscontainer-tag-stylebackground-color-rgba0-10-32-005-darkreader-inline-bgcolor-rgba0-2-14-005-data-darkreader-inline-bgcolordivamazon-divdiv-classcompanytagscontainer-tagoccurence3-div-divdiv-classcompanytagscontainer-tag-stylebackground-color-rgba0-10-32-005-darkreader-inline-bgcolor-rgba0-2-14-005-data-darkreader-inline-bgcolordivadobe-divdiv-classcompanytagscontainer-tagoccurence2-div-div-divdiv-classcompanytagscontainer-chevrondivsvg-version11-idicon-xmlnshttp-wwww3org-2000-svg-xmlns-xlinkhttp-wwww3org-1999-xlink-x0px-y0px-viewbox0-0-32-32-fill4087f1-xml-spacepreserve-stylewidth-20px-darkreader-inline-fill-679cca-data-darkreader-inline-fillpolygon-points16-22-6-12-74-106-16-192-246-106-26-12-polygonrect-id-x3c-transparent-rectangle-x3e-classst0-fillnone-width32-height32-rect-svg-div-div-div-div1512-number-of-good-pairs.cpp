class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> m;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            m[nums[i]]++;
        }
        int sum=0;
         for(auto x:m)
        {
            if(x.second>1)
            {
                sum+=(x.second*(x.second-1))/2;
            }
        }
        return sum;
    }
};