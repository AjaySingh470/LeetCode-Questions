class Solution {
public:
    int solve(int idx,int prev,int n,int sz,vector<int> &nums)
    {
        return 0;
    }
    int numTeams(vector<int>& rat) {
        int ans = 0;
        int n = rat.size();
        for(int i=0;i<n;i++)
        {
            int grt[2] = {0} , les[2] = {0};
            for(int j=0;j<n;j++)
            {
                if(rat[i] < rat[j]) les[i>j]++;
                if(rat[i] > rat[j]) grt[i>j]++;
            }
            ans += les[0] * grt[1] + grt[0] * les[1];
        }
        return ans;
        
    }
};