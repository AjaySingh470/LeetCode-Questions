class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;
        int n = neededTime.size();
        for(int i=0;i<n-1;i++)
        {
            if(colors[i] == colors[i+1])
            {
                
                    int tsm = neededTime[i] ,mxval = neededTime[i];
                while(i<n-1 && colors[i] == colors[i+1] )
                {
                    // cst.push_back(neededTime[i]);
                    i++;
                    tsm += neededTime[i];
                    mxval = max(mxval , neededTime[i]);
                }
                
                tsm -= mxval;
            ans += tsm;
            }
        }
        return ans;
    }
};