class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();int sum =0;
        vector<pair<int,int>> vt;
        for(int i=0;i<n;i++)
        {
            vt.push_back({ratings[i],i});
        }
        sort(vt.begin(),vt.end());
        vector<int> candy(n,0);
        for(int ind=0;ind<n;ind++)
        {
            int can = 1;
            int i = vt[ind].second;
            if(i>0 && ratings[i]>ratings[i-1])
            {
                can = max(candy[i-1] + 1, can );
            }
            if(i<n-1 && ratings[i]>ratings[i+1])
            {
                can = max(candy[i+1] + 1, can );
            }
            candy[i] = can;
            sum += can;
        }
        
        
        return sum;
    }
};