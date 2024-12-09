class Solution {
public:
    
    bool searchFor(int start,int end,vector<int>& faulty)
    {
        int n = faulty.size();
        int l = 0 , h = n-1;
        while(l<=h)
        {
            int mid = (l+h)>>1;
            //
            if(start > faulty[mid])
            {
                l = mid + 1;
            }
            else if(end < faulty[mid])
            {
                h = mid - 1;
            }
            else{
                return true;
            }
        }
        return false;
    }
    
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> faulty;
        vector<bool> ans;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]%2 == nums[i-1]%2)
            {
                faulty.push_back(i);
            }
        }
        for(auto it : queries)
        {
            int x = it[0] , y = it[1];
            ans.push_back(!searchFor(x+1,y,faulty));
        }
        return ans; 
    }
};